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

	int NrforOM;
	int NrforWM;
	page POper[OMsize];//16 czyli pamiec op 126byte
	page PWirt[WMsize];//64 pamiec wirtualna 2048byte

	char *ReturnLineOf16Chars(int);//udostepnia zawartosc ramki

	

	//int WhichPage(short int); //MMU do przeliczania adresu logicznego na fizyczny, nie wiem czy sie przydadz¹ na ten moment
	//int WhatOffset(short int);  //MMU -||-

	stronice MemRequest();
	void DeleteProcess(PCB);
	void PrintOM();
	void PrintWM();

};

