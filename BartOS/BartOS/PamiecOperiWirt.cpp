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
	}//VMiter--;
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
	////////////////////////////////////////////////////////////////
	int pom = 0;
	if (FIFO.size() != 0)
	{
		for (int i = 0; i < 16; i++)//skacz po tablicy stronic dla usuwanego procesu
		{
			pom = 0;
			if (blok->pages[i].Valid == true)//jak cos wsadzil do fifo
			{
				for (int j = 0; j < FIFO.size(); j++, pom++)//wykonaj si� o ilo�� ramek w OM
				{
					if (FIFO[j] == blok->pages[i].cell)
					{
						FIFO.erase(FIFO.begin() + pom);
						break; // dla ka�dego i jest tylko jedna taka operacja, mo�na �mia�o break
					}
				}

			}
		}
	}
	//////////////////////////////////////////////////////////////////

	string s;
	for (int i = 0; i < blok->allmessagesever.size(); i++)//skacz po ilosci wiadomosci w pamieci, wyrzucimy je wszystkie z OM
	{
		s = blok->allmessagesever.front();
		if (message_is_in_OM(s))
		{
			for (int j = 0; j < framesize; j++)
			{
				OM[((blok->memory_messages[i]) * 16) + j] = '-';
			}
		}
	}

	//for (int i = 0; i < blok->memory_messages.size(); i++)//skacz po ilosci wiadomosci w pamieci, wyrzucimy je wszystkie z OM
	//{
	//	for (int j = 0; j < framesize; j++)
	//	{
	//		OM[((blok->memory_messages[i]) * 16) + j] = '-';
	//	}
	//}
}
bool PamiecOperiWirt::message_is_in_OM(string s)
{
	string line;
	for (int i = 0; i < OMsize / 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			line += OM[(i * 16) + j];
		}
		if (line.find(s) != std::string::npos)
			return true;
	}
	return false;
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
	if (message.length() > OMsize) { std::cout << "wiadomosc jest wieksza niz rozmiar pamieci operacyjnej\n"; return; }
	int k = 0;
	for (int i = 0; i < message.length() / framesize + 1; i++)// dla 14 = 1 obieg, dla 20 = 2 obiegi
	{
		short FrameNr = Get_Free_Frame_Number();
		int ID_of_a_process_which_frame_is_being_overriden = Return_ID_of_a_Process_using_this_frame(FrameNr);
		int Nr_of_the_page = Return_nr_of_a_page_using_this_frame(FrameNr);// 4 linijki naprawiajace nadpisywanie innym programom tablice stronic
		if (ID_of_a_process_which_frame_is_being_overriden != -1 && Nr_of_the_page != -1)
			Update_Overide(ID_of_a_process_which_frame_is_being_overriden, Nr_of_the_page);

		for (int j = 0; j < framesize; j++)//pomocniczy for czyszcz�cy ramke przed jej wypelnieniem
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
				(*it)->allmessagesever.push_back(message);
			}
		}

	}

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
		OM[(FrameNr * framesize) + j] = '-';//wyczysc ramke przed jej nadpisaniem
	}
	for (int j = 0; j < framesize; j++)
		{
			OM[(FrameNr * framesize) + j] = VM[blok->Process_ID][page].tab[j];
		}


	int ID_of_a_process_which_frame_is_being_overriden = Return_ID_of_a_Process_using_this_frame(FrameNr);
	int Nr_of_the_page = Return_nr_of_a_page_using_this_frame(FrameNr);

	blok->pages[page].Valid = true;
	blok->pages[page].cell = FrameNr;
	FIFO.push_back(FrameNr);
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
	std::cout << "FIFO ";
	for (auto it = FIFO.begin(); it != FIFO.end(); it++)
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
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
	//it++;//przeskocz idle
	for (auto it2 = VM.begin(); it2 != VM.end(); it2++)//skacz po zawartosci PAMIECI WIRTUALNEJ
	{
		if (VM[cnt]->abandon == true)//je�eli znaleziona strona jest stron� zombie, le� dalej
		{
			cnt++;
			continue;
		}
		else
		{
			cout << "PAMIEC WIRTUALNA PROCESU NR " << (*it)->Process_ID << endl;
			for (int i = 0; i < (*it)->sopic / 16 + 1; i++)//przeskocz po wszystkich stronach procesu np dla sopic r�wnego 40 mamy 3
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
	iter = this->AllProc.begin();
	iter[PCBnumber]->pages[Pagenr].Valid = false;
}

void PamiecOperiWirt::Set_PCB_Vector(vector<PCB*> &AllProc)
{
	this->AllProc = AllProc;
}

int PamiecOperiWirt::Return_ID_of_a_Process_using_this_frame(int FrameNr)
{
	int cnt = 0;
	for (auto it = AllProc.begin(); it != AllProc.end(); it++)//skacz po zawartosci VM
	{
		//if (cnt == 1)it++;//przeskocz
		for (int j = 0; j < 16; j++)//skacz po tablicy stronic ktora ma 16 indeksow
		{
			if ((*it)->pages[j].cell == FrameNr && (*it)->pages[j].Valid == true)
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
	int cnt = 0;
	for (auto it = AllProc.begin(); it != AllProc.end(); it++)//skacz po zawartosci VM
	{
		//if (cnt == 1)it++;//przeskocz idle
		for (int j = 0; j < 16; j++)//skacz po tablicy stronic ktora ma 16 indeksow
		{
			if ((*it)->pages[j].cell == FrameNr && (*it)->pages[j].Valid == true)
			{
				return j;//search succeeded
			}

		}
		cnt++;
	}
	return -1;//search failed
}