#pragma once
class Semafor
{
private:
	int svalue;
public:
	//Kolejka FIFO proces�w oczekuj�cych na podniesienie semafora "queue < TYP_DANYCH > nazwa_kolejki;"
	void wait();	// operacja P
	void signal();	// operacja  V
	Semafor();
	~Semafor();
};

