#include "stdafx.h"
#include "PamiecOperiWirt.h"


PamiecOperiWirt::PamiecOperiWirt()
{
	for (int i = 0; i < framecount; i++)
	{
		singlepage = new page;
		singlepage->data.reserve(14);
		singlepage->nr = i;//numeruje ramki od 0 do 7
		POper.push_back(*singlepage);//utworzenie pamieci operacyjnej, 8 pustych ramek, po iteratorze mo¿na wpisywaæ
	}
	LicznikDoStron = 0;
}


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

void PamiecOperiWirt::StworzPamiecWirtualna()
{
	//tworzy strone, wpisuje 14 charow i pushuje do listy stron. Powtarza az do wyczerpania charow na dysku
}

void PamiecOperiWirt::DeleteProcess(PCB blok)
{
	int i = 0;
	for (iter = POper.begin(); iter != POper.end(); i++)
	{
		
		if (blok.pages[i].Valid == true)//gdy iter najedzie na ramke dla ktorej w tablicy stronic bit valid jest rowny TRUE
		{
			POper.erase(iter++);
			singlepage = new page;
			singlepage->nr = i;
			POper.insert(iter,*singlepage);
		}
		else
		{
			iter++;
		}
	}
	
}
