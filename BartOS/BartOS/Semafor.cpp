#include "stdafx.h"
#include "Semafor.h"
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
		cout << "Semafor: Zmieniam stan procesu "<< ID_Procesu<<" na oczekujacy" << endl;
		KPS.push(ID_Procesu); //Dodaje w¹tek do kolejki FIFO w¹tków oczekuj¹cych na podniesienie semafora 
		
		
		for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++) 
		{
			
			if ((*ElementAt)->Process_ID == ID_Procesu)
			{
				(*ElementAt)->Process_State = 1; //zmieniam stan w¹tku na waiting
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
		cout << "Semafor: Zmieniam stan procesu "<<KPS.front()<<" na gotowy"<<endl;
		KPS.front(); // wznawiam pierwszy oczekuj¹cy 
		for (ElementAt = AllProc->begin(); ElementAt != AllProc->end(); ElementAt++)
		{
			if ((*ElementAt)->Process_ID == KPS.front())
			{
				(*ElementAt)->Process_State = 2;
				break;
			}
		}
		KPS.pop(); //i usuwam go z kolejki w¹tków oczekuj¹cych
	}
}
