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
	KomunikacjaProcesowa();
	~KomunikacjaProcesowa();
	void Nadaj(int, int, string);
	void Odbierz(int x);
private:
	vector<PCB*>*AllProc;
};

/*    push - umieszczenie nowego elementu na koñcu kolejki;
    pop - usuniêcie istniej¹cego elementu z pocz¹tku kolejki;
    empty - informacja czy kolejka jest pusta;
    size - zwraca iloœæ elementów umieszczonych w kolejce;
    front - zwraca wartoœæ pierwszego elementu w kolejce.
    back - zwraca wartoœæ ostatniego elementu w kolejce.
	*/
