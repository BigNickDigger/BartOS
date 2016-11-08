#pragma once
class Zamek
{
private:
	bool zvalue;
public:
	void lock();
	void unlock();
	std::queue < int > KPZ; //kolejka w¹tków oczekuj¹cych
	//identyfikator(PID) w¹tku który zajmuje zamek
	Zamek();
	~Zamek();
};

