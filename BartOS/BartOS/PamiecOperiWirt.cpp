#include "stdafx.h"
#include "PamiecOperiWirt.h"



PamiecOperiWirt::PamiecOperiWirt()
{
	OM_Next_Frame_Victim = 0;
	IndexforWM = 0;
	IndexforWM2 = 0;
	for (int i = 0; i < OMsize; i++)
	{
		OM[i].nr = i;
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
// ta funkcja ponizej to chyba siê nie przyda xdxdxd, prêdzej ta pod ni¹ ///////////////////////////////////////////////////////////////////
//char PamiecOperiWirt::Get_Whole_Process_From_Memory(PCB blok)//wywolanie tej funkcji rozpocznie proces zwracania wszystkich charow sk³adaj¹cych siê na program do P_Oper
//{
//	for (int i = 0; i < blok.sopic; i++)//przebiega po wszystkich stronach procesu 
//	{
//		if (blok.pages[i].Valid == true)      //wejdŸ tu jeœli ramka JEST w PAM OP
//		{
//			for (int j = 0; j < framesize; j++)
//			{
//				//strona znajduje sie w pamieci OP wiec zwracamy z niej chary... jest ich nie wiêcej ni¿ framesize=16
//				if (POper[i].tab[j] != '-')			 //je¿eli w pamiêci jest COKOLWIEK innego ni¿ puste
//					return POper[i].tab[j];			 //zwróæ char
//				else                                 //jeœli jest '-' czyli œmieci
//					break;                           //break bo w tej ramce nie ma juz nic wiecej, idŸ do kolejnego i, czyli kolejnej ramki
//			}
//		}
//		if (blok.pages[i].Valid == false)                                 //wejdŸ tu jeœli ramki NIE MA w PAM OP
//		{
//			//strony nie ma w pamieci OP, sciagnij ja
//			Get_Page_From_WM(blok, i);//pobierz strone z pam wirt do operacyjnej, jak to zrobisz, to zwracaj z niej chary USTAW ROWNIEZ BIT NA VALID
//			for (int j = 0; j < framesize; j++)
//			{
//				//strona znajduje sie w pamieci OP wiec zwracamy z niej chary... jest ich nie wiêcej ni¿ framesize=16
//				if (POper[i].tab[j] != '-')			 //je¿eli w pamiêci jest COKOLWIEK innego ni¿ puste
//					return POper[i].tab[j];			 //zwróæ char
//				else                                 //jeœli jest '-' czyli œmieci
//					break;                           //break bo w tej ramce nie ma juz nic wiecej, idŸ do kolejnego i, czyli kolejnej ramki
//			}
//		}
//	}
//
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char PamiecOperiWirt::Get_Char_From_OM(PCB *blok, int LogicAdr)
{
	int page = WhichPage(LogicAdr);
	int offset = WhatOffset(LogicAdr);


	if (blok->pages[page].Valid == true)      //wejdŸ tu jeœli ramka JEST w PAM OP
	{
		return OM[page].tab[offset]; //ez zwróæ chara
	}
	else      //wejdŸ tu jeœli ramki NIE MA w PAM OP
	{
		Get_Page_From_WM(blok, page);//pobierz strone z pam wirt do operacyjnej, jak to zrobisz, to zwroc char USTAW ROWNIEZ BIT NA VALID
		return OM[page].tab[offset]; //ez zwróæ chara
	}
}

void PamiecOperiWirt::Get_Page_From_WM(PCB *blok, int page)
{
	
}

//string PamiecOperiWirt::Return_A_Formed_Order(PCB blok)
//{
//	//prawdopodobnie sie nie przyda / problem z implementacja
//	return "xD";
//}


void PamiecOperiWirt::PrintOM()
{
	cout << "AKTUALNY STAN PAMIECI OPERACYJNEJ" << endl;
	for (int i = 0; i < OMsize; i++)
	{
		cout << "FRAME "; cout.width(2); cout << OM[i].nr << " -> ";
		OM[i].PrintPage();
	}
}

void PamiecOperiWirt::PrintWM(std::vector<PCB*> AllProc)
{
	//vector<PCB*>::iterator AllProcIter;

	if (VM.capacity() == 0)
	{
		cout << "PAMIEC WIRTUALNA JEST PUSTA" << endl;
		return;
	}
	cout << "AKTUALNY STAN PAMIECI WIRTUALNEJ" << endl;

	int i = 0; // helpful iter :>
	int capacity = AllProc.capacity();
	for (i = 0 ; i < capacity ; i++)//przeskocz po wszystkich procesach a wiêc i = dany proces
	{
		cout << "PAMIEC WIRTUALNA PROCESU NR " << i << endl;
		for (int j = 0; j < AllProc[i]->sopic / 16 + 1; j++)//przeskocz po wszystkich stronach procesu np 40/16 +1 = 3
		{
			VM[i][j].PrintPage();
		}
		cout << endl;
	}
	//for (AllProcIter = AllProc.begin(); AllProcIter != AllProc.end(); AllProcIter++)//przeskocz po wszystkich procesach a wiêc i = dany proces





	//int i = 0;
	//int x = 0; // x = iloœæ stron dla danego procesu
	//for (VMiter = VM.begin(); VMiter != VM.end(); VMiter++)
	//{
	//	x = 
	//	for (int j=0;j<AllProc[i]->sopic)
	//	cout << "VM PAGE "; cout << VMiter ;
	//}
	
	
	

}

//cout << "PAGE "; cout.width(2); cout << VMiter[i]->nr << " -> ";
//VMiter[i]->PrintPage();