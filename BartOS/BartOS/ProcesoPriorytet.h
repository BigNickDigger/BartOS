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
int NUMBER_OF_PRIORITIES = 7; //ile mamy priorytetow-1, bo to cpp

struct List {
	std::queue<PCB*> proces;
	List *next;
	List *prev;
};

/*
Wyw³aszczenie przez w¹tek o wy¿szym priorytecie mo¿e byæ konsekwencj¹:
wejœcia w¹tku o wy¿szym priorytecie w stan gotowoœci,
podwy¿szenia priorytetu w¹tku gotowego.
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
	int *KiReadySummary; //mapa bitowa pokazuj¹ca niepuste kolejki


	std::list<PCB*> KiDispatcher[7];

	
	
};



#endif 