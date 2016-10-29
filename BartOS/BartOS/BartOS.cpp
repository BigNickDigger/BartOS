/*
Piotrek = Przyznawanie priorytet�w procesom
Olaw	= Mechanizmy synchronizacyjne
Bartek	= Shell i programy ASSembler
Krzysiu	= Komunikacja proces�w
Kuba	= Zarz�dzanie pami�ci� opercyjn� i wirtualn�
Darek	= Zarz�dzanie procesami(Tworzenie proces�w)
Marcin	= System plik�w
Adam	= ASSembler interpreter

System Windowso-niepodobny
Wpisujcie tutaj propozycje nazw:
BartOS
kabanOS
PornOS



*/


#include "stdafx.h"
#include <iostream>
#include <string>
#include "PamiecOperiWirt.h"
#include "PCB.h"

using namespace std;
const float SystemVer = 1.337;
int main()
{
	//bawie sie tutaj, mo�ecie to wszystko wywali� w pi�dziet//////////////////////////////
	PamiecOperiWirt PAM;
	PCB proces;
	proces.pages = new stronice[8];
	proces.pages[0].cell = 0;
	proces.pages[1].cell = 1;
	proces.pages[0].Valid = true;//ramka nr 0 znajduje sie w pamieci
	proces.pages[1].Valid = true;//ramka nr 1 znajduje sie w pamieci. usuniecie procesu = usuniecie ramek 0 i 1

	proces.nazwa = "cienias";//supermega proces

	PAM.iter = PAM.POper.begin();
	PAM.iter->data = "ADD A,8 MOV B,";//zawartosc pierwszej ramki pamieci
	PAM.iter++;
	PAM.iter->data = "ADD B,4 MOV A,";//zawartosc drugiej ramki pamieci

	PAM.iter = PAM.POper.begin();
	cout << "Pierwsza ramka w pam operacyjnej o nr " << PAM.iter->nr << " zawiera 14 charow, takich " << PAM.iter->data << endl << endl;
	PAM.iter++;
	cout << "Druga ramka w pam operacyjnej o nr " << PAM.iter->nr << " zawiera 14 charow, takich " << PAM.iter->data << endl << endl;

	for (PAM.iter = PAM.POper.begin(); PAM.iter != PAM.POper.end(); PAM.iter++)
	{
		cout << "RAMKA nr "<< PAM.iter->nr << endl;
	}
	PAM.DeleteProcess(proces);//funkcja usuwajaca proces z pamieci
	cout << endl;
	for (PAM.iter = PAM.POper.begin(); PAM.iter != PAM.POper.end(); PAM.iter++)
	{
		cout << "RAMKA nr " << PAM.iter->nr << endl;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}

