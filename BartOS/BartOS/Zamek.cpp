
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
		cout << "Proces " << this->ID_procesu<< " zamknal zamek" << endl;
	}
	else
	{
		cout << "Zamek zamkniety: Zmieniam stan procesu " <<ID_procesu<< " na oczekujacy"<<endl; // zmieniam stan w¹tku na waiting
		KPZ.push(ID_procesu); // umieszam w¹tek w kolejsce 
		tm->setstate(KPZ.back(), PCB::Proc_Waiting);
		
	}
}

void Zamek::unlock(int ID_procesu)
{
	if (this->ID_procesu == ID_procesu)
	{
		if (KPZ.empty())
		{
			zvalue = 0;
			cout << "Zamek jest otwarty" << endl;
		}
		else
		{	
			cout << "Zamek otwarty: Zmieniam stan procesu "<<KPZ.front()<<" na gotowy"<<endl; //zmieniam stan w¹tku na ready
			tm->setstate(KPZ.front(), PCB::Proc_Ready);
			KPZ.pop();//i biorê go z kolejki w¹tków oczekuj¹cych
			this->ID_procesu = ID_procesu;
		}
	}
}

void Zamek::InitZamek(CThreadManager *TM) {
	tm = TM;
}