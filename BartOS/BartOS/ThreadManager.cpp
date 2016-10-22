#include "stdafx.h"
#include "ThreadManager.h"
/*Darek Krajewski - Zarz¹dzanie procesami*/
int CThreadManager::IdentGen = 0x00000001;
CThreadManager::CThreadManager(PamiecOperiWirt* Memory, char*name)
{
	Proc_Control_block->nazwa = name;
	Proc_Control_block->Process_State = PCB::Proc_New;
	Proc_Control_block->Process_ID = IdentGen; IdentGen++;
	Proc_Control_block->Priority = Average_Priority;
	Proc_Control_block->IsParent = true;

}


CThreadManager::~CThreadManager()
{
}
void CThreadManager::fork(char*name) {

}