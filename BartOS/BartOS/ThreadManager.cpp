#include "stdafx.h"
#include "ThreadManager.h"
/*Darek Krajewski - Zarz¹dzanie procesami*/
int CThreadManager::IdentGen = 0x00000001;
CThreadManager::CThreadManager()
{
	Proc_Control_block->Process_State = PCB::Proc_New;
	Proc_Control_block->Process_ID = IdentGen; IdentGen++;
}


CThreadManager::~CThreadManager()
{
}
