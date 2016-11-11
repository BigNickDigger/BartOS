#include "stdafx.h"
#include "KomunikacjaProcesowa.h"
//#include <iostream>



//#include <vector>
using namespace std;

KomunikacjaProcesowa::KomunikacjaProcesowa(vector<PCB*>*AllProcc)
{
	AllProc = AllProcc;
}



KomunikacjaProcesowa::~KomunikacjaProcesowa()
{
}

void KomunikacjaProcesowa::Nadaj(int Odbiorca, string tresc)
{
	//szukanie skrzynki
	int counter = 0;
	for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
	{
		if (ElementAt[counter]->Process_ID == Odbiorca)
		{
			string S="";
			S += to_string(/*Nadawca*/4) + " " + tresc;
			ElementAt[counter]->messages.push(S);
//TUTAJ SIGNAL JAKBY SOBIE SPAL TAMTEN (CZEKAL NA WIADOMOSC)signal(odbiorca)
		}
		else
		{
			counter++;
		}
	}
	//no tutaj to niszczymy pana procesa czy tam zatrzymujemy
}

string KomunikacjaProcesowa::Odbierz(int Odbiorca)
{
	//szukanie skrzynki
	int counter = 0;
	for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
	{
		if (ElementAt[counter]->Process_ID == Odbiorca)
		{
			if (ElementAt[counter]->messages.empty())
			{
				//SEMAFOR wait(Odbiorca);
			}
			string x;
			x = ElementAt[counter]->messages.front();
			ElementAt[counter]->messages.pop();
			return x;
		}
		else
		{
			counter++;
		}
	}
	//SEMAFOR wait(Odbiorca);
}


/*    push - umieszczenie nowego elementu na koñcu kolejki;
pop - usuniêcie istniej¹cego elementu z pocz¹tku kolejki;
empty - informacja czy kolejka jest pusta;
size - zwraca iloœæ elementów umieszczonych w kolejce;
front - zwraca wartoœæ pierwszego elementu w kolejce.
back - zwraca wartoœæ ostatniego elementu w kolejce.
*/