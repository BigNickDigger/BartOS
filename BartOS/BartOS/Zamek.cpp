
#include "stdafx.h"
#include "Zamek.h"
#include <queue>
#include "ThreadManager.h"
#include "PCB.h"
/*Olaf Bergmann mechanizmy synchronizacji*/
Zamek::Zamek()
{
	zvalue = 0;
}

Zamek::~Zamek()
{
}

void Zamek::lock(int ID_procesu)
{
	
	if (zvalue == 0)
	{
		this->ID_procesu = ID_procesu;
		zvalue = 1;
	}
	else
	{

		KPZ.push(ID_procesu); // umieszam w�tek w kolejsce 
		CThreadManager *d;
		d->setstate(ID_procesu, PCB::Proc_Terminated);
		delete d;
		//CThreadManager::setstate(ID_procesu, PCB::stan::Proc_Waiting);
		//KPZ.back();// i zmieniam  jego stan na oczekuj�cy 
	}
}

void Zamek::unlock(int ID_procesu)
{
	if (this->ID_procesu == ID_procesu)
	{
		if (KPZ.empty())
		{
			zvalue = 0;
		}
		else
		{	
			//KPZ.front();// zmieniam stan w�tku na gotowy 
			//CThreadManager::setstate(KPZ.front(), PCB::stan::Proc_Ready);
			KPZ.pop();//i bior� go z kolejki w�tk�w oczekuj�cych
			this->ID_procesu = ID_procesu;
		}
	}
}


