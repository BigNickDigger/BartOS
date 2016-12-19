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
	//////////////////////////////////////////////// DYSK //////////////////////////////////////////////
	else if (rozkaz == "LS")	 // wyswietl zawartosc folderu
	{
		hard_drive.view_files();
	}
	else if (rozkaz == "CF")	// create file
	{
		hard_drive.create_file(komendy[1]);
	}
	else if (rozkaz == "DF")	 // delete file
	{
		hard_drive.delete_file(komendy[1]);
	}
	else if (rozkaz == "OF")	// open file
	{
		hard_drive.open_file(komendy[1]);
	}
	else if (rozkaz == "WF")	// write to file
	{	
		hard_drive.write_to_file(komendy[1], komendy[2]);
	}
	else if (rozkaz == "VS")	// view sector 
	{
		hard_drive.view_sector(stoi(komendy[1]));
	}
	else if (rozkaz == "VH")	// view hard drive
	{
		hard_drive.view_harddrive();
	}
	else if (rozkaz == "FS")	// file size
	{
		hard_drive.file_size(komendy[1]);
	}
	else if (rozkaz == "FP")	// file propertise
	{
		hard_drive.view_file_propertise(komendy[1]);
	}
	else if (rozkaz == "VS")	// view free space
	{
		hard_drive.view_free_space();
	}
	//////////////////////////////////////////////// PLANISTA //////////////////////////////////////////////
	else if (rozkaz == "TP")	// tick processes
	{
		
		for (int i = 0; i < 6;i++)
		planista.tick_processes();
		cout << (planista.FindReadyThread()->nazwa) << endl;
		//dysk.DeleteFolder(komendy[1]);
	}
	else if (rozkaz == "PV")	// view disc
	{
		planista.printMyBeatufiulBitVectorPlease();
	}
	else if (rozkaz == "PP")	// view processes - planista
	{
		//thread_manager->setstate(3, PCB::Proc_Waiting);
		planista.printMyBeautifulStructurePlease();
	}
	//////////////////////////////////////////////// THREAD_MANAGER //////////////////////////////////////////////
	else if (rozkaz == "CP")	// create process
	{
		cout << "Dodano proces" << endl;
		int k = thread_manager->CreateProcess("TEST", stoi(komendy[1]));
		pamiec.Insert_To_Virtual_Memory(thread_manager->gethandle(k), hard_drive.open_file("p1"), hard_drive.file_size("p1"));
	}
	else if (rozkaz == "PS") // process state
	{
		thread_manager->PrintProcessState(stoi(komendy[1]),true);
	}
	else if (rozkaz == "RP") // remove process
	{
		//thread_manager->setstate(stoi(komendy[1]), PCB::Proc_Terminated);
		thread_manager->RemoveProcess(stoi(komendy[1]));
	}
	else if (rozkaz == "VT")	// view threads
	{
		thread_manager->PrintProcesses();
		
	}
	else if (rozkaz == "VT")	// view threads
	{
		thread_manager->PrintProcesses();

	}
	//////////////////////////////////////////////// PAMIEC //////////////////////////////////////////////
	else if (rozkaz == "VV")	// view virtual memory
	{
		pamiec.PrintVM();
	}
	else if (rozkaz == "VP")	// view physical memory
	{
		pamiec.PrintOM();
	}
	//////////////////////////////////////////////// KOMUNIKACJA //////////////////////////////////////////////
	else if (rozkaz == "SM") // show messages
	{
		komuch->ShowMessages(stoi(komendy[1]));
		
	}
	else if (rozkaz == "XS")  // wyslij wiadomosc 
	{
		string wiadomosc;
		cout << "wpisz tresc wiadomosci"<<endl;
		getline(cin, wiadomosc);
		komuch->Send(stoi(komendy[1]), wiadomosc);
	}
	else if (rozkaz == "XR") 
	{
		komuch->Receive();

	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	else if (rozkaz == "ST")	// step
	{


		PCB *tmp = planista.FindReadyThread();
		parker.ExecuteCommand(tmp, pamiec, komuch, hard_drive);
		parker.Interface(planista.FindReadyThread(), pamiec);

		planista.tick_processes();
	}
	else if (rozkaz == "DP")	// help
	{
		//cout << "No hope left *noose tightening* " << endl;
		pamiec.DeleteProcess(thread_manager->gethandle(stoi(komendy[1])));
		thread_manager->RemoveProcess(stoi(komendy[1]));
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








