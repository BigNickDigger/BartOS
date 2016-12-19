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
	int id;
	for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
	{
		if ((*ElementAt)->Process_State == PCB::Proc_Running)
		{
			id = (*ElementAt)->Process_ID;
		}
	}
	for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
	{
		if ((*ElementAt)->Process_ID == Odbiorca)
		{
			string sid = to_string(id);
			x = 1;
			string S;
			cout << sid.length() << endl;;
			S +=to_string(sid.length())+""+sid+ tresc; // nadanie wiadomosci 
			cout <<"wiadomosc: "<< S << endl;
			(*ElementAt)->sem->Signal();
			(*ElementAt)->messages.push(S);
			break;
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
				cout << "Proces terminates: nie znaleziono odbiorcy!" << endl;
			}
		}
	}
}

void KomunikacjaProcesowa::Receive() 
{
	//szukanie skrzynki
		for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
		{
			if ((*ElementAt)->Process_State == PCB::Proc_Running)
			{
				if ((*ElementAt)->sleep == 0)
				{
					(*ElementAt)->sem->Wait((*ElementAt)->Process_ID);
					if ((*ElementAt)->messages.empty())
					{
						(*ElementAt)->sleep = 0;
						return;
					}
					else
					{
						string x;
						x = (*ElementAt)->messages.front();
						(*ElementAt)->messages.pop();
						cout << "ODEBRANO: " << x << endl;
						//FUNKCJAKUBY do Pamieci !!!!!! 
					}
				}
				else
				{
					(*ElementAt)->sleep = 1;
					string x;
					x = (*ElementAt)->messages.front();
					(*ElementAt)->messages.pop();
					cout << "ODEBRANO: " << x << endl;
					//FUNKCJAKUBY do Pamieci !!!!!! 
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
	for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
	{
		if ((*ElementAt)->Process_ID == id)
		{
			x = 1;
			if ((*ElementAt)->messages.empty())
						{
							cout << "IPC: Brak wiadomosci w kolejce do procesu o id=" << id << endl;
							return;
						}
			else
			{
				int id;
				string wiad;
				queue<string> pomoc;
				pomoc = (*ElementAt)->messages;
				while (1)
				{
					wiad = pomoc.front();
					id = stoi(wiad.substr(1, wiad[0]));
					int y;
					y = wiad.size() - ((int)wiad[0]-48);
					cout << "Wiadomosc od " << id << ": "<<wiad.substr(((int)wiad[0] - 47),y)<<endl;
					pomoc.pop();
					if (pomoc.empty())
					{
						break;
					}
				}
			}
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