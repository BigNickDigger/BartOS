#include "stdafx.h"
#include "ThreadManager.h"
#include "PCB.h"
/*Darek Krajewski - Zarz¹dzanie procesami*/
int CThreadManager::IdentGen = 0;
CThreadManager::CThreadManager(PamiecOperiWirt* Memory)
{
	srand(time(NULL));
	
	this->Memory = Memory;
}


CThreadManager::~CThreadManager()
{
	AllProc.clear();
	
}
void CThreadManager::CreateProcess(char*name, int sopic) {
	Proc_Control_block->nazwa = name;
	try { /*Proc_Control_block->pages = */&Memory->MemRequest(); }
	catch (int ErrCode) {
		switch (ErrCode) {
			case 1:Proc_Control_block->Process_State = PCB::Proc_Ready;
			break;
			case 0:Proc_Control_block->Process_State = PCB::Proc_New;
			break;
			
		}
		
	}
	Proc_Control_block->Process_ID = IdentGen; IdentGen++;
	Proc_Control_block->Priority = rand() % 7 + 1;
//	Proc_Control_block->pages = new stronice[(sopic / 16) + 1]; #kuba

}
void CThreadManager::RemoveProcess(int id) {
	for (auto it = AllProc.begin(); it != AllProc.end(); it++) {
		if ((*it)->Process_ID == id && (*it)->Process_State == PCB::Proc_Terminated) {
			
			Memory->DeleteProcess(Proc_Control_block);
			
			AllProc.erase(it); return;
		}
	}
}
void CThreadManager::PrintProcesses() {
	if (!AllProc.empty()) {
		printf("ID\tName\tState\t\n");
		for (auto it = AllProc.begin(); it != AllProc.end(); it++) {		
			printf("%d\t%s\t%s\n",Proc_Control_block->Process_ID,
				Proc_Control_block->nazwa,
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