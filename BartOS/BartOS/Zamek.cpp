
#include "stdafx.h"
#include "Zamek.h"
#include <queue>
#include "ThreadManager.h"
//#include "PCB.h"
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
		cout << "Zamek: Zmieniam stan procesu " <<ID_procesu<< " na oczekujacy"<<endl;
		KPZ.push(ID_procesu); // umieszam w¹tek w kolejsce 
		/*
		CThreadManager *d;
		d->setstate(ID_procesu, PCB::Proc_Waiting); //  zmieniam  jego stan na oczekuj¹cy 
		delete d;
		*/
		//KPZ.back();
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
			cout << "Zamek: Zmieniam stan procesu "<<ID_procesu<<" na gotowy"<<endl;
			/*
			CThreadManager *d;
			d->setstate(KPZ.front(), PCB::Proc_Ready); // zmieniam stan w¹tku na gotowy 
			delete d;
			*/
			KPZ.pop();//i biorê go z kolejki w¹tków oczekuj¹cych
			this->ID_procesu = ID_procesu;
		}
	}
}


void Zamek::InitZamek(CThreadManager *TM) {
	tm = TM;
}