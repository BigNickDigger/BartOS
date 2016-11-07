#include "stdafx.h"
#include "InterPeter.h"
#include <string>


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
			switch (line.at(5))
			{
			case 'B':
				rejA += rejB;
				break;

			case 'C':
				rejA += rejC;
				break;
			default:
				rejA += std::stoi(line.substr(5));
				break;
			}
			break;

		case 'B':
			switch (line.at(5))
			{
			case 'A':
				rejB += rejA;
				break;

			case 'C':
				rejB += rejA;
				break;
			default:
				rejB += std::stoi(line.substr(5));
				break;
			}
		
			break;

		case 'C':
			switch (line.at(5))
			{
			case 'A':
				rejC += rejA;
				break;

			case 'B':
				rejC += rejB;
				break;
			}
		default:
			rejC += std::stoi(line.substr(5));
			break;
		}
	}
	else if (n == "SB")
	{
		switch (line.at(3))
		{
		case 'A':
			switch (line.at(5))
			{
			case 'B':
				rejA -= rejB;
				break;

			case 'C':
				rejA -= rejC;
				break;
			default:
				rejA -= std::stoi(line.substr(5));
				break;
			}
			break;

		case 'B':
			switch (line.at(5))
			{
			case 'A':
				rejB -= rejA;
				break;

			case 'C':
				rejB -= rejA;
				break;
			default:
				rejB -= std::stoi(line.substr(5));
				break;
			}
			break;

		case 'C':
			switch (line.at(5))
			{
			case 'A':
				rejC -= rejA;
				break;

			case 'B':
				rejC -= rejB;
				break;
			default:
				rejC -= std::stoi(line.substr(5));
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
			switch (line.at(5))
			{
			case 'B':
				rejA *= rejB;
				break;

			case 'C':
				rejA *= rejC;
				break;
			default:
				rejA *= std::stoi(line.substr(5));
				break;
			}
			break;

		case 'B':
			switch (line.at(5))
			{
			case 'A':
				rejB *= rejA;
				break;

			case 'C':
				rejB *= rejA;
				break;
			default:
				rejB *= std::stoi(line.substr(5));
				break;
			}
			break;

		case 'C':
			switch (line.at(5))
			{
			case 'A':
				rejC *= rejA;
				break;

			case 'B':
				rejC *= rejB;
				break;
			default:
				rejC *= std::stoi(line.substr(5));
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
	else if (n == "JP") // jump
	{
		PC = std::stoi(line.substr(3));
	}
	else if (n == "JN") //jump not zero
	{
		if (rejA != 0)
		{
			PC = std::stoi(line.substr(3));
		}

	}
	else if (n == "MV")
	{
		switch (line.at(3))
		{
		case 'A':
			switch (line.at(5))
			{
			case 'B':
				rejA = rejB;
				break;

			case 'C':
				rejA = rejC;
				break;
			default:
				rejA = std::stoi(line.substr(5));
				break;
			}
			break;

		case 'B':
			switch (line.at(5))
			{
			case 'A':
				rejB = rejA;
				break;

			case 'C':
				rejB = rejA;
				break;
			default:
				rejB = std::stoi(line.substr(5));
				break;
			}
			break;

		case 'C':
			switch (line.at(5))
			{
			case 'A':
				rejC = rejA;
				break;

			case 'B':
				rejC = rejB;
				break;
			default:
				rejC = std::stoi(line.substr(5));
				break;
			}
			break;
		}
	}
	else if (n == "SW") //swap
	{

		switch (line.at(3))
		{
		case 'A':
			switch (line.at(5))
			{
			case 'B':
				swap(rejA, rejB);
				break;

			case 'C':
				swap(rejA, rejC);
				break;
			
			}
			break;

		case 'B':
			switch (line.at(5))
			{
			case 'A':
				swap(rejB, rejA);
				break;

			case 'C':
				swap(rejB, rejC);
				break;
			
			}
			break;

		case 'C':
			switch (line.at(5))
			{
			case 'A':
				swap(rejC, rejA);
				break;

			case 'B':
				swap(rejC, rejB);
				break;
		
			}
			break;
		}

	}
	else if (n == "SB")
	{


	}


	//SYS

	else if (n == "NF") //nowy plik
	{

	}
	else if (n == "LD") //meme load
	{
		
	}
	else if (n == "SV") //meme save
	{
		
	}
	else if (n == "MV")
	{

	}
	else if (n == "SB")
	{

	}
	else if (n == "KL") //kill process
	{

	}
	else if (n == "HT") //halt - hammer Zeit
	{

	}
	else if (n == "SB")
	{

	}

	

	PC++;
}

void InterPeter::LoadProg()
{
	string line;
	//line=load_memez();

}
