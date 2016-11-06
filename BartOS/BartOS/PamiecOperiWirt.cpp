#include "stdafx.h"
#include "PamiecOperiWirt.h"


PamiecOperiWirt::PamiecOperiWirt()
{
	NrforOM = 0;
	NrforWM = 0;
	for (int i = 0; i < OMsize;i++)
	{
		POper[i].nr = i;
	}
	for (int i = 0; i < WMsize; i++)
	{
		PWirt[i].nr = i;
	}
}

PamiecOperiWirt::~PamiecOperiWirt()
{
	
}

//int PamiecOperiWirt::WhichPage(short int x)
//{
//	return (x / 16);
//}
//
//int PamiecOperiWirt::WhatOffset(short int x)
//{
//	return (x % 16);
//}


void PamiecOperiWirt::DeleteProcess(PCB blok)
{
	
}
//Dodalem Ci funkcje hehe XD
// Wez ja wypelnij jakos ladnie
stronice PamiecOperiWirt::MemRequest() {
	int ErrCode;
	if (true)//Jest wolne miejsce dla alokacji pliku w 
		throw ErrCode = 1; //podmien true na wypelniona stronice
	else //Nie ma miejsca na plik
		throw ErrCode = 0;

}

char *PamiecOperiWirt::ReturnLineOf16Chars(int NrOfTheFrame)//NrOfTheFrame nale¿y do <0,15>
{
	return POper[NrOfTheFrame].tab;
}

void PamiecOperiWirt::PrintOM()
{
	cout << "AKTUALNY STAN PAMIECI OPERACYJNEJ" << endl;
	for (int i = 0; i < OMsize; i++)
	{
		POper[i].PrintPage();
	}
}

void PamiecOperiWirt::PrintWM()
{
	cout << "AKTUALNY STAN PAMIECI WIRTUALNEJ" << endl;
	for (int i = 0; i < WMsize; i++)
	{
		if (i % 16 == 0 && i!=0)
			cout << endl;
		PWirt[i].PrintPage();
	}
}