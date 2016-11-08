#include "stdafx.h"
#include "Semafor.h"
#include <queue>

Semafor::Semafor()
{
	svalue = 1;
}

Semafor::~Semafor()
{
}

void Semafor::wait(/*PID*/)
{
	svalue--;
	if (svalue < 0)
	{
		KPS.push(0); //Dodaje w�tek do kolejki FIFO w�tk�w oczekuj�cych na podniesienie semafora 
		//KPS.back(); //i wstrzymuje ten w�tek
	}
}

void Semafor::signal()
{
	svalue++;
	if (svalue <= 0)
	{
		//KPS.front(); // wznawiam pierwszy oczekuj�cy
		KPS.pop(); //i usuwam go z kolejki w�tk�w oczekuj�cych
		
	}
}