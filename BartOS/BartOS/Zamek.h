#pragma once
class Zamek
{
private:
	bool zvalue;
public:
	void lock();
	void unlock();
	//identyfikator w�tku kt�ry zajmuje zamek
	//kolejka FIFO w�tk�w oczekuj�cych
	Zamek();
	~Zamek();
};

