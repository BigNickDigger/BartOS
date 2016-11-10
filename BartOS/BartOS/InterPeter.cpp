#include "stdafx.h"
#include "InterPeter.h"
#include <string>


InterPeter::InterPeter()
{
	regA = 0;
	regB = 0;
	regC = 0;
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

void InterPeter::ExecuteCommand()
{
	string line = LoadCommand();
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
				regA += regB;
				break;

			case 'C':
				regA += regC;
				break;
			default:
				regA += std::stoi(line.substr(5));
				break;
			}
			break;

		case 'B':
			switch (line.at(5))
			{
			case 'A':
				regB += regA;
				break;

			case 'C':
				regB += regA;
				break;
			default:
				regB += std::stoi(line.substr(5));
				break;
			}
		
			break;

		case 'C':
			switch (line.at(5))
			{
			case 'A':
				regC += regA;
				break;

			case 'B':
				regC += regB;
				break;
			}
		default:
			regC += std::stoi(line.substr(5));
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
				regA -= regB;
				break;

			case 'C':
				regA -= regC;
				break;
			default:
				regA -= std::stoi(line.substr(5));
				break;
			}
			break;

		case 'B':
			switch (line.at(5))
			{
			case 'A':
				regB -= regA;
				break;

			case 'C':
				regB -= regA;
				break;
			default:
				regB -= std::stoi(line.substr(5));
				break;
			}
			break;

		case 'C':
			switch (line.at(5))
			{
			case 'A':
				regC -= regA;
				break;

			case 'B':
				regC -= regB;
				break;
			default:
				regC -= std::stoi(line.substr(5));
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
				regA *= regB;
				break;

			case 'C':
				regA *= regC;
				break;
			default:
				regA *= std::stoi(line.substr(5));
				break;
			}
			break;

		case 'B':
			switch (line.at(5))
			{
			case 'A':
				regB *= regA;
				break;

			case 'C':
				regB *= regA;
				break;
			default:
				regB *= std::stoi(line.substr(5));
				break;
			}
			break;

		case 'C':
			switch (line.at(5))
			{
			case 'A':
				regC *= regA;
				break;

			case 'B':
				regC *= regB;
				break;
			default:
				regC *= std::stoi(line.substr(5));
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
			regA++;
			break;

		case 'B':
			regB++;
			break;

		case 'C':
			regC++;
			break;
		}
	}
	else if (n == "DC")
	{
		switch (line.at(3))
		{
		case 'A':
			regA--;
			break;

		case 'B':
			regB--;
			break;

		case 'C':
			regC--;
			break;
		}
	}
	else if (n == "JP") // jump
	{
		PC = std::stoi(line.substr(3));
	}
	else if (n == "JN") //jump not zero
	{
		if (regA != 0)
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
				regA = regB;
				break;

			case 'C':
				regA = regC;
				break;
			default:
				regA = std::stoi(line.substr(5));
				break;
			}
			break;

		case 'B':
			switch (line.at(5))
			{
			case 'A':
				regB = regA;
				break;

			case 'C':
				regB = regA;
				break;
			default:
				regB = std::stoi(line.substr(5));
				break;
			}
			break;

		case 'C':
			switch (line.at(5))
			{
			case 'A':
				regC = regA;
				break;

			case 'B':
				regC = regB;
				break;
			default:
				regC = std::stoi(line.substr(5));
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
				swap(regA, regB);
				break;

			case 'C':
				swap(regA, regC);
				break;
			
			}
			break;

		case 'B':
			switch (line.at(5))
			{
			case 'A':
				swap(regB, regA);
				break;

			case 'C':
				swap(regB, regC);
				break;
			
			}
			break;

		case 'C':
			switch (line.at(5))
			{
			case 'A':
				swap(regC, regA);
				break;

			case 'B':
				swap(regC, regB);
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
	else if (n == "EN")
	{

	}
	else if (n == "SB")
	{

	}

	

	PC++;
}

std::string InterPeter::LoadCommand()
{
	string line;
	char p;

	do
	{
		//p = load_memez(PC);
		line += p;
		PC++;
	} while (p != ';');

	return line;
}

void InterPeter::RegisterDisplay()
{
	cout << " Register State " << endl;
	cout << "A  : " << regA << endl;
	cout << "B  : " << regB << endl;
	cout << "C  : " << regC << endl;
	cout << "PC : " << PC << endl;
}

void InterPeter::CommandDisplay()
{
	cout << " Commands" << endl;
	cout << "PREV : " << endl;
	cout << "NEXT : " << endl;
}

void InterPeter::Interface()
{
	RegisterDisplay();
	cout << "-----------" << endl;
	CommandDisplay();
}
