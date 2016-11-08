#pragma once
#include <queue>

class Zamek
{
private:
	bool zvalue;
public:
	void lock(int ID_procesu);
	void unlock(int ID_procesu);
	std::queue < int > KPZ; //kolejka w¹tków oczekuj¹cych
	int ID_procesu;
	Zamek();
	~Zamek();
};

