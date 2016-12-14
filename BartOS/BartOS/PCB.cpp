#include "stdafx.h"
#include "PCB.h"
#include "KomunikacjaProcesowa.h"
#include <vector>
PCB::PCB()
{
	RegA = RegB = RegC = RegD = ProgramCounter = 0;
	sem = new Semafor(0);
	orders_realized = 0;
	idleTime = 0;
	sopic = 0;
	//pages = new stronice[(sopic / 16)+1];
}


PCB::~PCB()
{
}
