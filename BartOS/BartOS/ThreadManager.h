#pragma once

#include "PamiecOperiWirt.h"
#include <vector>
#include "ProcesoPriorytet.h"

#define Average_Priority 4


//typedef int PamiecOperiWirt;
class CThreadManager
{
public:
	CThreadManager(PamiecOperiWirt* Memory, ProcesoPriorytet *pl);
	~CThreadManager();
	int CreateProcess(string name);
	int CreateProcess(string name, int prior);
	void RemoveProcess(int id);//usuwa procesy POZA procesem IDLE
	void RemoveProcess(int id, bool flag);//usuwa proces IDLE
	std::vector<PCB*>AllProc;//Wszystkie procesy sa tu.
	void PrintProcesses();//Drukuje wszystkie procesy i info
	PCB* gethandle(int id);//Nawet nie pamietam po co to tu jest
	char* getstate(int el);
	void setstate(PCB* bl, PCB::stan st);
	void setstate(int id, PCB::stan st);
	void PrintProcessState(int id, bool flag);
private:
	PamiecOperiWirt* Memory;
	static int IdentGen;
	ProcesoPriorytet *planista;


};

