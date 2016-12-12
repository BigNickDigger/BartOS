#include "stdafx.h"
#include "KomunikacjaProcesowa.h"
//#include <iostream>

using namespace std;

KomunikacjaProcesowa::KomunikacjaProcesowa(vector<PCB*>*AllProcc)
{
	AllProc = AllProcc;
}



KomunikacjaProcesowa::~KomunikacjaProcesowa()
{
}

void KomunikacjaProcesowa::Send(int Odbiorca, string tresc)
{
	//szukanie skrzynki
	bool x=0;
	int counter = 0;
	for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
	{
		if (ElementAt[counter]->Process_ID == Odbiorca)
		{
			x = 1;
			string S="";
			S += to_string(/*Nadawca*/4) + " " + tresc;
			ElementAt[counter]->messages.push(S);
			//signal(odbiorca)
		}
		else
		{
			counter++;
		}
	}
	if (x == 0)
	{
		cout << "hi";
		//no tutaj to niszczymy pana procesa czy tam zatrzymujemy
	}
}

void KomunikacjaProcesowa::Receive() //Potrzebuje zmienna globalna Running zeby to smigalo :3
{
	//szukanie skrzynki
	int counter = 0;
	//for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
	//{
	//	if (ElementAt[counter]->Process_ID == Odbiorca)
	//	{
	//		if (ElementAt[counter]->messages.empty())
	//		{
	//			//SEMAFOR wait(Odbiorca);
	//		}
	//		string x;
	//		x = ElementAt[counter]->messages.front();
	//		ElementAt[counter]->messages.pop();
	//		return x;
	//	}
	//	else
	//	{
	//		counter++;
	//	}
	/*}*/
	//SEMAFOR wait(Odbiorca);
}

void KomunikacjaProcesowa::ShowMessages(int id)
{
	bool x=0;
	int counter = 0;
	for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
	{
		if (ElementAt[counter]->Process_ID == id)
		{
			x = 1;
			if (ElementAt[counter]->messages.empty())
						{
							cout << "IPC: Brak wiadomosci w kolejce do procesu o id=" << id << endl;
							return;
						}
			else
			{
				//for (int i = 0;i<)
			}
		}
		else
		{
			counter++;
		}
	}
	if (x == 0)
	{
		cout << "Brak procesu o id=" << id << endl;
	}
}


/*    push - umieszczenie nowego elementu na koñcu kolejki;
pop - usuniêcie istniej¹cego elementu z pocz¹tku kolejki;
empty - informacja czy kolejka jest pusta;
size - zwraca iloœæ elementów umieszczonych w kolejce;
front - zwraca wartoœæ pierwszego elementu w kolejce.
back - zwraca wartoœæ ostatniego elementu w kolejce.
*/