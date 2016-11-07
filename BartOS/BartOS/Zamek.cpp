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
	//ustawiam w¹tek na oczekuj¹cy i umieszczam w kolejce
	}

}

void Zamek::unlock()
{
	if(/*kolejka procesów pusta*/)
	{
	zvalue = 0;
	}
	else
	{
		//biorê w¹tek z kolejki procesów oczekuj¹cych i zmieniam jego stna na gotowy
	}
}


