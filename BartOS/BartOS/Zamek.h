#pragma once
class Zamek
{
private:
	bool zvalue;
public:
	void lock();
	void unlock();
	std::queue < int > KPZ; //kolejka w�tk�w oczekuj�cych
	//identyfikator(PID) w�tku kt�ry zajmuje zamek
	Zamek();
	~Zamek();
};

