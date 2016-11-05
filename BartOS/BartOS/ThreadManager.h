#pragma once
#include "PCB.h"
#include "PamiecOperiWirt.h"
#include <vector>
#define Average_Priority 4

std::vector<PCB*>AllProc;

class CThreadManager
{
public:
	CThreadManager(PamiecOperiWirt* Memory);
	~CThreadManager();
	PCB * Proc_Control_block;	
	void CreateProcess(char*name);
	
	static int IdentGen;
private:
	PamiecOperiWirt* Memory;
	std::vector<PCB*>::iterator ElementAt;
};

