#pragma once
#include <queue>

class Zamek
{
private:
	bool zvalue;
public:
	void lock();
	void unlock();
	std::queue < int > KPZ; //kolejka w�tk�w oczekuj�cych
	int ID_procesu;
	Zamek();
	~Zamek();
};

