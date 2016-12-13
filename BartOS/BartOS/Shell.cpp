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
	/*:thread_manager(pamiec)*/
{

	pamiec = new PamiecOperiWirt();

	hard_drive = HardDrive();
	parker = InterPeter();
	planista = ProcesoPriorytet();
}


Shell::~Shell()
{
	
}
void Shell::UtworzZmiennaSrodowiskowa()
{
	string komenda;
	cin >> komenda;
	if (komenda == "ex")
	{
		cout << "cos";
	}
}
void PokazKursor(string znak_kursora=">>> ")
{
	cout << znak_kursora;
}
vector<string> Shell::ZczytajRozkaz()
{
	cout << "chuj";
	string linia;
	string rozkaz;
	vector<string> komendy;
	getline(cin, linia);
	
	string delimiter = " ";
	size_t pozycja = 0;
	
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
		cout << komendy[0] << endl;
		WykonujRozkaz(komendy[0], komendy);
	}
}
void Shell::WykonujRozkaz(string rozkaz, vector<string> komendy)
{
	

	if (rozkaz == "CL")			// clear - okienko shella sie czysci
	{
		system("CLS");	
	}
	else if (rozkaz == "LS")	 // wyswietl zawartosc folderu
	{
		cout << "wyswietlam";
		//dysk.ViewFile();
	}
	else if (rozkaz == "CF")	// create file
	{
		//cout << "wchodze";
		hard_drive.create_file(komendy[1]);
		//cout << "/" << komendy[1] << "/";
		hard_drive.view_files();
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
		hard_drive.view_harddrive();
	}
	else if (rozkaz == "VV")	// view virtual memory
	{
		cout << "VVVVVVVHitler" << endl;
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
		cout << "EX" << endl;
		//thread_manager.CreateProcess("First", 69);
		parker.CommandDisplay(planista.FindReadyThread(), *pamiec);
		// 1) zlecam zarzadcy procesow stworzyc proces
		// 2) zlecam pamieciowcowi wprowadzic program do pamieci (zaladownie stronic danymi)
		
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
		cout << "No hope left *noose tightening* " << endl;
	}
	else
	{
		cout << "nieznana komenda, wpisz poprawna" << endl;
	}
	
}

void funkcja()
{
	
}
int main()
{
	vector<string>komendy;
	cout << "cos";


	Shell *shell= new Shell();
	/*cout << "cos";*/
	while (1)
	{
		
		shell->ObsluzLinie(komendy);
		if (komendy[0] == "QT")
		{
			break;
		}
		komendy.clear();
		
	}
	
	return 0;
}








