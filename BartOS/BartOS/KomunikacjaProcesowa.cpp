#include "stdafx.h"
#include "KomunikacjaProcesowa.h"
//#include <iostream>

using namespace std;

KomunikacjaProcesowa::KomunikacjaProcesowa(vector<PCB*>*AllProcc)
{
	AllProc = AllProcc;  // wskaznik na wszystkie procki
}



KomunikacjaProcesowa::~KomunikacjaProcesowa()
{
}

void KomunikacjaProcesowa::Send(int Odbiorca, string tresc)
{
	//szukanie skrzynki
	bool x=0;
	for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
	{
		if ((*ElementAt)->Process_ID == Odbiorca)
		{
			x = 1;
			string S = "";
			S += to_string(/*Nadawca*/4) + " " + tresc; // nadanie wiadomosci 
			(*ElementAt)->messages.push(S);
		}
		else
		{

		}
	}
	if (x == 0)
	{
		for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
		{
			if ((*ElementAt)->Process_State == PCB::Proc_Running) 
			{
				(*ElementAt)->Process_State == PCB::Proc_Terminated; // znalezienie aktualnego procesu i zmiana jego stanu na terminated jezeli odbiorca nie istnieje
			}
		}
	}
}

void KomunikacjaProcesowa::Receive() 
{
	bool spi = 1;
	//szukanie skrzynki
	int counter = 0;
	if (spi == 1)
	{
		for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
		{
			if ((*ElementAt)->Process_State == PCB::Proc_Running)
			{
				(*ElementAt)->sem->Wait((*ElementAt)->Process_ID);
				if ((*ElementAt)->messages.empty())
				{
					return;
				}
				else
				{
					string x;
					x = (*ElementAt)->messages.front();

					(*ElementAt)->messages.pop();
				}
			}
		}
	}
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