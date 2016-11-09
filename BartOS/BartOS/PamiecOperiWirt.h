#pragma once
#include <iostream>
#include <vector>
#include "PCB.h"
using namespace std;
//proszê siê nie sugerowac moimi rozwi¹zaniami, tu jeszcze wszystko mo¿e siê zmieniæ

const int framesize = 16;//rozmiar ramki/strony
const int OMsize = 16;

class page {
public:
	char tab[framesize];//framesize = 16
	int nr;
	page()
	{
		for (int i = 0; i < framesize; i++)
		{
			tab[i] = '-';
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
	int IndexforWM;
	int IndexforWM2;
	page OM[OMsize];//16 czyli pamiec op 126byte
	vector <page*> VM;//64 pamiec wirtualna 2048byte
	vector <page*>::iterator VMiter;
	

	//char Get_Whole_Process_From_Memory(PCB blok);//mechanizm obs³ugi stronicowania na ¿¹danie ale dziki bo zwraca ca³y kod programu
	char Get_Char_From_OM(PCB *blok, int LogicAdr);//mechanizm obs³ugi stronicowania na ¿¹danie, zwraca 1 char dla danego procesu
	void Get_Page_From_WM(PCB* blok, int page);
	void Insert_To_Virtual_Memory(PCB *blok);//wrzuc do pamieci wirtualnej i ustawiaj w pcb TabliceStron
	//string Return_A_Formed_Order(PCB blok);//kinda useless propably

	int WhichPage(short int); //MMU do przeliczania adresu logicznego na fizyczny, nie wiem czy sie przydadz¹ na ten moment
	int WhatOffset(short int);  //MMU -||-

	stronice MemRequest();//do obgadania
	void DeleteProcess(PCB *blok);
	void PrintOM();
	void PrintWM(vector<PCB*> AllProc);//do wypisania pamieci wirtualnej potrzebna jest lista przechowujaca wszystkie procesy

};

