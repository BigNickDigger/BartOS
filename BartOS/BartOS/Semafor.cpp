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
		//Dodaje w�tek do kolejki FIFO w�tk�w oczekuj�cych na podniesienie semafora
	}

}

void Semafor::signal()
{
	svalue++;
	if (svalue <= 0)
	{
		//Usuwam w�tek z kolejki w�tk�w oczekuj�cych
		//Wznawiam stan w�tku wakeup(P);
	}

}