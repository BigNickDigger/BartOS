#include "stdafx.h"
#include "Semafor.h"
#include <queue>
#include <vector>
#include "ThreadManager.h"

/*Olaf Bergmann mechanizmy synchronizacji*/

Semafor::Semafor(int WPS) {
	SValue = WPS;
}

Semafor::~Semafor()
{
}

void Semafor::Wait(int ID_Procesu)
{
	SValue--;
	if (SValue < 0)
	{
		cout << "Semafor: Zmieniam stan procesu na oczekujacy" << endl;
		KPS.push(ID_Procesu); //Dodaje w�tek do kolejki FIFO w�tk�w oczekuj�cych na podniesienie semafora 
		//zmieniam stan w�tku na waiting
		
		for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++) 
		{
			
			if ((*ElementAt)->Process_ID == ID_Procesu)
			{
				(*ElementAt)->Process_State = 1;
				break;
			}
		}
	}
}

void Semafor::Signal()
{
	SValue++;
	if (SValue <= 0)
	{
		cout << "Semafor: Zmieniam stan procesu na gotowy"<<endl;
		KPS.front(); // wznawiam pierwszy oczekuj�cy 
		for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
		{
			if ((*ElementAt)->Process_ID == KPS.front())
			{
				(*ElementAt)->Process_State = 2;
				break;
			}
		}
		KPS.pop(); //i usuwam go z kolejki w�tk�w oczekuj�cych
	}
}
