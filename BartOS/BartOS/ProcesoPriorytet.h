#pragma once
/*
DO ZIOMKA OD PCB
prosz� o dodanie p�l:
int idleTime; //czas bez procesora
int workingTime; //czas ile dany procesor spedzil na procesorze
int PriorityDynamic; //pole uzywane do podnoszenia priorytetu procesu
*/
#ifndef __ProcesoPriorytet_H_INCLUDED__	
#define __ProcesoPriorytet_H_INCLUDED__ 

class PCB;
#include "PCB.h";
#include <list>
int NUMBER_OF_PRIORITIES = 7; //ile mamy priorytetow-1, bo to cpp

struct List {
	std::queue<PCB*> proces;
	List *next;
	List *prev;
};

/*
Wyw�aszczenie przez w�tek o wy�szym priorytecie mo�e by� konsekwencj�:
wej�cia w�tku o wy�szym priorytecie w stan gotowo�ci,
podwy�szenia priorytetu w�tku gotowego.
*/





class ProcesoPriorytet {
public:
	ProcesoPriorytet();
	~ProcesoPriorytet();

	PCB *FindReadyThread(); //proces oddaje procesor
	void ReadyThread(PCB *a);		//proces zmienia stan na ready oraz podniesiono priorytet jakiemus procesowi
	void addProcess(PCB *a); //dodawanie procesu do mojej struktury danych
	void removeProcess(PCB *a); //usuwanie procesu z mojej struktury
	void tick_processes();
	int *KiReadySummary; //mapa bitowa pokazuj�ca niepuste kolejki


	std::list<PCB*> KiDispatcher[7];

	
	
};



#endif 