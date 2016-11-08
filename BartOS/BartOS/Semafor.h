#pragma once
class Semafor
{
private:
	int SValue;
	std::vector <PCB*>*AllProc;
	std::vector<PCB*>::iterator ElementAt;
public:
	std::queue < int > KPS; //Przechowuje ID procesu
	void Wait(int ID_procesu);	// operacja P
	void Signal();	// operacja  V
	Semafor();
	~Semafor();
};

