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

/*    push - umieszczenie nowego elementu na ko�cu kolejki;
    pop - usuni�cie istniej�cego elementu z pocz�tku kolejki;
    empty - informacja czy kolejka jest pusta;
    size - zwraca ilo�� element�w umieszczonych w kolejce;
    front - zwraca warto�� pierwszego elementu w kolejce.
    back - zwraca warto�� ostatniego elementu w kolejce.
	*/