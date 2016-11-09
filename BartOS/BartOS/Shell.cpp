#include "stdafx.h"
#include "Shell.h"
#include <vector>
#include <iostream>
#include <string>
#include <direct.h>
#include <stdio.h>

using namespace std;



Shell::Shell()
{
	
	
}


Shell::~Shell()
{
	
}
//void Shell::UtworzZmiennaSrodowiskowa(string nazwa, string sciezka)
//{
//	ZmiennaSrodowiskowa *tmp = new ZmiennaSrodowiskowa(nazwa, sciezka);
//	vector_zmiennych_srodowiskowych.push_back(*tmp);
//}
void PokazKursor(string znak_kursora=">>> ")
{
	cout << znak_kursora;
}
vector<string> Shell::ZczytajRozkaz()
{
	string linia;
	string rozkaz;
	vector<string> komendy;
	getline(cin, linia);
	
	string delimiter = " ";
	size_t pozycja = 0;
	//cout << linia;
	//cout.flush();
	while ((pozycja = linia.find(delimiter)) != string::npos) 
	{
		rozkaz = linia.substr(0, pozycja);
		komendy.push_back(rozkaz);
		linia.erase(0, pozycja + delimiter.length());
	}
	komendy.push_back(linia);
	return komendy;
}
void Shell::ObsluzLinie(vector<string> &komendy)
{
	PokazKursor();
	
	komendy=ZczytajRozkaz();
	WykonujRozkaz(komendy[0],komendy);

	
}
void Shell::WykonujRozkaz(string rozkaz, vector<string> komendy)
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
		//
		if (komendy[1] == "plik.txt")
		{
			
		}
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

int main2()
{
	vector<string>komendy;
	Shell *shell= new Shell();
	shell->ObsluzLinie(komendy);
	while (komendy[1]!="QT")
	{
		shell->ObsluzLinie(komendy);




	}
	cout << "dobranoc";
	return 0;
}