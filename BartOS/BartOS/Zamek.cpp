
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

		KPZ.push(ID_procesu); // umieszam w¹tek w kolejsce 
		CThreadManager *d;
		d->setstate(ID_procesu, PCB::Proc_Terminated);
		delete d;
		//CThreadManager::setstate(ID_procesu, PCB::stan::Proc_Waiting);
		//KPZ.back();// i zmieniam  jego stan na oczekuj¹cy 
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
			//KPZ.front();// zmieniam stan w¹tku na gotowy 
			//CThreadManager::setstate(KPZ.front(), PCB::stan::Proc_Ready);
			KPZ.pop();//i biorê go z kolejki w¹tków oczekuj¹cych
			this->ID_procesu = ID_procesu;
		}
	}
}


