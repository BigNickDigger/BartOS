#pragma once
#include <iostream>
#include "ThreadManager.h"
//#include "PCB.h"
using namespace std;

struct Mess
{
	string tresc;
};

class KomunikacjaProcesowa
{
public:
	KomunikacjaProcesowa(CThreadManager &Y);
	~KomunikacjaProcesowa();
	CThreadManager *X;
	void Nadaj(int, int, string);
	string Odbierz(int);
	//std::vector<PCB*>::const_iterator xD;

};

/*    push - umieszczenie nowego elementu na ko�cu kolejki;
    pop - usuni�cie istniej�cego elementu z pocz�tku kolejki;
    empty - informacja czy kolejka jest pusta;
    size - zwraca ilo�� element�w umieszczonych w kolejce;
    front - zwraca warto�� pierwszego elementu w kolejce.
    back - zwraca warto�� ostatniego elementu w kolejce.
	*/