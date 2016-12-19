#include "stdafx.h"
#include "PCB.h"
#include "KomunikacjaProcesowa.h"
#include <vector>
PCB::PCB()
{
	sleep = 0;
	RegA = RegB = RegC = RegD = ProgramCounter = 0;
	sem = new Semafor(0);
	orders_realized = 0;
	idleTime = 0;
	sopic = 0;
	for (int i = 0; i < 16; i++) {
		pages[i].Valid = false;
		pages[i].cell = -1;
	}
	//pages = new stronice[(sopic / 16)+1];
}


PCB::~PCB()
{
}
