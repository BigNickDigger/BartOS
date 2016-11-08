#include "stdafx.h"
#include "KomunikacjaProcesowa.h"
//#include <iostream>



//#include <vector>
using namespace std;

KomunikacjaProcesowa::KomunikacjaProcesowa()
{
	//AllProc = AlllProc;
}



KomunikacjaProcesowa::~KomunikacjaProcesowa()
{
}

void KomunikacjaProcesowa::Nadaj(int Nadawca, int Odbiorca, string tresc)
{
	//int counter = 0;
	//Mess x;
	//x.nadawca = Nadawca;
	//x.tresc = tresc;
	////szukanie odbiorcy
	////Magiczny for ktory przeszukuje liste prockow
	//for (xD = X->AllProc.begin(); xD != X->AllProc.end(); xD++)
	//{
	//	if (X->AllProc[counter]->Process_ID == Odbiorca)
	//	{

	//		X->AllProc[counter]->messages.push(x);
	//	}
	//	else
	//	counter++;
	//}
}

void KomunikacjaProcesowa::Odbierz(int Odbiorca)
{

	//Semafor::wait();
	//szukanie skrzynki
	//int counter = 0;
	//for (xD = X->AllProc.begin(); xD != X->AllProc.end(); xD++)
	//{
	//	if (X->AllProc[counter]->Process_ID == Odbiorca)
	//	{
	//		Mess x;
	//		x = X->AllProc[counter]->messages.front;
	//		X->AllProc[counter]->messages.pop;
	//
	//	}
	//	else
	//	{
	//		//Lista = Lista->next;
	//		counter++;
	//	}


		//return x;
		//Jak nie znajdzie error(pytanie jak errora wyjebac ? )
	//}
}


/*    push - umieszczenie nowego elementu na koñcu kolejki;
pop - usuniêcie istniej¹cego elementu z pocz¹tku kolejki;
empty - informacja czy kolejka jest pusta;
size - zwraca iloœæ elementów umieszczonych w kolejce;
front - zwraca wartoœæ pierwszego elementu w kolejce.
back - zwraca wartoœæ ostatniego elementu w kolejce.
*/