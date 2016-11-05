#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "PCB.h"
using namespace std;
//proszê siê nie sugerowac moimi rozwi¹zaniami, tu jeszcze wszystko mo¿e siê zmieniæ

const int framesize = 16;//rozmiar ramki/strony

class page {
public:
	
	char data[16]; //Nie wiem jaki typ tu daæ. Jak zostanie string, to bedzie to string na 14charów/bajtów, bo 2 bajty id¹ na NR, a ca³y page=16 bajtów
	page()
	{
		for (int i = 0; i < 16; i++)
		{
			data[i] = '-';
		}
	}
	void ShowFrame()
	{
		for (int i = 0; i < 16; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
	void Insert16Chars(string S)
	{
		for (int i = 0; i < 16; i++)
		{
			data[i] = S[i];
		}
	}
};

class PamiecOperiWirt
{
public:
	int POnr;
	int PWnr;
	PamiecOperiWirt();
	~PamiecOperiWirt();
	unsigned short LicznikDoStron;
	unsigned short AktualnyRozmiarOP;//zlicza ile ramek jest zajetych
	unsigned short AktualnyRozmiarWIRT;//zlicza ile stron jest zajetych

	page *singlepage;
	
	//list <page> POper;
	page POper[8];
	vector <page> PWirt;
	vector <page>::iterator iter;

	//int WhichPage(short int); //MMU do przeliczania adresu logicznego na fizyczny, nie wiem czy sie przydadz¹ na ten moment
	//int WhatOffset(short int);  //MMU -||-

	//void StworzPamiecWirtualna();//nie wiem czy sie przyda

	void DeleteProcess(PCB);
	void AllocateMemory(unsigned short);

	void ShowOPMemory();
	void ShowVirtualMemory();

};

