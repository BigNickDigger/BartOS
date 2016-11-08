#pragma once
#include <queue>

class Zamek
{
private:
	bool zvalue;
public:
	void lock();
	void unlock();
	std::queue < int > KPZ; //kolejka w¹tków oczekuj¹cych
	int ID_procesu;
	Zamek();
	~Zamek();
};

