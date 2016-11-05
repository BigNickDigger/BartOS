#include "stdafx.h"
#include "ThreadManager.h"
/*Darek Krajewski - Zarz¹dzanie procesami*/
int CThreadManager::IdentGen = 0x00000001;
CThreadManager::CThreadManager(PamiecOperiWirt* Memory, char*name)
{
	srand(time(NULL));
	Proc_Control_block->nazwa = name;
	Proc_Control_block->Process_State = PCB::Proc_New;
	Proc_Control_block->Process_ID = IdentGen; IdentGen++;
	Proc_Control_block->Priority = rand() % 7 + 1;
	int size = 9; Proc_Control_block->pages = new stronice[size]; // Wielkoœæ Pliku / Rozmiar Stronicy 
	//Proc_Control_block->messages.push_back("eatshit");
}


CThreadManager::~CThreadManager()
{
}
void CThreadManager::CreateProcess(char*name) {

}