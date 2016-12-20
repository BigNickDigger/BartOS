#pragma once
#include "ZmiennaSrodowiskowa.h"
//#include "PamiecOperiWirt.h"
//#include "ThreadManager.h"
//#include "SystemPlikowFAT.h"
#include "ProcesoPriorytet.h"
#include "InterPeter.h"
#include "ProcesoPriorytet.h"
#include "Intro.h"
#include <iostream>
#include <string>
#include <vector>
#include <direct.h>
#include <stdio.h>
#include <conio.h>


class Shell
{
public:
	std::vector <ZmiennaSrodowiskowa> vector_zmiennych_srodowiskowych;
	PamiecOperiWirt pamiec;
	CThreadManager *thread_manager;
	HardDrive hard_drive;
	InterPeter parker;
	KomunikacjaProcesowa * komuch;
	ProcesoPriorytet planista;
	Shell();
	~Shell();
	void WykonujRozkaz(std::string rozkaz, std::vector<std::string> komendy);
	void UtworzZmiennaSrodowiskowa();
	std::vector<std::string> ZczytajRozkaz();
	void ObsluzLinie(std::vector<std::string> &komendy);
};





