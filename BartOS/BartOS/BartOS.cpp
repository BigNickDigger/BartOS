/*
Piotrek = Przyznawanie priorytetów procesom
Olaw	= Mechanizmy synchronizacyjne
Bartek	= Shell i programy ASSembler
Krzysiu	= Komunikacja procesów
Kuba	= Zarz¹dzanie pamiêci¹ opercyjn¹ i wirtualn¹
Darek	= Zarz¹dzanie procesami(Tworzenie procesów)
Marcin	= System plików
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
	//bawie sie tutaj, mo¿ecie to wszystko wywaliæ w piŸdziet//////////////////////////////
	PamiecOperiWirt PAM;
	PCB proces;
	proces.pages = new stronice[8];
	proces.pages[0].cell = 0;
	proces.pages[5].cell = 5;
	proces.pages[0].Valid = true;//ramka nr 0 znajduje sie w pamieci
	proces.pages[5].Valid = true;//ramka nr 1 znajduje sie w pamieci. usuniecie procesu = usuniecie ramek 0 i 1

	proces.nazwa = "cienias";//supermega proces

	PAM.iter = PAM.POper.begin();
	PAM.iter->data = "ADD A,8 MOV B,";//zawartosc pierwszej ramki pamieci
	advance(PAM.iter,5);
	PAM.iter->data = "ADD B,4 MOV A,";//zawartosc drugiej ramki pamieci

	PAM.iter = PAM.POper.begin();
	cout << "ramka w pam operacyjnej o nr " << PAM.iter->nr << " zawiera 14 charow, takich " << PAM.iter->data << endl << endl;
	advance(PAM.iter, 5);
	cout << "ramka w pam operacyjnej o nr " << PAM.iter->nr << " zawiera 14 charow, takich " << PAM.iter->data << endl << endl;

	for (PAM.iter = PAM.POper.begin(); PAM.iter != PAM.POper.end(); PAM.iter++)
	{
		cout << "RAMKA nr " << PAM.iter->nr << " z zawartoscia " << PAM.iter->data << endl;
	}
	cout << "usuwanie procesu z pamieci..." << endl;
	PAM.DeleteProcess(proces);//funkcja usuwajaca proces z pamieci
	cout << endl;
	for (PAM.iter = PAM.POper.begin(); PAM.iter != PAM.POper.end(); PAM.iter++)
	{
		cout << "RAMKA nr " << PAM.iter->nr << " z zawartoscia " << PAM.iter->data << endl;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}

