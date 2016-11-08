#include "stdafx.h"
#include "Semafor.h"
#include "PCB.h"
#include <queue>
#include <vector>

Semafor::Semafor()
{
	SValue = 1;
	std::vector <PCB*>*AllProcc;
	AllProc = AllProcc;
}

Semafor::~Semafor()
{
}

void Semafor::Wait(int ID_Procesu)
{
	SValue--;
	if (SValue < 0)
	{
		KPS.push(ID_Procesu); //Dodaje w¹tek do kolejki FIFO w¹tków oczekuj¹cych na podniesienie semafora 
		//zmieniam stan w¹tku na waiting
		int Licznik = 0;
		for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++) 
		{
			
			if (ElementAt[Licznik]->Process_ID == ID_Procesu)
			{
				ElementAt[Licznik]->Process_State = 1;
				break;
			}
			else
			{
				Licznik++;
			}
			
		}
	}
}

void Semafor::Signal()
{
	SValue++;
	if (SValue <= 0)
	{
		//KPS.front(); // wznawiam pierwszy oczekuj¹cy (nie mam jeszcze funkcji do tego czekam a¿ ktoœ zrobi, tylko kto?????)
		int Licznik=0;
		for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
		{

			if (ElementAt[Licznik]->Process_ID == KPS.front())
			{
				ElementAt[Licznik]->Process_State = 2;
				break;
			}
			else
			{
				Licznik++;
			}

		}
		KPS.pop(); //i usuwam go z kolejki w¹tków oczekuj¹cych
		
	}
}