#pragma once

#include <stdio.h>
class PCB
{
public:
	PCB();
	~PCB();
	char* nazwa;
	int Process_State,
		Process_ID, Process_Child_ID;
	short int Priority,
		ProgramCounter,
		MemoryBegin,
		MemoryLimit;
	bool IsParent;
	void RequestMemoryBegin(int &Memory_Begin);
	void RequestMemoryLimit(int &Memory_Limit);
	typedef enum//Stany Procesora
	{
		Proc_New, Proc_Waiting, Proc_Ready, Proc_Halted
	};
	FILE* plik;
};

