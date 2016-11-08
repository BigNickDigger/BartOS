#include "stdafx.h"
#include "PamiecOperiWirt.h"



PamiecOperiWirt::PamiecOperiWirt()
{
	OM_Next_Frame_Victim = 0;
	IndexforWM = 0;
	IndexforWM2 = 0;
	for (int i = 0; i < OMsize; i++)
	{
		POper[i].nr = i;
	}
	for (int i = 0; i < WMsize; i++)
	{
		PWirt[i].nr = i;
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
	int index;
	for (int i = 0 ; i < WMsize; i++)//obiegnij tyle razy ile jest stron dla pcb //sopic = 30 = 3 strony
	{
		if (blok->pages[i].Valid == false)//tylko strona do czyszczenia
		{
			PWirt[i].Clear();
		}
		if (blok->pages[i].Valid == true)//strona i ramka do czyszczenia
		{
			PWirt[i].Clear();
			POper[i].Clear();
			blok->pages[i].Valid = false;
			blok->pages[i].cell = NULL;
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
	//przeszuuj pamiec wirtualna i wrzucaj do pustych stron po16 charów I USTAWIAJ BITY VALID

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
		return POper[page].tab[offset]; //ez zwróæ chara
	}
	else      //wejdŸ tu jeœli ramki NIE MA w PAM OP
	{
		Get_Page_From_WM(blok, page);//pobierz strone z pam wirt do operacyjnej, jak to zrobisz, to zwroc char USTAW ROWNIEZ BIT NA VALID
		return POper[page].tab[offset]; //ez zwróæ chara
	}
}

void PamiecOperiWirt::Get_Page_From_WM(PCB *blok, int page)
{
	for (int i = 0; i < framesize; i++)
	{
		POper[OM_Next_Frame_Victim].tab[i] = PWirt[page].tab[i];
	}

	//blok.pages[brakujacy index].cell = OM_Next_Frame_Victim;
	blok->pages[IndexforWM2].Valid = true; IndexforWM2++;// !!! pomocniczy index tymczasowo trzeba zrobic poprawny
	OM_Next_Frame_Victim++;
	if (OM_Next_Frame_Victim == 16)
		OM_Next_Frame_Victim = 0;
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
		cout << "FRAME "; cout.width(2); cout << POper[i].nr << " -> ";
		POper[i].PrintPage();
	}
}

void PamiecOperiWirt::PrintWM()
{
	cout << "AKTUALNY STAN PAMIECI WIRTUALNEJ" << endl;
	for (int i = 0; i < WMsize; i++)
	{
		if (i % 16 == 0 && i != 0)
			cout << endl;
		cout.width(2);
		cout << "PAGE "; cout.width(2); cout << PWirt[i].nr << " -> ";
		PWirt[i].PrintPage();

	}
}