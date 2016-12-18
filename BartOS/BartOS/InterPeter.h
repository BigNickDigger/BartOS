#pragma once

#include "ThreadManager.h"
#include "PamiecOperiWirt.h"
#include "KomunikacjaProcesowa.h"
#include "SystemPlikowFAT.h"



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
	void ExecuteCommand(PCB* block, PamiecOperiWirt &pam, KomunikacjaProcesowa * kom, HardDrive &dysk);
	std::string LoadCommand(int &adress, int f, PCB *block, PamiecOperiWirt &pam);
	std::string LoadCommand(short int &adress, int f, PCB *block, PamiecOperiWirt &pam);
	void Interface(PCB *block, PamiecOperiWirt &pam);
	void RegisterDisplay();
	void CommandDisplay(PCB *block, PamiecOperiWirt &pam);




};

