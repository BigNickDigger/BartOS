#pragma once
/*
DO ZIOMKA OD PCB
proszê o dodanie pól:
int idleTime; //czas bez procesora
int workingTime; //czas ile dany procesor spedzil na procesorze
int PriorityDynamic; //pole uzywane do podnoszenia priorytetu procesu
*/
#ifndef __ProcesoPriorytet_H_INCLUDED__	
#define __ProcesoPriorytet_H_INCLUDED__ 

class PCB;
#include "PCB.h";
#include <list>

/*
Wyw³aszczenie przez w¹tek o wy¿szym priorytecie mo¿e byæ konsekwencj¹:
wejœcia w¹tku o wy¿szym priorytecie w stan gotowoœci,
podwy¿szenia priorytetu w¹tku gotowego.
*/


class ProcesoPriorytet {
private:
	int NUMBER_OF_PRIORITIES = 16; //ile mamy priorytetow-1, bo to cpp
	int NUMBER_OF_TIME_QUANTUM = 3; //ile rozkazow trwa kwant
	int NUMBER_OF_HUNGER = 6; //co ile rozkazow zwiekszamy priorytet glodzonego procesu
public:
	ProcesoPriorytet();
	~ProcesoPriorytet();

	PCB *FindReadyThread();		//zwraca najwyzszy wykonywalny proces
	void ReadyThread(PCB *a);	//proces zmienia stan na ready lub podniesiono priorytet jakiemus procesowi
	void addProcess(PCB *a);	//dodawanie procesu do mojej struktury danych
	void removeProcess(PCB *a); //usuwanie procesu z mojej struktury
	bool moveProcess(PCB *a);	//przeniesienie procesu miedzy kolejkami
	void tick_processes();		//podnosimy idleTime procesom gotowym
	void throwToBack(PCB *a);	//wyrzuc na koniec kolejki dany proces
	void printMyBeautifulStructurePlease(); //drukowanie


	void updateKiReadySummary();
	int *KiReadySummary;		//mapa bitowa pokazuj¹ca niepuste kolejki


	std::list<PCB*> *KiDispatcher;
};

#endif 