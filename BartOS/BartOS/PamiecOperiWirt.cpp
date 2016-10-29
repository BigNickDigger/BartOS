#include "stdafx.h"
#include "PamiecOperiWirt.h"


PamiecOperiWirt::PamiecOperiWirt()
{
	for (int i = 0; i < 255; i++)//utworzenie pamieci wirtualnej, 256 pustych stron
	{
		singlepage = new page;
		PWirt.push_back(*singlepage);
	}
	for (int i = 0; i < 8; i++)
	{
		singlepage = new page;
		POper.push_back(*singlepage);//utworzenie pamieci operacyjnej, 8 pustych ramek
	}
}


PamiecOperiWirt::~PamiecOperiWirt()
{
	
}

int PamiecOperiWirt::WhichPage(short int x)
{
	return (x / 16);
}

int PamiecOperiWirt::WhatOffset(short int x)
{
	return (x % 16);
}

void PamiecOperiWirt::AktualizujPamiecWirtualna()
{
	
}
