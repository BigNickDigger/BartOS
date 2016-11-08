#include "stdafx.h"
#include "Shell.h"
#include <vector>
#include <iostream>
#include <string>
#include <direct.h>

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
void PokazKursor(string znak_kursora=">>> ")
{
	cout << znak_kursora;
}
vector<string> ZczytajRozkaz()
{
	vector<string> komenda;
	string slowo;
	while (cin >> slowo)
	{
		komenda.push_back(slowo);
	}
	return komenda;
}
void ObsluzLinie()
{
	vector<string> komenda;
	PokazKursor();
	komenda=ZczytajRozkaz();
	for (vector<string>::iterator it = komenda.begin(); it != komenda.end(); ++it)
	{
		cout << *it;
	}
	cout << endl;
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
int main()
{
	Shell shell();
	ObsluzLinie();
	system("pause");
	return 0;
}