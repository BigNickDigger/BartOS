#include "stdafx.h"
#include "PamiecOperiWirt.h"

#include "windows.h"

PamiecOperiWirt::PamiecOperiWirt()
{

	BOOL WINAPI Beep(_In_ DWORD dwFreq, _In_ DWORD dwDuration);
	/*Beep(247, 600);
	Beep(247, 600);
	Beep(247, 600);
	Beep(207, 450);
	Beep(277, 150);
	Beep(247, 600);
	Beep(207, 450);
	Beep(277, 150);
	Beep(247, 600);*/

	/*Beep(207.652, 700);
	Beep(311.127, 250);
	Beep(466.164, 500);
	Beep(415.305, 750);
	Beep(622.254, 500);
	Beep(466.164, 900);

	Beep(830.609, 270);
	Beep(622.254, 270);
	Beep(415.305, 270);
	Beep(466.164, 400);*/

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
	}VMiter--;
	VM.erase(VMiter);
	VM.insert(VMiter, new page);
	VM[i - 1]->abandon = true;
	/////////////////////////////////////////////////////////////////
	for (int j = 0; j < blok->sopic / framesize + 1; j++)
	{
		if (blok->pages[j].Valid == true)
		{
			for (int k = 0; k < framesize; k++)
				OM[(blok->pages[j].cell) * 16 + k] = '-';
		}
	}
	////////////////////////////////////////////////////////////////
	int pom = 0;
	for (int i = 0; i < 16; i++)//skacz po tablicy stronic dla usuwanego procesu
	{
		pom = 0;
		if (blok->pages[i].Valid == true)//jak cos wsadzil do fifo
		{
			for (int j = 0; j < OMsize / 16; j++)//wykonaj siê o iloœæ ramek w OM
			{
				if (FIFO[j] == blok->pages[i].cell)
				{
					FIFO.erase(FIFO.begin() + pom);
					break; // dla ka¿dego i jest tylko jedna taka operacja, mo¿na œmia³o break
				}
				pom++;
			}

		}
	}
	//////////////////////////////////////////////////////////////////
	for (int i = 0; i < blok->memory_messages.size(); i++)//skacz po ilosci wiadomosci w pamieci, wyrzucimy je wszystkie z OM
	{
		for (int j = 0; j < framesize; j++)
		{
			OM[((blok->memory_messages[i]) * 16) + j] = '-';
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


void PamiecOperiWirt::Insert_To_Virtual_Memory(PCB *blok, char *disc_tab, int sopic)
{
	blok->sopic = sopic;
	if (sopic == -1) { blok->Process_State = PCB::Proc_New; return; }
	int number_of_pages = WhichPage(blok->sopic) + 1;
	int pom = 0;
	page *kod = new page[number_of_pages];

	for (int i = 0; i < number_of_pages; i++) {


		for (int j = 0; j < framesize; j++) {
			if (pom < sopic) {
				kod[i].tab[j] = disc_tab[pom]; pom++;
			}
			else {
				VM.push_back(kod); return;
			}
		}

	}
}

void PamiecOperiWirt::save_message(string message)
{
	//szukaj indeksu wolnej ramki, jak nie ma to wg FIFO
	if (message.length() > OMsize) { std::cout << "wiadomosc jest wieksza niz rozmiar pamieci operacyjnej\n"; return; }
	int k = 0;
	for (int i = 0; i < message.length() / framesize + 1; i++)// dla 14 = 1 obieg, dla 20 = 2 obiegi
	{
		short FrameNr = Get_Free_Frame_Number();
		int ID_of_a_process_which_frame_is_being_overriden = Return_ID_of_a_Process_using_this_frame(FrameNr);
		int Nr_of_the_page = Return_nr_of_a_page_using_this_frame(FrameNr);// 4 linijki naprawiajace nadpisywanie innym programom tablice stronic
		if (ID_of_a_process_which_frame_is_being_overriden != -1 && Nr_of_the_page != -1)
			Update_Overide(ID_of_a_process_which_frame_is_being_overriden, Nr_of_the_page);

		for (int j = 0; j < framesize; j++)//pomocniczy for czyszcz¹cy ramke przed jej wypelnieniem
		{
			OM[(FrameNr * framesize) + j] = '-';
		}

		for (int j = 0; j < framesize; j++)
		{
			OM[(FrameNr * framesize) + j] = message[k];//wpisz wiadomosc do pamieci
			if (k == message.length()){break;}
			k++;
		}

		for (auto it = AllProc.begin(); it != AllProc.end(); it++)//skacz po zawartosci allproca
		{
			if ((*it)->Process_State == PCB::Proc_Running)
			{
				(*it)->memory_messages.push_back(FrameNr);//wrzuc do pcb
				FIFO.push_back(FrameNr);
			}
		}

	}

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

	for (int j = 0; j < framesize; j++)
	{
		OM[(FrameNr * framesize) + j] = VM[blok->Process_ID - 1][page].tab[j];
	}

	int ID_of_a_process_which_frame_is_being_overriden = Return_ID_of_a_Process_using_this_frame(FrameNr);
	int Nr_of_the_page = Return_nr_of_a_page_using_this_frame(FrameNr);

	blok->pages[page].Valid = true;
	blok->pages[page].cell = FrameNr;
	FIFO.push_back(FrameNr);
	if (ID_of_a_process_which_frame_is_being_overriden != -1 && Nr_of_the_page != -1)
		Update_Overide(ID_of_a_process_which_frame_is_being_overriden, Nr_of_the_page);//w pcb procesu, który by³ w ramce przed jej nadpisaniem, ustaw pages list, zeby juz nie wskazywa na ta ramke 
}

int PamiecOperiWirt::Get_Free_Frame_Number()
{
	for (int i = 0; i < 128; i = i + 16)
	{
		if (OM[i] == '-')
		{
			return i / 16;//zwroc index pierwszej pustej ramki jeœli puste w ogóle s¹
		}
	}//bo jak ich nie ma to realizuj wyrzucanie z OM wg FIFO = zwróc index ramki która by³a najd³u¿ej

	int x = FIFO.front();
	FIFO.pop_front();
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
	if (VM.capacity() == 0)
	{
		cout << "PAMIEC WIRTUALNA JEST PUSTA" << endl;
		return;
	}

	int cnt = 0;
	auto it = AllProc.begin();
	it++;//przeskocz idle
	for (auto it2 = VM.begin(); it2 != VM.end(); it2++)//skacz po zawartosci PAMIECI WIRTUALNEJ
	{
		if (VM[cnt]->abandon == true)//je¿eli znaleziona strona jest stron¹ zombie, leæ dalej
		{
			cnt++;
			continue;
		}
		else
		{
			cout << "PAMIEC WIRTUALNA PROCESU NR " << (*it)->Process_ID << endl;
			for (int i = 0; i < (*it)->sopic / 16 + 1; i++)//przeskocz po wszystkich stronach procesu np dla sopic równego 40 mamy 3
			{
				VM[cnt][i].PrintPage();
			}
			cout << endl;
			cnt++;
		}
		it++;
	}


}

void PamiecOperiWirt::Update_Overide(int PCBnumber, int Pagenr)
{
	//vector <PCB*>::iterator iter;
	iter = this->AllProc.begin();
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
	//	for (int j = 0; j < iter[i]->sopic / 16 + 1; j++)//przeskocz po wszystkich stronach procesu np dla sopic równego 40 mamy 3
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
		if (cnt == 1)it++;//przeskocz idle
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








//void PamiecOperiWirt::PrintVM()
//{
//	//vector<PCB*>AllProcc = *AllProc;
//	if (VM.capacity() == 0)
//	{
//		cout << "PAMIEC WIRTUALNA JEST PUSTA" << endl;
//		return;
//	}
//
//	//cout << VM.capacity() << endl;
//	//cout << VM.size() << endl;
//	//cout << AllProc->capacity() << endl;
//	//cout << AllProc->size() << endl;
//
//	int capacity = VM.capacity();
//	int cnt = 1;
//	for (auto it = AllProc.begin(); it != AllProc.end(); it++)//skacz po zawartosci allproca
//	{
//		if (cnt == 1)it++;
//		if (VM[cnt - 1]->abandon == true)//je¿eli znaleziona strona jest stron¹ zombie, leæ dalej
//		{
//			cnt++;
//			continue;
//		}
//		else
//			if ((*it)->Process_ID == 0)
//			{
//				continue;
//			}
//		{
//			cout << "PAMIEC WIRTUALNA PROCESU NR " << (*it)->Process_ID << endl;
//			for (int i = 0; i < (*it)->sopic / 16 + 1; i++)//przeskocz po wszystkich stronach procesu np dla sopic równego 40 mamy 3
//			{
//				VM[cnt - 1][i].PrintPage();
//			}
//			cout << endl;
//			cnt++;
//		}
//	}
//
//
//}