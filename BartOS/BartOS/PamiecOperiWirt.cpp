#include "stdafx.h"
#include "PamiecOperiWirt.h"


PamiecOperiWirt::PamiecOperiWirt()
{
	
}
//sss

PamiecOperiWirt::~PamiecOperiWirt()
{
	delete singlepage;
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
	
	
}//Dodalem Ci funkcje hehe XD
// Wez ja wypelnij jakos ladnie
stronice PamiecOperiWirt::MemRequest() {
	int ErrCode;
	if (true)//Jest wolne miejsce dla alokacji pliku w 
		throw ErrCode = 1; //podmien true na wypelniona stronice
	else //Nie ma miejsca na plik
		throw ErrCode = 0;

}