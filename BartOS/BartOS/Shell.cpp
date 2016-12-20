#include "stdafx.h"
#include "Shell.h"




using namespace std;



Shell::Shell()	:hard_drive(),parker(),planista(),pamiec()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31 );
//	pamiec = new PamiecOperiWirt();	
/*	hard_drive = HardDrive();
	parker = InterPeter();
	planista = ProcesoPriorytet();*/
	thread_manager = new CThreadManager(&pamiec, &planista);
	pamiec.Set_PCB_Vector(thread_manager->AllProc);
	komuch = new KomunikacjaProcesowa(&thread_manager->AllProc, &pamiec);
	hard_drive.create_file("p1");
	hard_drive.write_to_file_from_file("p1", "p1.txt");
	hard_drive.create_file("t2");
	hard_drive.write_to_file_from_file("t2", "t2.txt");
	hard_drive.create_file("gab");
	hard_drive.write_to_file_from_file("gab", "procesy.txt");
	hard_drive.create_file("droc2");
	hard_drive.write_to_file_from_file("droc2", "procesy2.txt");
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
		if (komendy.size() == 2)
		{
			hard_drive.create_file(komendy[1]);
		}
		else
		{
			cout << "brak argumentow" << endl;
		}
	}
	else if (rozkaz == "DF")	 // delete file
	{
		if (komendy.size() == 2)
		{
			hard_drive.delete_file(komendy[1]);
		}
		else
		{
			cout << "brak argumentow" << endl;
		}

	}
	else if (rozkaz == "OF")	// open file
	{
		if (komendy.size() == 2)
		{
			hard_drive.open_file(komendy[1]);
		}
		else
		{
			cout << "brak argumentow" << endl;
		}
	}
	else if (rozkaz == "WF")	// write to file
	{	
		if (komendy.size() == 3)
		{
			hard_drive.write_to_file(komendy[1], komendy[2]);
		}
		else
		{
			cout << "brak argumentow" << endl;
		}
	}
	else if (rozkaz == "VS")	// view sector 
	{
		if (komendy.size() == 2)
		{
			hard_drive.view_sector(stoi(komendy[1]));
		}
		else
		{
			cout << "brak argumentow" << endl;
		}
	}
	else if (rozkaz == "VH")	// view hard drive
	{
		hard_drive.view_harddrive();
	}
	else if (rozkaz == "FS")	// file size
	{
		if (komendy.size() == 2)
		{
			hard_drive.file_size(komendy[1]);
		}
		else
		{
			cout << "brak argumentow" << endl;
		}
	}
	else if (rozkaz == "FP")	// file propertise
	{
		if (komendy.size() == 2)
		{
			hard_drive.view_file_propertise(komendy[1]);
		}
		else
		{
			cout << "brak argumentow" << endl;
		}
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
		if (komendy.size()==3)
		{
			//cout << "Dodano proces" << endl;
			int k = thread_manager->makeprocess(komendy[2], stoi(komendy[1]));
			pamiec.Insert_To_Virtual_Memory(thread_manager->gethandle(k), hard_drive.open_file(komendy[2]), hard_drive.file_size(komendy[2]));
		
		}
		else
		{
			cout << "brak argumentow" << endl;
		}
		
	}
	else if (rozkaz == "PS") // process state
	{
		if (komendy.size() == 2)
		{
		thread_manager->PrintProcessState(stoi(komendy[1]),true);
		}
		else
		{
			cout << "brak argumentow" << endl;
		}
	}
	else if (rozkaz == "RP") // remove process
	{
		if (komendy.size() == 2)
		{
			//thread_manager->setstate(stoi(komendy[1]), PCB::Proc_Terminated);
			thread_manager->RemoveProcess(stoi(komendy[1]));
		}
		else
		{
			cout << "brak argumentow" << endl;
		}
		
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
		if (komendy.size() == 2)
		{
			komuch->ShowMessages(stoi(komendy[1]));
		}
		else
		{
			cout << "brak argumentow" << endl;
		}
	}
	else if (rozkaz == "XS")  // wyslij wiadomosc 
	{

		if (komendy.size() == 2)
		{
			thread_manager->PrintProcessState(stoi(komendy[1]), true);
			string wiadomosc;
			cout << "wpisz tresc wiadomosci"<<endl;
			getline(cin, wiadomosc);
			komuch->Send(stoi(komendy[1]), wiadomosc);
		}
		else
		{
			cout << "brak argumentow" << endl;
		}
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
		parker.Interface(tmp, pamiec);

		planista.tick_processes();
	}
	else if (rozkaz == "DP")	// help
	{
		//cout << "No hope left *noose tightening* " << endl;
		if (komendy.size() == 2)
		{
			pamiec.DeleteProcess(thread_manager->gethandle(stoi(komendy[1])));
			thread_manager->RemoveProcess(stoi(komendy[1]),true);
		}
		else
		{
			cout << "brak argumentow" << endl;
		}
	}
	else
	{
		cout << "nieznana komenda, wpisz poprawna" << endl;
	}
	
}

int main()
{
	Intro *intro = new Intro();
	intro->start();

	vector<string>komendy;
	

	Shell *shell = new Shell();
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








