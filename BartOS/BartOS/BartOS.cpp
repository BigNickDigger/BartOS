/*
Piotrek = Przyznawanie priorytet�w procesom
Olaw	= Mechanizmy synchronizacyjne
Bartek	= Shell i programy ASSembler
Krzysiu	= Komunikacja proces�w
Kuba	= Zarz�dzanie pami�ci� opercyjn� i wirtualn�
Darek	= Zarz�dzanie procesami(Tworzenie proces�w)
Marcin	= System plik�w
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

