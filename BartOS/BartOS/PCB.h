#pragma once

#include <stdio.h>
#include <string>
#include <time.h>
#include <queue>
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
	int sopic;//size of program in chars

	int orders_realized;//wstawiam, bo potrzebuje do wznawiania przerwanych

	//stronice *pages; UWAGA WBIJAM NA KWADRAT ZE ZMIANAMI
	stronice pages[48];//uwa�am �e tablica stronic ma rozmiar WMsize = 48
	
	typedef enum//Stany Procesora
	{
		Proc_New, Proc_Waiting, Proc_Ready, Proc_Terminated, Proc_Erroneous
	};
	std::queue<std::string>messages;
	std::vector<PCB*>::iterator ElementAt;
};

