//amen

#include "stdafx.h"
#include "ProcesoPriorytet.h"

ProcesoPriorytet::ProcesoPriorytet()
{
	KiDispatcher = new std::list<PCB*>[NUMBER_OF_PRIORITIES];
	KiReadySummary = new int[NUMBER_OF_PRIORITIES];
	for (int i = 0; i < NUMBER_OF_PRIORITIES; i++)
		KiReadySummary[i] = 0;
}

ProcesoPriorytet::~ProcesoPriorytet()
{
	delete KiReadySummary;
}

PCB *ProcesoPriorytet::FindReadyThread()
{
	for (int i = NUMBER_OF_PRIORITIES; i >= 0; i++) {
		if(KiReadySummary[i] == 1) {
			std::list<PCB*>::iterator it;
			for (auto it : KiDispatcher[i]) {
				if (it->Process_State == PCB::Proc_Ready) return it;
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
	int i = a->Priority;
	KiDispatcher[i].push_back(a);
	KiReadySummary[i] = 1;
}
void ProcesoPriorytet::removeProcess(PCB * a)
{
	int i = a->Priority;
	std::list<PCB*>::iterator it;
	for (auto it : KiDispatcher[i]) {
		if(it == a) KiDispatcher[i].remove(a);
	}
}


bool ProcesoPriorytet::moveProcess(PCB *a)
{
	
	return false;
}


void ProcesoPriorytet::updateKiReadySummary() {
	for (int i = 1; i <= NUMBER_OF_PRIORITIES; i++) {
		if (KiDispatcher[i].empty() == true) {
			KiReadySummary[i] = 1;
		}
		else KiReadySummary[i] = 0;
	}
}

void ProcesoPriorytet::tick_processes()
{
	for (int i = 1; i <= NUMBER_OF_PRIORITIES; i++) {
		std::list<PCB*>::iterator it;
		for (auto it : KiDispatcher[i]) {
			if (it->Process_State == PCB::Proc_Ready) {
				it->idleTime++;
				if (it->idleTime > NUMBER_OF_HUNGER) {
					moveProcess(it);
					updateKiReadySummary();
				}
			}
		}
	}
}

