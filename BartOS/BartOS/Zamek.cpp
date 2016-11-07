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
		//zmieniam stan w¹tku na oczekuj¹cy i umieszam go w kolejsce "queue < TYP_DANYCH > nazwa_kolejki;"
	}
}

void Zamek::unlock()
{
	if (1/*kolejka w¹tków jest pusta*/)
	{
		zvalue = 0;
	}
	else
	{
		//biorê w¹tek z kolejki w¹tków oczekuj¹cych i zmieniam jego stan na gotowy
	}
}


