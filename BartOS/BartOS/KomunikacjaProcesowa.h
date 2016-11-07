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

/*    push - umieszczenie nowego elementu na koñcu kolejki;
    pop - usuniêcie istniej¹cego elementu z pocz¹tku kolejki;
    empty - informacja czy kolejka jest pusta;
    size - zwraca iloœæ elementów umieszczonych w kolejce;
    front - zwraca wartoœæ pierwszego elementu w kolejce.
    back - zwraca wartoœæ ostatniego elementu w kolejce.
	*/