#pragma once
#include <iostream>
#include "PCB.h"
#include <vector>
#include <queue>
using namespace std;

struct Mess
{
	int nadawca;
	string tresc;
};


class KomunikacjaProcesowa
{
public:
	KomunikacjaProcesowa(vector<PCB*>*AllProcc);
	~KomunikacjaProcesowa();
	void Send(int, string);  //Wyslij (do id, wiadomosc)
	void Receive();  //Odbierz wiad z queue
	void ShowMessages(int);  //Pokaz wiadomosci w Queue procesi o (id)
	vector<PCB*>*AllProc;
	vector<PCB*>::iterator ElementAt;
};

/*    push - umieszczenie nowego elementu na koñcu kolejki;
    pop - usuniêcie istniej¹cego elementu z pocz¹tku kolejki;
    empty - informacja czy kolejka jest pusta;
    size - zwraca iloœæ elementów umieszczonych w kolejce;
    front - zwraca wartoœæ pierwszego elementu w kolejce.
    back - zwraca wartoœæ ostatniego elementu w kolejce.kkk
	*/
