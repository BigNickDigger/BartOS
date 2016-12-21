#pragma once
#ifndef __ProcesoPriorytet_H_INCLUDED__	
#define __ProcesoPriorytet_H_INCLUDED__ 

class PCB;
#include "PCB.h";
#include <vector>
#include <algorithm>
/*
Wyw³aszczenie przez w¹tek o wy¿szym priorytecie mo¿e byæ konsekwencj¹:
wejœcia w¹tku o wy¿szym priorytecie w stan gotowoœci,
podwy¿szenia priorytetu w¹tku gotowego.
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
	int *KiReadySummary;		//mapa bitowa pokazuj¹ca niepuste kolejki

	PCB *running;
	std::vector<std::vector<PCB*>> KiDispatcher;
};

#endif 