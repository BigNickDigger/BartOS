#include "stdafx.h"
#include "PamiecOperiWirt.h"


PamiecOperiWirt::PamiecOperiWirt()
{
	POnr = 0;
	PWnr = 0;
}


PamiecOperiWirt::~PamiecOperiWirt()
{
	//delete singlepage;
}


//void PamiecOperiWirt::StworzPamiecWirtualna()
//{
	//tworzy strone, wpisuje 14 charow i pushuje do listy stron. Powtarza az do wyczerpania charow na dysku
//}

void PamiecOperiWirt::DeleteProcess(PCB blok)
{
	
	
}

void PamiecOperiWirt::AllocateMemory(unsigned short x)
{
	
}




void PamiecOperiWirt::ShowOPMemory()
{
	for (int i = 0; i < 8; i++)
	{
		this->POper[i].ShowFrame();
	}
}
void PamiecOperiWirt::ShowVirtualMemory()
{
	for (iter = PWirt.begin(); iter != PWirt.end(); ++iter)
	{
		iter->ShowFrame();
	}
	iter = PWirt.begin();
}
