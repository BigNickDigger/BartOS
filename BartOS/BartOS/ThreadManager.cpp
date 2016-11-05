#include "stdafx.h"
#include "ThreadManager.h"
/*Darek Krajewski - Zarz¹dzanie procesami*/
int CThreadManager::IdentGen = 0x00000001;
CThreadManager::CThreadManager(PamiecOperiWirt* Memory)
{
	srand(time(NULL));
	
	this->Memory = Memory;
}


CThreadManager::~CThreadManager()
{
	if (Proc_Control_block->Process_State == PCB::Proc_Terminated) {
		Memory->DeleteProcess(*this->Proc_Control_block);
		AllProc.erase(ElementAt);
	}
	else(Proc_Control_block->Process_State = PCB::Proc_Erroneous);
}
void CThreadManager::CreateProcess(char*name) {
	Proc_Control_block->nazwa = name;
	try { Proc_Control_block->pages = &Memory->MemRequest(); }
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
}