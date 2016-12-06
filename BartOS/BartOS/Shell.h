#pragma once
#include "ZmiennaSrodowiskowa.h"
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
	void WykonujRozkaz(std::string rozkaz, std::vector<std::string> komendy);
	//void UtworzZmiennaSrodowiskowa(std::string nazwa, std::string sciezka);
	std::vector<std::string> ZczytajRozkaz();
	void ObsluzLinie(std::vector<std::string> &komendy/*, Dysk &dysk*, ThreadManager thread_manager()*/);
};





