#pragma once

#ifndef SEMAFOR_H
#define SEMAFOR_H
#include "PCB.h"
class Semafor
{
private:
	int SValue;
	std::vector <PCB*>*AllProc;
	std::vector<PCB*>::iterator ElementAt;
public:
	std::queue < int > KPS; //Przechowuje ID procesu
	void Wait(int ID_procesu);	// operacja P 
	void Signal();	// operacja  V
	Semafor(std::vector <PCB*>*AllProcc);
	~Semafor();
};

#endif // !SEMAFOR_H