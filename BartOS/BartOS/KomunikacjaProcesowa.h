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
	void Nadaj(int, int, string);
	string Odbierz(int);
	vector<PCB*>*AllProc;
	vector<PCB*>::iterator ElementAt;
};

/*    push - umieszczenie nowego elementu na ko�cu kolejki;
    pop - usuni�cie istniej�cego elementu z pocz�tku kolejki;
    empty - informacja czy kolejka jest pusta;
    size - zwraca ilo�� element�w umieszczonych w kolejce;
    front - zwraca warto�� pierwszego elementu w kolejce.
    back - zwraca warto�� ostatniego elementu w kolejce.
	*/
