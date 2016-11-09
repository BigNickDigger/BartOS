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
#include "KomunikacjaProcesowa.h"
using namespace std;
const float SystemVer = 1.337;
int main()
{
	//K$R*A
	//KRZYSIU MASZ
	//NIE WK^R%^AJ MNIE:
	//ZABAWA NIE ZNA GRANIC, ZNOWU TO ROBIE IKS DE DE DE, MemoryGuy2016~
	PamiecOperiWirt PAM;
	CThreadManager EatShit(&PAM);
	KomunikacjaProcesowa EatMoreShit();
	std::vector<PCB*>*MoreShit = &EatShit.AllProc;
	
	EatShit.AllProc.push_back(new PCB);
	EatShit.AllProc[0]->sopic = 40;
	EatShit.AllProc.push_back(new PCB);
	EatShit.AllProc[1]->sopic = 70;

	page kod_procesu[3];
	for (int i = 0; i < 3; i++)
		for (int j=0;j<16;j++)
			kod_procesu[i].tab[j] = 'a' + j;

	page kod_procesu2[5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 16; j++)
		{
			if (i != 4)
			kod_procesu2[i].tab[j] = '5' + j;
			else
			if (j<5)
				kod_procesu2[i].tab[j] = '5' + j;
			
		}


	PAM.PrintWM(EatShit.AllProc);
	PAM.VM.push_back(kod_procesu);
	PAM.VM.push_back(kod_procesu2);
	PAM.PrintWM(EatShit.AllProc);
	

	
    return 0;
}

