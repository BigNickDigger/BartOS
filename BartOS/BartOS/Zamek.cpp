#include "stdafx.h"
#include "Zamek.h"
#include <queue>

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
		//KPZ.back(); i zmieniam  jego stan na oczekuj�cy (nie mam jeszcze funkcji do tego czekam a� kto� zrobi, tylko kto?????)
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

		{	//KPZ.front(); // zmieniam stan w�tku na gotowy (nie mam jeszcze funkcji do tego czekam a� kto� zrobi, tylko kto?????)
			KPZ.pop();//i bior� go z kolejki w�tk�w oczekuj�cych
			this->ID_procesu = ID_procesu;

		}
	}
}


