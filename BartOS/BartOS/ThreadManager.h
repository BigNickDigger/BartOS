#pragma once
#include "PCB.h"
class CThreadManager
{
public:
	CThreadManager();
	~CThreadManager();
	PCB * Proc_Control_block;
	static int IdentGen;
private:
	char * pootis;

};

