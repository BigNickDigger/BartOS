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



*/

//SHIT BROKE FELLAS

#include "stdafx.h"
#include <iostream>
#include <string>
#include "PamiecOperiWirt.h"
#include "ThreadManager.h"

using namespace std;
const float SystemVer = 1.337;
int main()
{
	//K$R*A
	//KRZYSIU MASZ
	//NIE WK^R%^AJ MNIE:
	PamiecOperiWirt PAM;
	CThreadManager EatShit(&PAM);
	KomunikacjaProcesowa EatMoreShit();
	std::vector<PCB*>MoreShit = EatShit.AllProc;
	//END
	
	for (int i = 0; i < framesize; i++)
		PAM.POper[0].tab[i] = ('a'+i);
	//PAM.PrintOM();
	cout << PAM.ReturnLineOf16Chars();
    return 0;
}

