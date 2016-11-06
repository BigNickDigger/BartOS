#pragma once
#include "PCB.h"
#include "PamiecOperiWirt.h"
#include <vector>
#define Average_Priority 4



class CThreadManager
{
public:
	CThreadManager(PamiecOperiWirt* Memory);
	~CThreadManager();
	PCB * Proc_Control_block;
	void CreateProcess(char*name);
	static int IdentGen;
	std::vector<PCB*>AllProc;
private:
	PamiecOperiWirt* Memory;
	
	
};

