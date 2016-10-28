#include "stdafx.h"
#include "InterPeter.h"


InterPeter::InterPeter()
{
	rejA = 0;
	rejB = 0;
	rejC = 0;
	PC = 0;
}


InterPeter::~InterPeter()
{

}

void InterPeter::SaveState()
{

}

void InterPeter::LoadState()
{

}

void InterPeter::Command()
{
	string line;
	string n;
	n = line.at(0) + line.at(1);
	if (n == "AD")
	{
		switch (line.at(3))
		{
		case 'A':
			switch (line.at(6))
			{
			case 'B':
				rejA += rejB;
				break;

			case 'C':
				rejA += rejC;
				break;
			}
			break;

		case 'B':
			switch (line.at(6))
			{
			case 'A':
				rejB += rejA;
				break;

			case 'C':
				rejC += rejA;
				break;
			}
			break;

		case 'C':
			switch (line.at(6))
			{
			case 'A':
				rejC += rejA;
				break;

			case 'B':
				rejC += rejB;
				break;
			}
			break;
		}
	}
	else if (n == "SB")
	{
		switch (line.at(3))
		{
		case 'A':
			switch (line.at(6))
			{
			case 'B':
				rejA -= rejB;
				break;

			case 'C':
				rejA -= rejC;
				break;
			}
			break;

		case 'B':
			switch (line.at(6))
			{
			case 'A':
				rejB -= rejA;
				break;

			case 'C':
				rejC -= rejA;
				break;
			}
			break;

		case 'C':
			switch (line.at(6))
			{
			case 'A':
				rejC -= rejA;
				break;

			case 'B':
				rejC -= rejB;
				break;
			}
			break;
		}
	}
	else if (n == "MP")
	{
		switch (line.at(3))
		{
		case 'A':
			switch (line.at(6))
			{
			case 'B':
				rejA *= rejB;
				break;

			case 'C':
				rejA *= rejC;
				break;
			}
			break;

		case 'B':
			switch (line.at(6))
			{
			case 'A':
				rejB *= rejA;
				break;

			case 'C':
				rejC *= rejA;
				break;
			}
			break;

		case 'C':
			switch (line.at(6))
			{
			case 'A':
				rejC *= rejA;
				break;

			case 'B':
				rejC *= rejB;
				break;
			}
			break;
		}
	}
	else if (n == "IC")
	{
		switch (line.at(3))
		{
		case 'A':
			rejA++;
			break;

		case 'B':
			rejB++;
			break;

		case 'C':
			rejC++;
			break;
		}
	}
	else if (n == "DC")
	{
		switch (line.at(3))
		{
		case 'A':
			rejA--;
			break;

		case 'B':
			rejB--;
			break;

		case 'C':
			rejC--;
			break;
		}
	}
	else if (n == "JP")
	{

	}
	else if (n == "JZ")
	{


	}
	else if (n == "SB")
	{


	}


	//SYS

	else if (n == "NF") //plik
	{
//nowy plik
	}
	else if (n == "LD")
	{

	}
	else if (n == "SV")
	{

	}
	else if (n == "SB")
	{

	}
	else if (n == "SB")
	{

	}
	else if (n == "SB")
	{

	}

	


}

void InterPeter::LoadProg()
{
	string line;
	//line=load_memez();

}
