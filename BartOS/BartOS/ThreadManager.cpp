#include "stdafx.h"
#include "ThreadManager.h"
#include "PCB.h"
/*Darek Krajewski - Zarządzanie procesami*/

int CThreadManager::IdentGen = 0;
CThreadManager::CThreadManager(PamiecOperiWirt* Memory)
{
	srand(time(NULL));	
	this->Memory = Memory;
	CreateProcess("IDLE", 13);
	AllProc[0]->Priority = 0;
	AllProc[0]->Process_State = PCB::Proc_Ready;
}


CThreadManager::~CThreadManager()
{
	AllProc.clear();
	
}
void CThreadManager::CreateProcess(char*name, int sopic) {
	PCB* nowy = new PCB;
	nowy->nazwa = name;
	try { /*Proc_Control_block->pages = */&Memory->MemRequest(); }
	catch (int ErrCode) {
		switch (rand()%2) {
			case 1:nowy->Process_State = PCB::Proc_Ready;
			break;
			case 0:nowy->Process_State = PCB::Proc_New;
			break;
			
		}
		
	}
	nowy->Process_ID = IdentGen; IdentGen++;
	nowy->Priority = rand() % 6 + 1;
//	Proc_Control_block->pages = new stronice[(sopic / 16) + 1]; #kuba
	AllProc.push_back(nowy);

}
void CThreadManager::RemoveProcess(int id) {
	if (id == 0) { printf("\nNie mozna usunac procesu IDLE\n"); }
	for (auto it = AllProc.begin(); it != AllProc.end(); it++) {
		if ((*it)->Process_ID == id && (*it)->Process_State == PCB::Proc_Terminated) {
			
			Memory->DeleteProcess((*it));
			
			AllProc.erase(it); return;
		}
	}
}
void CThreadManager::RemoveProcess(int id, bool flag) {
	auto it = AllProc.begin();
	(*it)->Process_State = PCB::Proc_Terminated;
	Memory->DeleteProcess((*it));
	AllProc.erase(it);
}

void CThreadManager::PrintProcesses() {
	if (!AllProc.empty()) {
		printf("ID\tName\tState\tPriority\n");
		for (auto it = AllProc.begin(); it != AllProc.end(); it++) {		
			printf("%d\t%s\t%s\t%d\n",(*it)->Process_ID,
				(*it)->nazwa,
				getstate((*it)->Process_State),(*it)->Priority );
		}
	}
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
				printf("%d\t%d\t%d\t%d\t%d\t%s\n",(*it)->Process_ID,
					(*it)->RegA,
					(*it)->RegB,
					(*it)->RegC,
					(*it)->ProgramCounter,
					getstate((*it)->Process_State));
		}
	}
}