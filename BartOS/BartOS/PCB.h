#pragma once

#include <stdio.h>
#include <vector>
#include <time.h>
#include <queue>
#include "KomunikacjaProcesowa.h"
struct stronice {
	bool Valid;
	short int cell;
};

class PCB
{
public:
	PCB();
	~PCB();
	char* nazwa;
	int Process_State,
		Process_ID;
	short int Priority,
		ProgramCounter;
	int RegA, RegB, RegC, RegD;
	stronice *pages;
	void RequestMemoryBegin(int &Memory_Begin);
	void RequestMemoryLimit(int &Memory_Limit);
	typedef enum//Stany Procesora
	{
		Proc_New, Proc_Waiting, Proc_Ready, Proc_Halted
	};
	std::queue<Mess>messages;
};

