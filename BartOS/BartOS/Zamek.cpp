#include "stdafx.h"
#include "Zamek.h"


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
		//zmieniam stan w�tku na oczekuj�cy i umieszam go w kolejsce "queue < TYP_DANYCH > nazwa_kolejki;"
	}
}

void Zamek::unlock()
{
	if (1/*kolejka w�tk�w jest pusta*/)
	{
		zvalue = 0;
	}
	else
	{
		//bior� w�tek z kolejki w�tk�w oczekuj�cych i zmieniam jego stan na gotowy
	}
}


