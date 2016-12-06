#include "stdafx.h"
#include "ThreadManager.h"
#include "PCB.h"
/*Darek Krajewski - Zarz¹dzanie procesami*/
int CThreadManager::IdentGen = 0;
CThreadManager::CThreadManager(PamiecOperiWirt* Memory)
{
	srand(time(NULL));	
	this->Memory = Memory;
	poot[1].push(new PCB());
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
		switch (ErrCode) {
			case 1:nowy->Process_State = PCB::Proc_Ready;
			break;
			case 0:nowy->Process_State = PCB::Proc_New;
			break;
			
		}
		
	}
	nowy->Process_ID = IdentGen; IdentGen++;
	nowy->Priority = rand() % 7 + 1;
//	Proc_Control_block->pages = new stronice[(sopic / 16) + 1]; #kuba
	AllProc.push_back(nowy);

}
void CThreadManager::RemoveProcess(int id) {
	for (auto it = AllProc.begin(); it != AllProc.end(); it++) {
		if ((*it)->Process_ID == id && (*it)->Process_State == PCB::Proc_Terminated) {
			
			Memory->DeleteProcess((*it));
			
			AllProc.erase(it); return;
		}
	}
}
void CThreadManager::PrintProcesses() {
	if (!AllProc.empty()) {
		printf("ID\tName\tState\t\n");
		for (auto it = AllProc.begin(); it != AllProc.end(); it++) {		
			printf("%d\t%s\t%s\n",(*it)->Process_ID,
				(*it)->nazwa,
				getstate((*it)->Process_State) );
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
	}

}
PCB* CThreadManager::gethandle(int id) {
	for (auto it = AllProc.begin(); it != AllProc.end(); it++) {
		if ((*it)->Process_ID == id)return (*it);
	}
}