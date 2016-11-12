#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "PCB.h"

using namespace std;
//proszê siê nie sugerowac moimi rozwi¹zaniami, tu jeszcze wszystko mo¿e siê zmieniæ

const int framesize = 16;//rozmiar strony
const int OMsize = 128;

class page {
public:
	char tab[framesize];//framesize = 16
	int nr;
	bool abandon;
	page()
	{
		for (int i = 0; i < framesize; i++)
		{
			tab[i] = '-';
			abandon = false;
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
	queue <int> FIFO;
	
	int IndexforWM;
	int FIFOindex;

	char Get_Char_From_OM(PCB *blok, int LogicAdr);//mechanizm obs³ugi stronicowania na ¿¹danie, zwraca 1 char dla danego procesu
	void Get_Page_From_WM(PCB* blok, int page);
	void Insert_To_Virtual_Memory(PCB *blok);//wrzuc do pamieci wirtualnej i ustawiaj w pcb TabliceStron
	int Get_Free_Frame_Number();

	int WhichPage(short int); //MMU; do przeliczania adresu logicznego na fizyczny
	int WhatOffset(short int);  //MMU; -||-


	stronice MemRequest();//do obgadania
	void DeleteProcess(PCB *blok);
	void PrintOM();
	void PrintVM(vector<PCB*> AllProc);//do wypisania pamieci wirtualnej potrzebna jest lista przechowujaca wszystkie procesy

};

