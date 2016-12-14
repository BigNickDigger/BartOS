#include "stdafx.h"
#include "InterPeter.h"
#include <string>




InterPeter::InterPeter()
{
	regA = 0;
	regB = 0;
	regC = 0;
	PC = 0;
	Adr = 0;
	AdrPREV = 0;
	prog = "NF plik.txt;WF plik.txt,string Mariusz;DF plik.txt;EN;";
		//"MV A,5;MV B,0;MV C,1;AD C,B;SW C,B;DC A;JN 21;EN;";//"MV A,5;MV B,0;MV C,1;AD C,B;SW C,B;DC A;JN 21;EN;";
}


InterPeter::~InterPeter(){}

void InterPeter::SaveState(PCB* block) //Dareg
{
	block->RegA = regA;
	block->RegB = regB;
	block->RegC = regC;
	block->ProgramCounter = PC;
}

void InterPeter::LoadState(PCB* block) //Dareg
{
	regA = block->RegA;
	regB = block->RegB;
	regC = block->RegC;
	PC = block->ProgramCounter;
}

void InterPeter::ExecuteCommand(PCB* block, PamiecOperiWirt pam, KomunikacjaProcesowa *kom, HardDrive &dysk)
{
	//LoadState(block);

	string line;
	string command;

	line = LoadCommand(Adr, 0, block, pam);
	
	command += line.at(0);
	command += line.at(1);



	//MATHz

	if (command == "AD")
	{
		cout << "#" << line.at(3) << endl;
		cout << "#" << line.at(5) << endl;
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
				regB += regC;
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
				cout << "arf" << endl;
				regC += regB;
				break;
			default:
				regC += std::stoi(line.substr(5));
				break;
			}
			break;
		}
		
	}
	else if (command == "SB")
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
				regB -= regC;
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
	else if (command == "MP")
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
				regB *= regC;
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
	else if (command == "IC")
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
	else if (command == "DC")
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

	//TRANSFER

	else if (command == "JP") // jump
	{
		Adr = std::stoi(line.substr(3));
	}
	else if (command == "JN") //jump not zero
	{
		if (regA != 0)
		{
			Adr = std::stoi(line.substr(3));
		}

	}
	else if (command == "MV")
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
				regB = regC;
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
	else if (command == "SW") //swap
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



	//-SYS-

	//FILE #dysk  Marcin


	else if (command == "NF") //new file
	{
		dysk.create_file("PLICZAK.xD");
	}
	else if (command == "OF") //open file
	{

	}
	else if (command == "RF") //read file
	{

	}
	else if (command == "WF") //write file
	{
		dysk.write_to_file("PLICZAK.xD", "string mariusz inferno spaghetti");
	}
	else if (command == "CF") //close file
	{

	}
	else if (command == "DF") //write file
	{
		dysk.delete_file("PLICZAK.xD");
	}

	//MEMEory Kuba

	else if (command == "MR") //meme read
	{

	}
	else if (command == "MW") //meme write
	{
		
	}

	//MESSAGE Krzysiu

	else if (command == "XR") //read
	{
		kom->Receive();
	}
	else if (command == "XS") //send
	{
		kom->Send(69, "inferno_spaghetti");
	}
	
	//PROCESS Dareg

	else if (command == "CP") //create
	{
		
	}
	else if (command == "HP") //halt - hammer Zeit
	{
		block->Process_State = PCB::Proc_Ready;
	}
	else if (command == "KP") //kill
	{
		block->Process_State = PCB::Proc_Terminated;
	}

	//END
	
	else if (command == "EN") //BUT IN THE END
	{
		cout << "but in the EN, it doesn't even matter" << endl;
		//block->Process_State = PCB::Proc_Terminated;
		//return to BarKar
	}
	
	PC++;
	//SaveState(block);
}

std::string InterPeter::LoadCommand(int &adress, int f, PCB *block, PamiecOperiWirt pam)
{
	string line;
	char p;
	int a = adress;
	
	if (prog[Adr] == ';')
		Adr++;
	do
	{
		p = prog[a];//pam.Get_Char_From_OM(block, Adr);
		line += p;
		a++;
	} while (p != ';');

	if (!f)
	{
		AdrPREV = adress;
		adress = a;
	}
		
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

void InterPeter::CommandDisplay(PCB *block, PamiecOperiWirt pam)
{
	cout << " Commands" << endl;
	cout << "PREV : " << LoadCommand(AdrPREV, 1, block, pam) << endl;
	cout << "NEXT : " << LoadCommand(Adr, 1, block, pam) << endl;
}

void InterPeter::Interface(PCB *block, PamiecOperiWirt pam)
{
	RegisterDisplay();
	cout << "-----------" << endl;
	CommandDisplay(block, pam);
}
