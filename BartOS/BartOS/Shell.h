#pragma once
#include "ZmiennaSrodowiskowa.h"
#include "PamiecOperiWirt.h"
#include "ThreadManager.h"
#include "SystemPlikowFAT.h"
#include <string>
#include <iostream>
#include <string>
#include <vector>

class Shell
{
public:
	std::vector <ZmiennaSrodowiskowa> vector_zmiennych_srodowiskowych;
	Shell();
	~Shell();
	void WykonujRozkaz(std::string rozkaz, std::vector<std::string> komendy, HardDrive &hard_drive);
	//void UtworzZmiennaSrodowiskowa(std::string nazwa, std::string sciezka);
	std::vector<std::string> ZczytajRozkaz();
	void ObsluzLinie(std::vector<std::string> &komendy, HardDrive &hard_drive);
};





