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
	//ustawiam w�tek na oczekuj�cy i umieszczam w kolejce
	}

}

void Zamek::unlock()
{
	if(/*kolejka proces�w pusta*/)
	{
	zvalue = 0;
	}
	else
	{
		//bior� w�tek z kolejki proces�w oczekuj�cych i zmieniam jego stna na gotowy
	}
}


