#pragma once
class Semafor
{
private:
	int svalue;
public:
	//Kolejka FIFO procesów oczekujących na podniesienie semafora
	void wait();	// operacja P
	void signal();	// operacja  V
	Semafor();
	~Semafor();
};

