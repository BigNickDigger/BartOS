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
		//dodanie do kolejki FIFO procesów oczekuj¹cych
		//wstrzymanie procesu block();
	}

}

void Semafor::signal()
{
	svalue++;
	if (svalue <= 0)
	{
		//bierzemy proces z kolejki FIFO
		//wznawiamy proces wakeup();

	}

}