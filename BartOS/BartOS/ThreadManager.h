#pragma once

#include "PamiecOperiWirt.h"
#include <vector>
#define Average_Priority 4


//typedef int PamiecOperiWirt;
class CThreadManager
{
public:
	CThreadManager(PamiecOperiWirt* Memory);
	~CThreadManager();
	void CreateProcess(char*name, int sopic);
	
	void RemoveProcess(int id);//usuwa procesy POZA procesem IDLE
	void RemoveProcess(int id,bool flag);//usuwa proces IDLE
	std::vector<PCB*>AllProc;//Wszystkie procesy sa tu.
	void PrintProcesses();//Drukuje wszystkie procesy i info
	PCB* gethandle(int id);//Nawet nie pamietam po o to tu jest
	char* getstate(int el);//to tez nie...
	void PrintProcessState(int id, bool flag);
private:
	PamiecOperiWirt* Memory;
	static int IdentGen;
	
};

