#include "stdafx.h"
#include "Shell.h"
#include <vector>
#include <iostream>
#include <string>
#include <direct.h>
#include <stdio.h>
#include <conio.h>

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
	if (komendy[0] != "QT")
	{
		WykonujRozkaz(komendy[0], komendy);
	}
}
void Shell::WykonujRozkaz(string rozkaz, vector<string> komendy/*, Dysk &dysk*, ThreadManager thread_manager()*/)
{
	
	if (rozkaz == "CL")			// clear - okienko shella sie czysci
	{
		system("CLS");	
	}
	else if (rozkaz == "LS")	 // wyswietl zawartosc folderu
	{
		//dysk.ViewFile();
	}
	else if (rozkaz == "CF")	// create file
	{
		//dysk.CreateFile(komendy[1]);
	}
	else if (rozkaz == "DF")	 // delete file
	{
		//dysk.DeleteFile(komendy[1]);
	}
	else if (rozkaz == "OF")	// open file
	{
		//dysk.OpenFile(komendy[1]);
	}
	else if (rozkaz == "CE")	// create folder
	{	
		//dysk.CreateFolder(komendy[1])	;
	}
	
	else if (rozkaz == "DE")	// delete folder
	{
		//dysk.DeleteFolder(komendy[1]);
	}
	else if (rozkaz == "VD")	// view disc
	{
		//dysk.ViewDisc();
	}
	else if (rozkaz == "VV")	// view virtual memory
	{
		//thread_manager.Memory->PrintWM();
	}
	else if (rozkaz == "VP")	// view physical memory
	{
		//thread_manager.Memory->PrintOM();
	}
	else if (rozkaz == "VT")	// view threads
	{
		//thread_manager.PrintProcesses();
	}
	else if (rozkaz == "EX")	// execute
	{
		// 1) zlecam zarzadcy procesow stworzyc proces
		// 2) zlecam pamieciowcowi wprowadzic program do pamieci (zaladownie stronic danymi)
		// 3) zlecam wykonanie pojedynczego rozkazu interpreterowi Assemblera
	}
	else if (rozkaz == "C0")
	{
		//wykonaj nastepny rozkaz assemblera
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
	//PamiecOperiWirt pamiec = new PawmiecOperiWirt();
	//ThreadManager *thread_manager = new ThreadManager(pamiec);
	//Dysk dysk = new Dysk();

	Shell *shell= new Shell();
	
	while (1)
	{
		shell->ObsluzLinie(komendy/*,dysk,thread_manager*/);
		if (komendy[0] == "QT")
		{
			break;
		}
		komendy.clear();
		
	}
	cout << "Shutting down...";
	
	return 0;
}








