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

void Zamek::lock()
{
	if (zvalue == 0)
	{
		zvalue = 1;
	}
	else
	{
		KPZ.push(0); // umieszam w�tek w kolejsce 
		//KPZ.back(); i zmieniam  jego stan na oczekuj�cy
	}
}

void Zamek::unlock()
{
	if (KPZ.empty())
	{
		zvalue = 0;
	}
	else

	{	//KPZ.front(); // zmieniam stan w�tku na gotowy
		KPZ.pop();//i bior� go z kolejki w�tk�w oczekuj�cych
	
	}
}


