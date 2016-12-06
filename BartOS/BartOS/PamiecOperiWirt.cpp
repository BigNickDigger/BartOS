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
		VM.insert(VMiter,new page);
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


void PamiecOperiWirt::Insert_To_Virtual_Memory(PCB *blok)
{
	//laduj do VM[processID] tablice reprezentujaca kod programu

}

char PamiecOperiWirt::Get_Char_From_OM(PCB *blok, int LogicAdr)
{
	int page = WhichPage(LogicAdr);
	int offset = WhatOffset(LogicAdr);


	if (blok->pages[page].Valid == true)      //wejdŸ tu jeœli ramka JEST w PAM OP
	{
		return OM[blok->pages[page].cell * 16 + offset];
	}
	else      //wejdŸ tu jeœli ramki NIE MA w PAM OP
	{
		Get_Page_From_WM(blok, page);//pobierz strone z pam wirt do operacyjnej, jak to zrobisz, to zwroc char USTAW ROWNIEZ BIT NA VALID
		Get_Char_From_OM(blok, LogicAdr);//wywo³aj sie na nowo ¿eby tym razem zwróciæ chara
	}
}

void PamiecOperiWirt::Get_Page_From_WM(PCB *blok, int page)
{
	short FrameNr = Get_Free_Frame_Number();//szukaj indeksu wolnej ramki, jak nie ma to wg FIFO

	for (int i = 0; i < blok->sopic / 16 + 1; i++)
	{
		for (int j = 0; j < framesize ; j++)
		{
			OM[(FrameNr * framesize) + j] = VM[blok->Process_ID][page].tab[j];
		}
	}

	int ID_of_a_process_which_frame_is_being_overriden = Return_ID_of_a_Process_using_this_frame(FrameNr);
	int Nr_of_the_page = Return_nr_of_a_page_using_this_frame(FrameNr);

	blok->pages[page].Valid = true;
	blok->pages[page].cell = FrameNr;
	FIFO.push(FrameNr);
	if (ID_of_a_process_which_frame_is_being_overriden != -1 && Nr_of_the_page != -1)
	Update_Overide(ID_of_a_process_which_frame_is_being_overriden, Nr_of_the_page);//w pcb procesu, który by³ w ramce przed jej nadpisaniem, ustaw pages list, zeby juz nie wskazywa na ta ramke 
}

int PamiecOperiWirt::Get_Free_Frame_Number()
{
	for (int i = 0; i < 128; i=i+16)
	{
		if (OM[i] == '-')
		{
			return i/16;//zwroc index pierwszej pustej ramki jeœli puste w ogóle s¹
		}
	}//bo jak ich nie ma to realizuj wyrzucanie z OM wg FIFO = zwróc index ramki która by³a najd³u¿ej
	int x = FIFO.front();
	FIFO.pop();
	return x;
	
}



void PamiecOperiWirt::PrintOM()
{
	int counter = 0;
	cout << "AKTUALNY STAN PAMIECI OPERACYJNEJ" << endl;
	for (int i = 0; i < OMsize/framesize; i++)
	{
		cout << "Frame nr " << i + 1 << "  ";
		for (int j = 0 ; j < framesize ; j++)
		{
			cout << OM[counter] << " ";
			counter++;
		}
		cout << endl;
	}
}

void PamiecOperiWirt::PrintVM(std::vector<PCB*> AllProc)
{

	if (VM.capacity() == 0)
	{
		cout << "PAMIEC WIRTUALNA JEST PUSTA" << endl;
		return;
	}

	
	int capacity = VM.capacity();
	for (int i = 0; i < capacity; i++)//skacz po zawartosci VM
	{
		if (VM[i]->abandon == true)
			continue;
		else
		{
			cout << "PAMIEC WIRTUALNA PROCESU NR " << i << endl;
			for (int j = 0; j < AllProc[i]->sopic / 16 + 1; j++)//przeskocz po wszystkich stronach procesu np dla sopic równego 40 mamy 3
			{
				VM[i][j].PrintPage();
			}
			cout << endl;
		}
	}


}

void PamiecOperiWirt::Update_Overide(int PCBnumber, int Pagenr)
{
	//vector <PCB*>::iterator iter;
	iter[PCBnumber]->pages[Pagenr].Valid = false;
	//AllPCBs[PCBnumber]->pages[Pagenr].Valid = false;
	

}

void PamiecOperiWirt::Set_PCB_Vector(vector<PCB*> *AllProc)
{
	this->AllPCBs = AllProc;
}

int PamiecOperiWirt::Return_ID_of_a_Process_using_this_frame(int FrameNr)
{
	iter = AllPCBs->begin();
	int cap = AllPCBs->capacity();
	for (int i = 0; i < cap; i++)
	{
		for (int j = 0; j < iter[i]->sopic / 16 + 1; j++)//przeskocz po wszystkich stronach procesu np dla sopic równego 40 mamy 3
		{
			if (iter[i]->pages[j].cell == FrameNr)
			{
				return i;//search succeeded
			}
		}
		
	}
	return -1;//search failed
}

int PamiecOperiWirt::Return_nr_of_a_page_using_this_frame(int FrameNr)
{
	iter = AllPCBs->begin();
	int cap = AllPCBs->capacity();
	for (int i = 0; i < cap; i++)
	{
		for (int j = 0; j < iter[i]->sopic / 16 + 1; j++)//przeskocz po wszystkich stronach procesu np dla sopic równego 40 mamy 3
		{
			if (iter[i]->pages[j].cell == FrameNr)
			{
				return j;//search succeeded
			}
		}

	}
	return -1;//search failed
}