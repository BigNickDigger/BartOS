#pragma once
class Zamek
{
private:
	bool zvalue;
public:
	void lock();
	void unlock();
	//identyfikator w¹tku który zajmuje zamek
	//kolejka FIFO w¹tków oczekuj¹cych "queue < TYP_DANYCH > nazwa_kolejki;"
	Zamek();
	~Zamek();
};

