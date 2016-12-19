#pragma once
class PamiecOperiWirt;
class page;
class Semafor;
#ifndef __PCB_H_INCLUDED	
#define __PCB_H__INCLUDED


#include <stdio.h>
#include <string>
#include <time.h>
#include <queue>
#include "PamiecOperiWirt.h"
#include "Semafor.h"

struct stronice {
	bool Valid;
	short int cell;
};

class PCB
{
public:
	PCB();
	~PCB();
	std::string nazwa;
	int Process_State,
		PriorityDynamic,
		Process_ID;
	short int Priority,
		ProgramCounter;
	int RegA, RegB, RegC, RegD;
	int sopic,//size of program in chars
		idleTime;
	int sleep; //potrzebne do wznowienia odbioru.

	int orders_realized;//wstawiam, bo potrzebuje do wznawiania przerwanych
	
	//stronice *pages; UWAGA WBIJAM NA KWADRAT ZE ZMIANAMI
	stronice pages[16];//uwa¿am ¿e tablica stronic ma rozmiar WMsize = 48
	//page str[3];
	typedef enum stan//Stany Procesora
	{
		Proc_New, Proc_Waiting, Proc_Ready, Proc_Terminated, Proc_Erroneous, Proc_Running
	};
	std::queue<std::string>messages;
	std::vector<PCB*>::iterator ElementAt;
	Semafor *sem;
	
};

#endif // !PCB_H