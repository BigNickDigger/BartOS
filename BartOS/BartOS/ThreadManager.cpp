#include "stdafx.h"
#include "ThreadManager.h"
#include "PCB.h"
/*Darek Krajewski - Zarz¹dzanie procesami*/

int CThreadManager::IdentGen = 0;
CThreadManager::CThreadManager(PamiecOperiWirt* Memory, ProcesoPriorytet *pl)
{
	srand(time(NULL));
	this->Memory = Memory;
	planista = pl;
	makeprocess("IDLE");
	//PrintProcesses();
}


CThreadManager::~CThreadManager()
{
	AllProc.clear();

}
int CThreadManager::makeprocess(string name) {
	PCB* nowy = new PCB;
	nowy->nazwa = name;
	nowy->sem->AllProc = &AllProc;
	//Memory->Insert_To_Virtual_Memory(nowy);
	nowy->Process_State = PCB::Proc_Ready;
	nowy->PriorityDynamic = 0;
	nowy->Process_ID = IdentGen; IdentGen++;
	nowy->Priority = rand() % 6 + 1;	
	//	Proc_Control_block->pages = new stronice[(sopic / 16) + 1]; #kuba
	AllProc.push_back(nowy);
	planista->addProcess(nowy);
	return (IdentGen-1);
}
int CThreadManager::makeprocess(string name, int prior) {
	 PCB* nowy = new PCB;
	 nowy->nazwa = name;
	 nowy->sem->AllProc = &AllProc;
	 //Memory->Insert_To_Virtual_Memory(nowy);
	 nowy->Process_State = PCB::Proc_Ready;
	 nowy->PriorityDynamic = 0;
	 nowy->Process_ID = IdentGen; IdentGen++;
	 nowy->Priority = prior;
	 //	Proc_Control_block->pages = new stronice[(sopic / 16) + 1]; #kuba
	 AllProc.push_back(nowy);
	 planista->addProcess(nowy);
	 return (IdentGen - 1);
 }
void CThreadManager::RemoveProcess(int id) {
	if (id == 0) { printf("\nNie mozna usunac procesu IDLE\n"); return; }
	for (auto it = AllProc.begin(); it != AllProc.end(); it++) {
		if ((*it)->Process_ID == id && (*it)->Process_State == PCB::Proc_Terminated) {
		
			//Memory->DeleteProcess((*it));// ZEPSUTE
			planista->removeProcess(*it);
			AllProc.erase(it); 
			
			return;
		}
	}
	cout << "\t+-----------------------------------+\n";//28
	cout << "\t|                             |-| |X|\n";
	cout << "\t+-----------------------------------+\n";
	cout << "\t| Proces " << id << " nie istnieje w systemie! |\n";
	cout << "\t|     Lub nie jest TERMINATED       |\n";
	cout << "\t|                                   |\n";
	cout << "\t|      |OK|        |No Trudno|      |\n";
	cout << "\t|                                   |\n";
	cout << "\t+-----------------------------------+\n";
}
void CThreadManager::RemoveProcess(int id, bool flag) {
	
	if (gethandle(id) != NULL) {
		for (auto it = AllProc.begin(); it != AllProc.end(); ++it) {
			if ((*it)->Process_ID == id) { AllProc.erase(it); return; }
		}
	}
	else {
		cout << "\t+-----------------------------------+\n";//28
		cout << "\t|                             |-| |X|\n";
		cout << "\t+-----------------------------------+\n";
		cout << "\t| Proces " << id << " nie istnieje w systemie! |\n";
		cout << "\t|                                   |\n";
		cout << "\t|                                   |\n";
		cout << "\t|      |OK|        |No Trudno|      |\n";
		cout << "\t|                                   |\n";
		cout << "\t+-----------------------------------+\n";
	}


}

void CThreadManager::PrintProcesses() {
	printf("\nProcesy w systemie:\n");
	if (!AllProc.empty()) {
		cout << "ID\tName\tState\tPriority\n";
		for (auto it = AllProc.begin(); it != AllProc.end(); it++) {
			cout << (*it)->Process_ID << "\t";
			cout << (*it)->nazwa << "\t";
			cout << getstate((*it)->Process_State) << "\t";
			cout << (*it)->Priority << "\n";
		}
	}
	else printf("Cos poszlo nie tak, nie ma procesu IDLE\n");
}
char* CThreadManager::getstate(int el) {
	switch (el) {
	case PCB::Proc_New:
		return "New";
	case PCB::Proc_Running:
		return "Running";
	case PCB::Proc_Waiting:
		return "Waiting/Halted";
	case PCB::Proc_Ready:
		return "Ready";
	case PCB::Proc_Terminated:
		return "Terminated";
	case PCB::Proc_Erroneous:
		return "Terminated_With_Error";
	default: return "Unknown";
	}

}
PCB* CThreadManager::gethandle(int id) {
	for (auto it = AllProc.begin(); it != AllProc.end(); it++) {
		if ((*it)->Process_ID == id)return (*it);
	}
	return NULL;
}
void CThreadManager::PrintProcessState(int id, bool flag) {
	for (auto it = AllProc.begin(); it != AllProc.end(); it++) {
		if ((*it)->Process_ID == id) {
			printf("\nStan Procesu : %s\n", (*it)->nazwa.c_str());
			printf("ID\tRegA\tRegB\tRegC\tPC\tStan\n");
			printf("%d\t%d\t%d\t%d\t%d\t%s\n", (*it)->Process_ID,
				(*it)->RegA,
				(*it)->RegB,
				(*it)->RegC,
				(*it)->ProgramCounter,
				getstate((*it)->Process_State));
			if (!(*it)->messages.empty()) { cout << "Proces " << id << " ma " << (*it)->messages.size() << " wiadomosci.\n"; }
			else cout << "Proces " << id << " nie ma zadnych wiadomosci\n";
		}
	}
}
void CThreadManager::setstate(PCB* bl, PCB::stan st) {
	bl->Process_State = st;
}
void CThreadManager::setstate(int id, PCB::stan st) {
	gethandle(id)->Process_State = st; return;
	for (auto it = AllProc.begin(); it != AllProc.end(); it++) {
		if ((*it)->Process_ID == id) {
			(*it)->Process_State = st;
		}
	}
}
