#pragma once
#include "PCB.h"
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
	std::vector<PCB*>AllProc;
private:
	PamiecOperiWirt* Memory;
	
	
};

