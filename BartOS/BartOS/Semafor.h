#pragma once

#ifndef SEMAFOR_H
#define SEMAFOR_H
#include "PCB.h"

/*Olaf Bergmann mechanizmy synchronizacji*/

class Semafor
{
private:
	int SValue;

	std::vector<PCB*>::iterator ElementAt;
public:
	std::queue < int > KPS; //Przechowuje ID procesu
	void Wait(int ID_procesu);	// operacja P 
	void Signal();	// operacja  V
	Semafor(int WPS);
	~Semafor();
	std::vector <PCB*>*AllProc;
};

#endif // !SEMAFOR_H