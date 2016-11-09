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
	PCB * Proc_Control_block;
	void CreateProcess(char*name, int sopic);
	static int IdentGen;
	void RemoveProcess(int id);
	std::vector<PCB*>AllProc;
	void PrintProcesses();
	char* getstate(int el);
private:
	PamiecOperiWirt* Memory;
	
	
};

