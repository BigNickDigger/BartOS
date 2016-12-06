//amen

#include "stdafx.h"
#include "ProcesoPriorytet.h"

ProcesoPriorytet::ProcesoPriorytet()
{
	int *KiReadySummary = new int[NUMBER_OF_PRIORITIES];
	for (int i = 0; i < NUMBER_OF_PRIORITIES; i++) 
		KiReadySummary[i] = 0;
}

ProcesoPriorytet::~ProcesoPriorytet()
{
	delete KiReadySummary;
}

PCB *ProcesoPriorytet::FindReadyThread()
{
	for (int i = 1; i < NUMBER_OF_PRIORITIES; i++) {
		if(KiReadySummary[NUMBER_OF_PRIORITIES-i] == 1) {
			std::list<PCB*>::iterator it;
			for (it = KiDispatcher[i].begin(); it != KiDispatcher[i].end(); ++it) {
				if ((*it)->Process_State == PCB::Proc_Ready) return *it;
			}
		}
	}
}

void ProcesoPriorytet::ReadyThread(PCB *a)
{
	//if (terazWykonywanyProces->priority < a-.Priority) => dajemy a na procesor
	//else dodajemy a do odpowiedniej kolejki
}

void ProcesoPriorytet::addProcess(PCB *a)
{
	int i = a->Priority + a->PriorityDynamic;
	KiDispatcher[i].push_back(a);
	KiReadySummary[i] = 1;
}

void ProcesoPriorytet::removeProcess(PCB * a)
{
	int i = a->Priority + a->PriorityDynamic;
	std::list<PCB*>::iterator it;
	for (it = KiDispatcher[i].begin(); it != KiDispatcher[i].end(); ++it) {
		if(*it == a) KiDispatcher[i].remove(a);
	}
	
}

void ProcesoPriorytet::tick_processes()
{
	for (int i = i; i <= NUMBER_OF_PRIORITIES; i++) {
		std::list<PCB*>::iterator it;
		for (it = KiDispatcher[i].begin(); it != KiDispatcher[i].end(); ++it) {
			if ((*it)->Process_State == PCB::Proc_Ready) (*it)->idleTime++;
		}
	}
}