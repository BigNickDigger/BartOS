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
	EatShit.AllProc[0]->Process_ID = 0;

	EatShit.AllProc.push_back(new PCB);
	EatShit.AllProc[1]->sopic = 70;
	EatShit.AllProc[1]->Process_ID = 1;

	EatShit.AllProc.push_back(new PCB);
	EatShit.AllProc[2]->sopic = 35;
	EatShit.AllProc[2]->Process_ID = 2;

	page kod_procesu[3];
	for (int i = 0; i < 3; i++)
		for (int j=0;j<16;j++)
			kod_procesu[i].tab[j] = '1';

	page kod_procesu2[5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 16; j++)
		{
			if (i != 4)
			kod_procesu2[i].tab[j] = '2';
			else
			if (j<5)
				kod_procesu2[i].tab[j] = '2';
			
		}

	page kod_procesu3[3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 16; j++)
		{
			if (i != 2)
				kod_procesu3[i].tab[j] = '3';
			else
				if (j<6)
					kod_procesu3[i].tab[j] = '3';
		}



	PAM.PrintVM(EatShit.AllProc);
	PAM.VM.push_back(kod_procesu);
	PAM.VM.push_back(kod_procesu2);
	PAM.PrintVM(EatShit.AllProc);
	PAM.PrintOM();
	PAM.Get_Page_From_WM(EatShit.AllProc[0], 0);
	PAM.Get_Page_From_WM(EatShit.AllProc[0], 1);
	PAM.Get_Page_From_WM(EatShit.AllProc[0], 2);
	PAM.Get_Page_From_WM(EatShit.AllProc[1], 0);
	PAM.Get_Page_From_WM(EatShit.AllProc[1], 1);
	PAM.Get_Page_From_WM(EatShit.AllProc[1], 2);
	PAM.Get_Page_From_WM(EatShit.AllProc[1], 3);
	PAM.Get_Page_From_WM(EatShit.AllProc[1], 4);
	PAM.PrintOM();
	cout << "USUWAM" << endl;
	PAM.DeleteProcess(EatShit.AllProc[0]);
	PAM.DeleteProcess(EatShit.AllProc[1]);
	PAM.PrintOM();
	PAM.PrintVM(EatShit.AllProc);
	cout << "bierzemy proces 3" << endl;
	PAM.VM.push_back(kod_procesu3);
	for (int i = 0; i < 35; i++)
	{
		PAM.Get_Char_From_OM(EatShit.AllProc[2], i);
	}
	PAM.PrintOM();
	PAM.PrintVM(EatShit.AllProc);
	
	

	
    return 0;
}

