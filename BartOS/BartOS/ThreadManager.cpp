#include "stdafx.h"
#include "ThreadManager.h"
#include "PCB.h"
/*Darek Krajewski - Zarządzanie procesami*/

int CThreadManager::IdentGen = 0;
CThreadManager::CThreadManager(PamiecOperiWirt* Memory, ProcesoPriorytet *pl)
{
	srand(time(NULL));
	this->Memory = Memory;
	planista = pl;
	CreateProcess("IDLE");
	//PrintProcesses();
}


CThreadManager::~CThreadManager()
{
	AllProc.clear();

}
int CThreadManager::CreateProcess(char*name) {
	PCB* nowy = new PCB;
	nowy->nazwa = name;
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
int CThreadManager::CreateProcess(char*name, int prior) {
	 PCB* nowy = new PCB;
	 nowy->nazwa = name;
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
	printf("Shite\n");
	if (id == 0) { printf("\nNie mozna usunac procesu IDLE\n"); }
	for (auto it = AllProc.begin(); it != AllProc.end(); it++) {
		if ((*it)->Process_ID == id && (*it)->Process_State == PCB::Proc_Terminated) {
		
			//Memory->DeleteProcess((*it));// ZEPSUTE
			planista->removeProcess(*it);
			AllProc.erase(it); 
			
			return;
		}
	}
}
void CThreadManager::RemoveProcess(int id, bool flag) {
	
	gethandle(id)->Process_State = PCB::Proc_Terminated;
	RemoveProcess(id);
/*	auto it = AllProc.begin();
	(*it)->Process_State = PCB::Proc_Terminated;
	planista->removeProcess(*it);
	Memory->DeleteProcess((*it));
	AllProc.erase(it);*/

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
}
void CThreadManager::PrintProcessState(int id, bool flag) {
	for (auto it = AllProc.begin(); it != AllProc.end(); it++) {
		if ((*it)->Process_ID == id) {
			printf("\nStan Procesu : %s\n", (*it)->nazwa);
			printf("ID\tRegA\tRegB\tRegC\tPC\tStan\n");
			printf("%d\t%d\t%d\t%d\t%d\t%s\n", (*it)->Process_ID,
				(*it)->RegA,
				(*it)->RegB,
				(*it)->RegC,
				(*it)->ProgramCounter,
				getstate((*it)->Process_State));
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
