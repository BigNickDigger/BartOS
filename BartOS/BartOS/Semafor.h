#pragma once

#ifndef SEMAFOR_H
#define SEMAFOR_H
#include "PCB.h"

/*Olaf Bergmann mechanizmy synchronizacji*/

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
	Semafor(int WPS, std::vector <PCB*>*AllProcc); //WPS - wartoœæ pocz¹tkowa semafora std::vector <PCB*>*AllProcc
	~Semafor();
};

#endif // !SEMAFOR_H