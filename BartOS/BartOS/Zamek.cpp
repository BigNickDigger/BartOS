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
		KPZ.push(ID_procesu); // umieszam w¹tek w kolejsce 
		//KPZ.back(); i zmieniam  jego stan na oczekuj¹cy (nie mam jeszcze funkcji do tego czekam a¿ ktoœ zrobi, tylko kto?????)
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

		{	//KPZ.front(); // zmieniam stan w¹tku na gotowy (nie mam jeszcze funkcji do tego czekam a¿ ktoœ zrobi, tylko kto?????)
			KPZ.pop();//i biorê go z kolejki w¹tków oczekuj¹cych
			this->ID_procesu = ID_procesu;

		}
	}
}


