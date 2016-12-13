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
	for (int i = NUMBER_OF_PRIORITIES-1; i >= 0; i--) {
		if (KiReadySummary[i] == 1) {
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
	int i = a->Priority + a->PriorityDynamic;
	KiDispatcher[i].remove(a);
}


bool ProcesoPriorytet::moveProcess(PCB *a)
{
	int i = a->Priority + a->PriorityDynamic;
	for (auto it : KiDispatcher[i]) {
		KiDispatcher[i].remove(a);
		a->PriorityDynamic++;
		i = a->Priority + a->PriorityDynamic;
		KiDispatcher[i].push_back(a);

		updateKiReadySummary();
		return true;
	}
	updateKiReadySummary();
	return false;
}


void ProcesoPriorytet::updateKiReadySummary() {
	for (int i = 0; i < NUMBER_OF_PRIORITIES; i++) {
		if (KiDispatcher[i].empty() == true) {
			KiReadySummary[i] = 1;
		}
		else KiReadySummary[i] = 0;
	}
}

void ProcesoPriorytet::throwToBack(PCB *a)
{
	int i = a->Priority + a->PriorityDynamic;
	KiDispatcher[i].remove(a);
	KiDispatcher[i].push_back(a);
}


void ProcesoPriorytet::tick_processes()
{
	for (int i = 0; i < NUMBER_OF_PRIORITIES; i++) {
		std::list<PCB*>::iterator it;
		for (auto it : KiDispatcher[i]) {
			if (it->Process_State == PCB::Proc_Running) {
				//to moze umrzec
				if ((it->orders_realized != 0) && ((it->orders_realized % NUMBER_OF_TIME_QUANTUM) == 0)) {
					throwToBack(it);
				}
			}
			if (it->Process_State == PCB::Proc_Ready) {
				it->idleTime++;
				if (it->idleTime > NUMBER_OF_HUNGER) {
					if (moveProcess(it)) {
						continue;
					}
				}
			}
		}
	}
}

void ProcesoPriorytet::printMyBeautifulStructurePlease()
{
	for (int i = 0; i < NUMBER_OF_PRIORITIES; i++) {
		std::list<PCB*>::iterator it;
		bool PrintPriority = true;
		for (auto it : KiDispatcher[i]) {
			if (PrintPriority) {
				std::cout << i << ":" << std::endl;
				PrintPriority = false;
			}

			std::cout << it->nazwa << " (" << it->Priority << "+" << it->PriorityDynamic << "); " << std::endl;
		}
	}
}