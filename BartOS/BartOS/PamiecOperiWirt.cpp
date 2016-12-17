#include "stdafx.h"
#include "PamiecOperiWirt.h"



PamiecOperiWirt::PamiecOperiWirt()
{
	OM_Next_Frame_Victim = 0;
	IndexforWM = 0;
	for (int i = 0; i < OMsize; i++)
	{
		OM[i] = '-';
	}

}

PamiecOperiWirt::~PamiecOperiWirt()
{

}

int PamiecOperiWirt::WhichPage(short int x)
{
	return (x / 16);
}

int PamiecOperiWirt::WhatOffset(short int x)
{
	return (x % 16);
}


void PamiecOperiWirt::DeleteProcess(PCB *blok)
{
	int i = 0;
	VMiter = VM.begin();
	while (i != blok->Process_ID)
	{
		VMiter++; i++;
	}
	VM.erase(VMiter);
	VM.insert(VMiter, new page);
	VM[i]->abandon = true;
	/////////////////////////////////////////////////////////////////
	for (int j = 0; j < blok->sopic / framesize + 1; j++)
	{
		if (blok->pages[j].Valid == true)
		{
			for (int k = 0; k < framesize; k++)
				OM[(blok->pages[j].cell) * 16 + k] = '-';
		}
	}
}
//Dodalem Ci funkcje hehe XD
// Wez ja wypelnij jakos ladnie
stronice PamiecOperiWirt::MemRequest()
{




	int ErrCode;
	if (true)//Jest wolne miejsce dla alokacji pliku w 
		throw ErrCode = 1; //podmien true na wypelniona stronice
	else //Nie ma miejsca na plik
		throw ErrCode = 0;

}


void PamiecOperiWirt::Insert_To_Virtual_Memory(PCB *blok, char *disc_tab,int sopic)
{
	//cout << disc_tab << endl;
	//int j = 0;
	blok->sopic = sopic;
	if (sopic == -1) { blok->Process_State = PCB::Proc_New; return; }
	int number_of_pages = WhichPage(blok->sopic) + 1;
	int pom = 0;
	page *kod = new page[number_of_pages];
	
	for (int i = 0; i < number_of_pages; i++) {
		
		
		for (int j = 0; j < framesize; j++) {
			if (pom < sopic) { 
				kod[i].tab[j] = disc_tab[pom]; pom++; }
			else {
				VM.push_back(kod);return;
			}
		}

	}


	/*for (int i = 0; i < number_of_pages-1; i++)
	{
		
		for (int j=0; j < framesize; j++)
		{
			kod[i].tab[j] = disc_tab[pom];
			pom++;
		}
		if (i + 1 == number_of_pages)//wejdz tu jesli ostatnia strona, przepisz i wyjdz z funkcji
		{
			for (int k = 0; k < WhatOffset(blok->sopic); k++)
			{
				kod[i].tab[k] = disc_tab[pom];
				pom++;
			}
		}
		
	}
	
	VM.push_back(kod);*/
}

char PamiecOperiWirt::Get_Char_From_OM(PCB *blok, int LogicAdr)
{
	int page = WhichPage(LogicAdr);
	int offset = WhatOffset(LogicAdr);


	if (blok->pages[page].Valid == true)      //wejd� tu je�li ramka JEST w PAM OP
	{
		return OM[blok->pages[page].cell * 16 + offset];
	}
	else      //wejd� tu je�li ramki NIE MA w PAM OP
	{
		Get_Page_From_WM(blok, page);//pobierz strone z pam wirt do operacyjnej, jak to zrobisz, to zwroc char USTAW ROWNIEZ BIT NA VALID
		Get_Char_From_OM(blok, LogicAdr);//wywo�aj sie na nowo �eby tym razem zwr�ci� chara
	}
}

void PamiecOperiWirt::Get_Page_From_WM(PCB *blok, int page)
{
	short FrameNr = Get_Free_Frame_Number();//szukaj indeksu wolnej ramki, jak nie ma to wg FIFO

	for (int j = 0; j < framesize; j++)
	{
		OM[(FrameNr * framesize) + j] = VM[blok->Process_ID-1][page].tab[j];
	}

	int ID_of_a_process_which_frame_is_being_overriden = Return_ID_of_a_Process_using_this_frame(FrameNr);
	int Nr_of_the_page = Return_nr_of_a_page_using_this_frame(FrameNr);

	blok->pages[page].Valid = true;
	blok->pages[page].cell = FrameNr;
	FIFO.push(FrameNr);
	if (ID_of_a_process_which_frame_is_being_overriden != -1 && Nr_of_the_page != -1)
		Update_Overide(ID_of_a_process_which_frame_is_being_overriden, Nr_of_the_page);//w pcb procesu, kt�ry by� w ramce przed jej nadpisaniem, ustaw pages list, zeby juz nie wskazywa na ta ramke 
}

