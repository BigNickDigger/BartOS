#pragma once
struct Mess
{
	int nadawca;
	int odbiorca;
	char *tresc;
};

class KomunikacjaProcesowa
{
public:
	KomunikacjaProcesowa();
	~KomunikacjaProcesowa();
	void Nadaj(int, int, char*);
	Mess Odbierz(int);

};

/*    push - umieszczenie nowego elementu na koñcu kolejki;
    pop - usuniêcie istniej¹cego elementu z pocz¹tku kolejki;
    empty - informacja czy kolejka jest pusta;
    size - zwraca iloœæ elementów umieszczonych w kolejce;
    front - zwraca wartoœæ pierwszego elementu w kolejce.
    back - zwraca wartoœæ ostatniego elementu w kolejce.
	*/