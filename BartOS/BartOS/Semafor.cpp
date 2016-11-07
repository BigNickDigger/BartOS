#include "stdafx.h"
#include "Semafor.h"


Semafor::Semafor()
{
	svalue = 1;
}


Semafor::~Semafor()
{
}

void Semafor::wait()
{
	svalue--;
	if (svalue < 0)
	{
		//wstrzymuje proces block();
		//Dodaje w¹tek do kolejki FIFO w¹tków oczekuj¹cych na podniesienie semafora
	}

}

void Semafor::signal()
{
	svalue++;
	if (svalue <= 0)
	{
		//Usuwam w¹tek z kolejki w¹tków oczekuj¹cych
		//Wznawiam stan w¹tku wakeup(P);
	}

}