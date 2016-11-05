#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "PCB.h"
using namespace std;
//prosz� si� nie sugerowac moimi rozwi�zaniami, tu jeszcze wszystko mo�e si� zmieni�

const int framesize = 16;//rozmiar ramki/strony

class page {
public:
	
	char data[16]; //Nie wiem jaki typ tu da�. Jak zostanie string, to bedzie to string na 14char�w/bajt�w, bo 2 bajty id� na NR, a ca�y page=16 bajt�w
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

	//int WhichPage(short int); //MMU do przeliczania adresu logicznego na fizyczny, nie wiem czy sie przydadz� na ten moment
	//int WhatOffset(short int);  //MMU -||-

	//void StworzPamiecWirtualna();//nie wiem czy sie przyda

	void DeleteProcess(PCB);
	void AllocateMemory(unsigned short);

	void ShowOPMemory();
	void ShowVirtualMemory();

};

