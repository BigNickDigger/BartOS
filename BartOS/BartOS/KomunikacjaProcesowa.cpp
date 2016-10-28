#include "stdafx.h"
#include "KomunikacjaProcesowa.h"
#include "PCB.h"
#include <queue>
//Help
//KRZYSIU TO PIZDA H3H3 
KomunikacjaProcesowa::KomunikacjaProcesowa()
{
}


KomunikacjaProcesowa::~KomunikacjaProcesowa()
{
}

void KomunikacjaProcesowa::Nadaj(int Nadawca, int Odbiorca, char *tresc)
{
	/*szukanie odbiorcy
	if(Lista->Proces.ID==Odbiorca)
	Mess x;
	x.nadawca=Nadawca;
	x.odbiorca=odbiorca;
	x.tresc=tresc;
	Lista->Proces.queue.push<x>;
	else
	   Lista=Lista->next;




	   Jak nie znajdzie error (pytanie jak errora wyjebac?)
	*/

}

/*Mess KomunikacjaProcesowa::Odbierz(int Odbiorca)
{
	szukanie skrzynki
	if(Lista->Prcoes.ID==Odbiorca)
	{
	Lista->Proces.queue.;
	Mess x;

	x.nadawca=Lista->Proces.queue.front.nadawca;
	x.odbiorca=Lista->Proces.queue.front.odbiorca;
	x.tresc=Lista->Proces.queue.front.tresc;
	}
	else
	Lista=Lista->next;



	return x;
	Jak nie znajdzie error (pytanie jak errora wyjebac?)
	
}*/


/*    push - umieszczenie nowego elementu na koñcu kolejki;
pop - usuniêcie istniej¹cego elementu z pocz¹tku kolejki;
empty - informacja czy kolejka jest pusta;
size - zwraca iloœæ elementów umieszczonych w kolejce;
front - zwraca wartoœæ pierwszego elementu w kolejce.
back - zwraca wartoœæ ostatniego elementu w kolejce.
*/