#pragma once
#include <iostream>
#include <list>
#include "PCB.h"
using namespace std;
//proszê siê nie sugerowac moimi rozwi¹zaniami, tu jeszcze wszystko mo¿e siê zmieniæ

const int framesize = 16;//rozmiar ramki/strony

class page {
public:
	char tab[framesize];//framesize = 16
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

	page *singlepage;

	page POper[16];//pamiec op 126byte
	page PWirt[126];//pamiec wirtualna 2016byte

	

	//int WhichPage(short int); //MMU do przeliczania adresu logicznego na fizyczny, nie wiem czy sie przydadz¹ na ten moment
	//int WhatOffset(short int);  //MMU -||-

	stronice MemRequest();
	void DeleteProcess(PCB);

};

