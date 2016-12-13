#pragma once
#include <queue>
/*Olaf Bergmann mechanizmy synchronizacji*/
class CThreadManager;
class Zamek
{
private:
	bool zvalue;
	CThreadManager *tm;
public:
	void lock(int ID_procesu);
	void unlock(int ID_procesu);
	std::queue < int > KPZ; //kolejka w¹tków oczekuj¹cych
	int ID_procesu;
	void InitZamek(CThreadManager *TM);
	Zamek();
	~Zamek();
};