int PamiecOperiWirt::Get_Free_Frame_Number()
{
	for (int i = 0; i < 128; i = i + 16)
	{
		if (OM[i] == '-')
		{
			return i / 16;//zwroc index pierwszej pustej ramki je�li puste w og�le s�
		}
	}//bo jak ich nie ma to realizuj wyrzucanie z OM wg FIFO = zwr�c index ramki kt�ra by�a najd�u�ej
	int x = FIFO.front();
	FIFO.pop();
	return x;

}



void PamiecOperiWirt::PrintOM()
{
	int counter = 0;
	cout << "AKTUALNY STAN PAMIECI OPERACYJNEJ" << endl;
	for (int i = 0; i < OMsize / framesize; i++)
	{
		cout << "Frame nr " << i + 1 << "  ";
		for (int j = 0; j < framesize; j++)
		{
			cout << OM[counter] << " ";
			counter++;
		}
		cout << endl;
	}
}

void PamiecOperiWirt::PrintVM()
{
	//vector<PCB*>AllProcc = *AllProc;
	if (VM.capacity() == 0)
	{
		cout << "PAMIEC WIRTUALNA JEST PUSTA" << endl;
		return;
	}

	//cout << VM.capacity() << endl;
	//cout << VM.size() << endl;
	//cout << AllProc->capacity() << endl;
	//cout << AllProc->size() << endl;

	int capacity = VM.capacity();
	int cnt = 1;
	for (vector<PCB*>::iterator it = AllProc.begin(); it != AllProc.end(); it++)//skacz po zawartosci VM
	{
		
//		if (VM[i]->abandon == true)
	//		continue;
		//else
		if ((*it)->Process_ID == 0)
		{
			continue;
		}
		{
			cout << "PAMIEC WIRTUALNA PROCESU NR " <<(*it)->Process_ID << endl;
			for (int i = 0; i < (*it)->sopic/16+1;i++)//przeskocz po wszystkich stronach procesu np dla sopic r�wnego 40 mamy 3
			{
				VM[cnt-1][i].PrintPage();
				//VM[i][j].PrintPage();
			}
			cout << endl;
			cnt++;
		}
	}


}

void PamiecOperiWirt::Update_Overide(int PCBnumber, int Pagenr)
{
	//vector <PCB*>::iterator iter;
	iter[PCBnumber]->pages[Pagenr].Valid = false;
	//AllPCBs[PCBnumber]->pages[Pagenr].Valid = false;


}

void PamiecOperiWirt::Set_PCB_Vector(vector<PCB*> &AllProc)
{
	this->AllProc = AllProc;
}

int PamiecOperiWirt::Return_ID_of_a_Process_using_this_frame(int FrameNr)
{
	int cnt = 1;
	for (auto it = AllProc.begin(); it != AllProc.end(); it++)//skacz po zawartosci VM
	{
		if (cnt == 1)it++;//przeskocz
		for (int j = 0; j < 16; j++)//skacz po tablicy stronic ktora ma 16 indeksow
		{
			if ((*it)->pages[j].cell == FrameNr)
			{
				return cnt;//search succeeded
			}
			
		}
		cnt++;

	}
	return -1;//search failed
}

int PamiecOperiWirt::Return_nr_of_a_page_using_this_frame(int FrameNr)
{
	//iter = AllProc.begin();
	//int cap = AllProc.capacity();
	//for (int i = 0; i < cap; i++)
	//{
	//	for (int j = 0; j < iter[i]->sopic / 16 + 1; j++)//przeskocz po wszystkich stronach procesu np dla sopic r�wnego 40 mamy 3
	//	{
	//		if (iter[i]->pages[j].cell == FrameNr)
	//		{
	//			return j;//search succeeded
	//		}
	//	}

	//}
	//return -1;//search failed TO JEST STARY KOD, MOZLIWE ZE TEZ DZIALA

	int cnt = 1;
	for (auto it = AllProc.begin(); it != AllProc.end(); it++)//skacz po zawartosci VM
	{
		if (cnt == 1)it++;//przeskocz
		for (int j = 0; j < 16; j++)//skacz po tablicy stronic ktora ma 16 indeksow
		{
			if ((*it)->pages[j].cell == FrameNr)
			{
				return j;//search succeeded
			}

		}
		cnt++;

	}
	return -1;//search failed
}