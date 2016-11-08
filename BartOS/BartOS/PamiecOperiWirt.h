#pragma once
#include <iostream>
#include <list>
#include "PCB.h"
using namespace std;
//proszê siê nie sugerowac moimi rozwi¹zaniami, tu jeszcze wszystko mo¿e siê zmieniæ

const int framesize = 16;//rozmiar ramki/strony
const int OMsize = 16;
const int WMsize = 64;

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

};

class PamiecOperiWirt
{
public:
	PamiecOperiWirt();
	~PamiecOperiWirt();

	int OM_Next_Frame_Victim;
	int IndexforWM;
	page POper[OMsize];//16 czyli pamiec op 126byte
	page PWirt[WMsize];//64 pamiec wirtualna 2048byte

	char *ReturnLineOf16Chars();//udostepnia zawartosc ramki, kinda useless propably

	char Get_Whole_Process_From_Memory(PCB blok);//mechanizm obs³ugi stronicowania na ¿¹danie ale dziki bo zwraca ca³y kod programu LUL
	char Get_Char_From_OM(PCB blok, int LogicAdr);//mechanizm obs³ugi stronicowania na ¿¹danie, zwraca 1 char dla danego procesu
	void Get_Page_From_WM(PCB, int);
	void Insert_To_Virtual_Memory();//wrzuc do pamieci wirtualnej
	string Return_A_Formed_Order(PCB blok);

	int WhichPage(short int); //MMU do przeliczania adresu logicznego na fizyczny, nie wiem czy sie przydadz¹ na ten moment
	int WhatOffset(short int);  //MMU -||-

	stronice MemRequest();//do obgadania
	void DeleteProcess(PCB);
	void PrintOM();
	void PrintWM();

};

