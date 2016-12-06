#pragma once
 
using namespace std;
#include<iostream>

class InterPeter
{
	int regA, regB, regC;
	int PC;

public:
	InterPeter();
	~InterPeter();
	void SaveState();
	void LoadState();
	void ExecuteCommand();
	std::string LoadCommand();
	void Interface();
	void RegisterDisplay();
	void CommandDisplay();




};

