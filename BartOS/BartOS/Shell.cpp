#include "stdafx.h"
#include "Shell.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;



Shell::Shell()
{
	
	
}


Shell::~Shell()
{
	
}
void Shell::UtworzZmiennaSrodowiskowa(string nazwa, string sciezka)
{
	ZmiennaSrodowiskowa *tmp = new ZmiennaSrodowiskowa(nazwa, sciezka);
	vector_zmiennych_srodowiskowych.push_back(*tmp);
}
void Shell::WykonujRozkaz(string rozkaz)
{
	
	if (rozkaz == "CL")			// clear - okienko shella sie czysci
	{
		system("CLS");	
	}
	else if (rozkaz == "LS")	 // wyswietl zawartosc folderu
	{

	}
	else if (rozkaz == "CF")	// create file
	{

	}
	else if (rozkaz == "DF")	 // delete file
	{

	}
	else if (rozkaz == "OF")	// open file
	{

	}
	else if (rozkaz == "CE")	// create folder
	{	

	}
	
	else if (rozkaz == "DE")	// delete folder
	{

	}
	else if (rozkaz == "VD")	// view disc
	{

	}
	
	else if (rozkaz == "VV")	// view virtual memory
	{

	}
	else if (rozkaz == "VP")	// view physical memory
	{

	}
	else if (rozkaz == "VT")	// view threads
	{

	}
	else if (rozkaz == "EX")	// execute
	{

	}
	else if (rozkaz == "EV")	// enviroment variable
	{

	}
	else if (rozkaz == "HE")	// help
	{
		
	}
	else
	{
		cout << "nieznana komenda, wpisz poprawna" << endl;
	}
	
}