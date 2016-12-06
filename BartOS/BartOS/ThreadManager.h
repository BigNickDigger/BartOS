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
	static int IdentGen;
	void RemoveProcess(int id);
	std::vector<PCB*>AllProc;
	void PrintProcesses();
	PCB* gethandle(int id);
	char* getstate(int el);
private:
	PamiecOperiWirt* Memory;
	std::queue<PCB*>poot[2];
	
};

