#pragma once
class PCB;
class stronice;
class page;
#ifndef PAMIECPOERIWIRT_H
#define PAMIECPOERIWIRT_H

class page;
#include <iostream>
#include <vector>
#include <deque>
#include "PCB.h"


using namespace std;

const int framesize = 16;
const int OMsize = 64;

class page {
public:
	char tab[framesize];
	int nr;
	bool abandon;
	page()
	{
		for (int i = 0; i < framesize; i++)
		{
			tab[i] = '-';
			abandon = false;//nowe strony nie s� stronami zombie
		}
	}

	void PrintPage()
	{
		for (int i = 0; i < framesize; i++)
		{
			cout << tab[i] << " ";
		}
		cout << endl;
	}
	void Clear()
	{
		for (int i = 0; i < framesize; i++)
		{
			tab[i] = '-';
		}
	}

};

class PamiecOperiWirt
{
public:
	PamiecOperiWirt();
	~PamiecOperiWirt();
	int OM_Next_Frame_Victim;
	char OM[OMsize];
	vector <page*> VM;
	vector <page*>::iterator VMiter;
	deque <int> FIFO;
	vector<PCB*> AllProc;
	vector <PCB*>::iterator iter;


	int IndexforWM;
	int FIFOindex;

	char Get_Char_From_OM(PCB *blok, int LogicAdr);//mechanizm obs�ugi stronicowania na ��danie, zwraca 1 char dla danego procesu
	void Get_Page_From_WM(PCB* blok, int page);
	void Insert_To_Virtual_Memory(PCB *blok, char*, int sopic);//wrzuc do pamieci wirtualnej i ustawiaj w pcb TabliceStron
	int Get_Free_Frame_Number();
	int Return_ID_of_a_Process_using_this_frame(int FrameNr);
	int Return_nr_of_a_page_using_this_frame(int FrameNr);

	int WhichPage(short int); //MMU; do przeliczania adresu logicznego na fizyczny
	int WhatOffset(short int);  //MMU; -||-

	void save_message(string message);

	void DeleteProcess(PCB *blok);
	void PrintOM();
	void PrintVM();//do wypisania pamieci wirtualnej potrzebna jest lista przechowujaca wszystkie procesy
	void Update_Overide(int, int);
	void Set_PCB_Vector(vector<PCB*> &AllProc);
	void Print_Page_Table(int ID);

	bool message_is_in_OM(string);
};

#endif // !PAMIECPOERIWIRT_H