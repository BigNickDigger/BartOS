#pragma once
#include "PCB.h"
#include "PamiecOperiWirt.h"
#define Average_Priority 7
class CThreadManager
{
public:
	CThreadManager(PamiecOperiWirt* Memory, char *name);
	~CThreadManager();
	PCB * Proc_Control_block;
	void fork(char*name);
	void request_memory();
	static int IdentGen;
private:
	

};

