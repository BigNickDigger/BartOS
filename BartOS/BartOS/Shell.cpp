#include "stdafx.h"
#include "Shell.h"


#include <vector>
#include <iostream>
#include <string>
#include <direct.h>
#include <stdio.h>
#include <conio.h>

using namespace std;



Shell::Shell()	:hard_drive(),parker(),planista(),pamiec()
{

//	pamiec = new PamiecOperiWirt();	
/*	hard_drive = HardDrive();
	parker = InterPeter();
	planista = ProcesoPriorytet();*/
	thread_manager = new CThreadManager(&pamiec, &planista);
	pamiec.Set_PCB_Vector(thread_manager->AllProc);
	komuch = new KomunikacjaProcesowa(&thread_manager->AllProc);
	hard_drive.create_file("p1");
	hard_drive.write_to_file_from_file("p1", "p1.txt.txt");
}


Shell::~Shell()
{
	
}
void Shell::UtworzZmiennaSrodowiskowa()
{
	string komenda;
	cin >> komenda;
	
}
void PokazKursor(string znak_kursora=">>> ")
{
	cout << znak_kursora;
}
vector<string> Shell::ZczytajRozkaz()
{
	pamiec.Set_PCB_Vector(thread_manager->AllProc);
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
		//cout << komendy[0] << endl;
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
		hard_drive.create_file("p1");
		hard_drive.write_to_file_from_file("p1", "p1.txt.txt");
		//dysk.CreateFolder(komendy[1])	;
	}
	
	else if (rozkaz == "DE")	// delete folder
	{
		for (int i = 0; i < 6;i++)
		planista.tick_processes();
		cout << (planista.FindReadyThread()->nazwa) << endl;
		//dysk.DeleteFolder(komendy[1]);
	}
	else if (rozkaz == "VD")	// view disc
	{
		hard_drive.view_harddrive();
	}
	else if (rozkaz == "CP") {//child pr0n
		cout << "Dodano proces" << endl;
		int k = thread_manager->CreateProcess("TEST", stoi(komendy[1]));
		
		pamiec.Insert_To_Virtual_Memory(thread_manager->gethandle(k), hard_drive.open_file("p1"), hard_drive.file_size("p1"));
	}
	else if (rozkaz == "PP")	// view disc
	{
		//thread_manager->setstate(3, PCB::Proc_Waiting);
		planista.printMyBeautifulStructurePlease();
	}
	else if (rozkaz == "VV")	// view virtual memory
	{
		pamiec.PrintVM();
	}
	else if (rozkaz == "VP")	// view physical memory
	{
		//Dwa ponizsze testowo
		//thread_manager.Memory->PrintOM();
	}
	else if (rozkaz == "SS") {//ustaw stan
		thread_manager->setstate(stoi(komendy[1]), PCB::Proc_Terminated);
	}
	else if (rozkaz == "RT") {
		thread_manager->setstate(stoi(komendy[1]), PCB::Proc_Terminated);
		thread_manager->RemoveProcess(stoi(komendy[1]));
	}
	else if (rozkaz == "VT")	// view threads
	{
		thread_manager->PrintProcesses();
	}
	else if (rozkaz == "ST")	// step
	{
		
		//thread_manager.CreateProcess("First", 69);
		//parker.CommandDisplay(planista.FindReadyThread(), *pamiec);
		PCB *tmp = planista.FindReadyThread();
		parker.ExecuteCommand(tmp, pamiec, komuch, hard_drive);
		parker.Interface(planista.FindReadyThread(), pamiec);
		// 1) zlecam zarzadcy procesow stworzyc proces
		// 2) zlecam pamieciowcowi wprowadzic program do pamieci (zaladownie stronic danymi)
		planista.tick_processes();
	}
	else if (rozkaz == "C0")
	{

		//wykonaj nastepny rozkaz assemblera
	}
	else if (rozkaz == "EV")	// enviroment variable
	{
		pamiec.PrintOM();
	}
	else if (rozkaz == "SM") {
		komuch->Send(stoi(komendy[1]), "this sucks");
	}
	else if (rozkaz == "RM") {
		//komuch->ShowMessages()
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

int main()
{


	vector<string>komendy;
	
	vector<vector<int*>>v;
	int a = 10;

	for (int i = 0; i < 3;i++)
	{
		vector <int*> z;
		v.push_back(z);
		for (int j = 0; j < 3; j++)
		{
			v[i].push_back(&a);
			
		}
	}

	for (int i = 0; i < 3;i++)
	{
		for (auto j : v[i])
		{
			cout << *j << " " << j << endl;
		}
	}


	Shell *shell = new Shell();
	/*shell->thread_manager->CreateProcess("IDLE", 13);
	shell->thread_manager->AllProc[0]->Priority = 0;
	shell->thread_manager->AllProc[0]->Process_State = PCB::Proc_Ready;
	shell->planista.addProcess(shell->thread_manager->gethandle(0));*/
	while (1)
	{
		
		shell->ObsluzLinie(komendy);
		if (komendy[0] == "QT")
		{
			break;
		}
		komendy.clear();
	}
	cout << "Shutting down...";
	
	return 0;
}








