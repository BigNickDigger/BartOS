/*
Piotrek = Przyznawanie priorytetów procesom
Olaw	= Mechanizmy synchronizacyjne
Bartek	= Shell i programy ASSembler
Krzysiu	= Komunikacja procesów
Kuba	= Zarz¹dzanie pamiêci¹ opercyjn¹ i wirtualn¹
Darek	= Zarz¹dzanie procesami(Tworzenie procesów)
Marcin	= System plików
Adam	= ASSembler interPeter

System Windowso-niepodobny
Wpisujcie tutaj propozycje nazw:
BartOS
kabanOS
PornOS
Cyborg



*/

//SHIT BROKE FELLAS

#include "stdafx.h"
#include <iostream>
#include <string>
#include "PamiecOperiWirt.h"
#include "ThreadManager.h"

using namespace std;
const float SystemVer = 1.337;
int main2()
{
	//K$R*A
	//KRZYSIU MASZ
	//NIE WK^R%^AJ MNIE:
	//ZABAWA NIE ZNA GRANIC, ZNOWU TO ROBIE IKS DE DE DE, MemoryGuy2016~
	PamiecOperiWirt PAM;
	CThreadManager EatShit(&PAM);
	KomunikacjaProcesowa EatMoreShit();
	std::vector<PCB*>*MoreShit = &EatShit.AllProc;
	PCB BLOK; BLOK.pages = new stronice[3]; BLOK.pages[0].Valid = false; BLOK.pages[1].Valid = false; BLOK.pages[2].Valid = false;
	EatShit.AllProc.push_back(&BLOK);

	//END
	char bufor[48];
	for (int i = 0; i < framesize; i++)
	{
		PAM.PWirt[0].tab[i] = 'a' + i;
		PAM.PWirt[1].tab[i] = '1' + i;
		PAM.PWirt[2].tab[i] = 'd' + i;
	}
	PAM.PrintWM();
	PAM.PrintOM();
	cout << "Sciagam do pomocniczego bufora 3 pelne ramki z pamieci operacyjnej, ktora jest pusta, wiec nastapi obsluga bledu strony\nz wykorzystaniem pamieci wirtualnej" << endl;
	for (int i = 0; i < framesize*3; i++)
		bufor[i] = PAM.Get_Char_From_OM(BLOK, i);//sciagam komorki (adres logiczny) od 0 do 47
	PAM.PrintOM();
	cout << "Co udalo sie sciagnac z pamieci operacyjnej? Wypisz bufor..." << endl;
	for (int i = 0; i < framesize*3; i++)
	{
		cout << bufor[i]<<" ";
	}cout << endl;
	cout << EatShit.AllProc.capacity();
	cout << MoreShit->capacity();
    return 0;
}

