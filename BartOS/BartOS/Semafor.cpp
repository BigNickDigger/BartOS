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

void Semafor::wait(int ID_procesu)
{
	svalue--;
	if (svalue < 0)
	{
		KPS.push(ID_procesu); //Dodaje w¹tek do kolejki FIFO w¹tków oczekuj¹cych na podniesienie semafora 
		//KPS.back(); //i wstrzymuje ten w¹tek (nie mam jeszcze funkcji do tego czekam a¿ ktoœ zrobi, tylko kto?????)
	}
}

void Semafor::signal()
{
	svalue++;
	if (svalue <= 0)
	{
		//KPS.front(); // wznawiam pierwszy oczekuj¹cy (nie mam jeszcze funkcji do tego czekam a¿ ktoœ zrobi, tylko kto?????)
		KPS.pop(); //i usuwam go z kolejki w¹tków oczekuj¹cych
		
	}
}