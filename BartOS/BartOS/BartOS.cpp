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
	PAM.Set_PCB_Vector(&EatShit.AllProc);
	
	/*EatShit.AllProc.push_back(new PCB);
	EatShit.AllProc[0]->sopic = 40;
	EatShit.AllProc[0]->Process_ID = 0;

	EatShit.AllProc.push_back(new PCB);
	EatShit.AllProc[1]->sopic = 70;
	EatShit.AllProc[1]->Process_ID = 1;

	EatShit.AllProc.push_back(new PCB);
	EatShit.AllProc[2]->sopic = 35;
	EatShit.AllProc[2]->Process_ID = 2;*/
//ZAMIAST POWYZSZEGO UZYWAC CREATEPROCESS
	EatShit.CreateProcess("shite1", 40);
	EatShit.CreateProcess("shite2", 40);
	EatShit.CreateProcess("shite3", 35);
	
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

	cout << "start" << endl;
	cout << "wydrukuj obie pamieci" << endl;

	PAM.PrintVM(EatShit.AllProc);
	PAM.PrintOM();

	cout << "wrzuc 3 kody do pamieci wirtualnej" << endl;

	PAM.VM.push_back(kod_procesu);
	PAM.VM.push_back(kod_procesu2);
	PAM.VM.push_back(kod_procesu3);

	cout << "wydrukuj obie pamieci" << endl;

	PAM.PrintVM(EatShit.AllProc);
	PAM.PrintOM();

	cout << "wrzuc kod programu 1 i 3 do pamieci operacyjnej" << endl;

	for (int i = 0; i < 40; i++)
	{
		PAM.Get_Char_From_OM(EatShit.AllProc[0], i);
	}

	for (int i = 0; i < 35; i++)
	{
		PAM.Get_Char_From_OM(EatShit.AllProc[2], i);
	}

	cout << "wydrukuj obie pamieci" << endl;

	PAM.PrintVM(EatShit.AllProc);
	PAM.PrintOM();

	cout << "Wrzucamy proces nr 2" << endl;
	
	for (int i = 0; i < 70; i++)
	{
		PAM.Get_Char_From_OM(EatShit.AllProc[1], i);
	}
	
	cout << "wydrukuj obie pamieci" << endl;

	PAM.PrintOM();
	PAM.PrintVM(EatShit.AllProc);

	PAM.DeleteProcess(EatShit.AllProc[0]);
	PAM.DeleteProcess(EatShit.AllProc[2]);

	PAM.PrintOM();
	PAM.PrintVM(EatShit.AllProc);
	
	EatShit.CreateProcess("poot", 36);
	//EatShit.PrintProcesses();
	//printf("%d", EatShit.AllProc.size());
	//EatShit.gethandle(2)->pages;
	EatShit.PrintProcesses();
	
	
    return 0;
}

