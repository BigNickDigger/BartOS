#include "stdafx.h"
#include "PamiecOperiWirt.h"


PamiecOperiWirt::PamiecOperiWirt()
{
	OM_Next_Frame_Victim = 0;
	IndexforWM = 0;
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


void PamiecOperiWirt::DeleteProcess(PCB blok)
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

char *PamiecOperiWirt::ReturnLineOf16Chars()
{
	char* eatshit = "eat shit for real, nigga";
	return eatshit;
}

void PamiecOperiWirt::Insert_To_Virtual_Memory()
{

}
// ta funkcja ponizej to chyba siê nie przyda xdxdxd, prêdzej ta pod ni¹
char PamiecOperiWirt::Get_Whole_Process_From_Memory(PCB blok)//wywolanie tej funkcji rozpocznie proces zwracania wszystkich charow sk³adaj¹cych siê na program do P_Oper
{
	for (int i = 0; i < 4; i++)//przebiega po wszystkich stronach procesu (za³ó¿my ¿e 4)
	{
		if (blok.pages[i].Valid == true)      //wejdŸ tu jeœli ramka JEST w PAM OP
		{
			for (int j = 0; j < framesize; j++)
			{
				//strona znajduje sie w pamieci OP wiec zwracamy z niej chary... jest ich nie wiêcej ni¿ framesize=16
				if (POper[i].tab[j] != '-')			 //je¿eli w pamiêci jest COKOLWIEK innego ni¿ puste
					return POper[i].tab[j];			 //zwróæ char
				else                                 //jeœli jest '-' czyli œmieci
					break;                           //break bo w tej ramce nie ma juz nic wiecej, idŸ do kolejnego i, czyli kolejnej ramki
			}
		}
		if (blok.pages[i].Valid == false)                                 //wejdŸ tu jeœli ramki NIE MA w PAM OP
		{
			//strony nie ma w pamieci OP, sciagnij ja
			Get_Page_From_WM(i);//pobierz strone z pam wirt do operacyjnej, jak to zrobisz, to zwracaj z niej chary USTAW ROWNIEZ BIT NA VALID
			for (int j = 0; j < framesize; j++)
			{
				//strona znajduje sie w pamieci OP wiec zwracamy z niej chary... jest ich nie wiêcej ni¿ framesize=16
				if (POper[i].tab[j] != '-')			 //je¿eli w pamiêci jest COKOLWIEK innego ni¿ puste
					return POper[i].tab[j];			 //zwróæ char
				else                                 //jeœli jest '-' czyli œmieci
					break;                           //break bo w tej ramce nie ma juz nic wiecej, idŸ do kolejnego i, czyli kolejnej ramki
			}
		}
	}

}

char PamiecOperiWirt::Get_Char_From_Process(PCB blok, int LogicAdr)
{
	int page = WhichPage(LogicAdr);
	int offset = WhatOffset(LogicAdr);
	if (blok.pages[page].Valid == true)      //wejdŸ tu jeœli ramka JEST w PAM OP
	{
		return POper[page].tab[offset]; //ez zwróæ chara
	}
	if (blok.pages[page].Valid == false)      //wejdŸ tu jeœli ramki NIE MA w PAM OP
	{
		Get_Page_From_WM(page);//pobierz strone z pam wirt do operacyjnej, jak to zrobisz, to zwroc char USTAW ROWNIEZ BIT NA VALID
		return POper[page].tab[offset];//i ³adnie zwróæ chara
	}
}

void PamiecOperiWirt::Get_Page_From_WM(int page)
{
	for (int i = 0; i < framesize; i++)
	{
		POper[OM_Next_Frame_Victim].tab[i] = PWirt[page].tab[i];
	}
	OM_Next_Frame_Victim++;
	if (OM_Next_Frame_Victim == 16)
		OM_Next_Frame_Victim = 0;
	
}


void PamiecOperiWirt::PrintOM()
{
	cout << "AKTUALNY STAN PAMIECI OPERACYJNEJ" << endl;
	for (int i = 0; i < OMsize; i++)
	{
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
		PWirt[i].PrintPage();
	}
}