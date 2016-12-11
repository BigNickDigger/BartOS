#pragma once
class PCB;
using namespace std;
#include<iostream>

class InterPeter
{
	int regA, regB, regC;
	int PC;
	int Adr;
	int AdrPREV;

public:
	InterPeter();
	~InterPeter();
	void SaveState(PCB* block);
	void LoadState(PCB* block);
	void ExecuteCommand(PCB* &block);
	std::string LoadCommand(int &adress, int f);
	void Interface();
	void RegisterDisplay();
	void CommandDisplay();




};

