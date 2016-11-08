#pragma once
class Semafor
{
private:
	int svalue;
public:
	std::queue < int > KPS; //Przechowuje ID procesu
	void wait(int ID_procesu);	// operacja P
	void signal();	// operacja  V
	Semafor();
	~Semafor();
};

