#include "stdafx.h"
#include "KomunikacjaProcesowa.h"
#include <iostream>
#include <queue>
//Help
using namespace std;
//KRZYSIU TO PIZDA Hx3H3 
KomunikacjaProcesowa::KomunikacjaProcesowa(CThreadManager &Y)
{
	X = &Y;
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

string KomunikacjaProcesowa::Odbierz(int Odbiorca)
{
	//szukanie skrzynki
	//int counter = 0;
	//for (xD = X->AllProc.begin(); xD != X->AllProc.end(); xD++)
	//{
	//	if (X->AllProc[counter]->Process_ID == Odbiorca)
	//	{
	//		Mess x;
	//		x = X->AllProc[counter]->messages.front;
	//		X->AllProc[counter]->messages.pop;
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


/*    push - umieszczenie nowego elementu na ko�cu kolejki;
pop - usuni�cie istniej�cego elementu z pocz�tku kolejki;
empty - informacja czy kolejka jest pusta;
size - zwraca ilo�� element�w umieszczonych w kolejce;
front - zwraca warto�� pierwszego elementu w kolejce.
back - zwraca warto�� ostatniego elementu w kolejce.
*/