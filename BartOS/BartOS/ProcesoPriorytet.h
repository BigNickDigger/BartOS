#pragma once
#ifndef __ProcesoPriorytet_H_INCLUDED__	
#define __ProcesoPriorytet_H_INCLUDED__ 

class PCB;
#include "PCB.h";
#include <vector>
#include <algorithm>
/*
Wyw�aszczenie przez w�tek o wy�szym priorytecie mo�e by� konsekwencj�:
wej�cia w�tku o wy�szym priorytecie w stan gotowo�ci,
podwy�szenia priorytetu w�tku gotowego.
*/


class ProcesoPriorytet {
public:
	ProcesoPriorytet();
	~ProcesoPriorytet();

	static int NUMBER_OF_PRIORITIES; //ile mamy priorytetow-1, bo to cpp
	static int NUMBER_OF_TIME_QUANTUM; //ile rozkazow trwa kwant
	static int NUMBER_OF_HUNGER; //co ile rozkazow zwiekszamy priorytet glodzonego procesu


	PCB *FindReadyThread();		//zwraca najwyzszy gotowy proces
	void addProcess(PCB *a);	//dodawanie procesu do mojej struktury danych
	void removeProcess(PCB *a); //usuwanie procesu z mojej struktury
	bool moveProcess(PCB *a);	//przeniesienie procesu miedzy kolejkami
	bool tick_processes();		//podnosimy idleTime procesom gotowym
	void throwToBack(PCB *a);	//wyrzuc na koniec kolejki dany proces

	void printMyBeautifulStructurePlease(); //drukowanie
	void printMyBeatufiulBitVectorPlease(); //drukowanie wektora bitowego

	void updateKiReadySummary();
	int *KiReadySummary;		//mapa bitowa pokazuj�ca niepuste kolejki

	PCB *running;
	std::vector<std::vector<PCB*>> KiDispatcher;
};

#endif 