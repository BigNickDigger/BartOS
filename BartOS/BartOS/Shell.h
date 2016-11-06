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
	void WykonujRozkaz(std::string rozkaz);
	void UtworzZmiennaSrodowiskowa(std::string nazwa, std::string sciezka);
};





