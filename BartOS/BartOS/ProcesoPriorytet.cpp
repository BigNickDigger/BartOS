//amen

#include "stdafx.h"
#include "ProcesoPriorytet.h"

ProcesoPriorytet::ProcesoPriorytet()
{
	KiReadySummary = new int[NUMBER_OF_PRIORITIES]; //tworzymy bitowy wektor pomocniczy
	for (int i = 0; i < NUMBER_OF_PRIORITIES; i++) {
		//zerujemy bity na wektorze
		KiReadySummary[i] = 0;

		//dodajemy wektory do wektora wektorow
		std::vector<PCB*> tmp;
		KiDispatcher.push_back(tmp);
	}
	running = NULL;
	//system("Pause");
}

//kilka zmiennych zadeklarowanych aby program byl bardziej "elastyczny", tzn. mozemy z jednego miejsca
//zmieniac wszystkie wartosci na ktorych opiera sie moj modul
int ProcesoPriorytet::NUMBER_OF_PRIORITIES = 16;
int ProcesoPriorytet::NUMBER_OF_TIME_QUANTUM = 3;
int ProcesoPriorytet::NUMBER_OF_HUNGER = 6;

ProcesoPriorytet::~ProcesoPriorytet()
{
	//czyscimy wskazniczki
	KiDispatcher.clear();
	delete KiReadySummary;
}

PCB *ProcesoPriorytet::FindReadyThread()
{
	updateKiReadySummary();
	//szukanie zaczynamy od najwyzszej mozliwej kolejki
	for (int i = NUMBER_OF_PRIORITIES - 1; i >= 0; i--) {
		if (KiReadySummary[i] == 0) continue; //pomijamy iteracje, bo dana kolejka jest pusta
		for (auto it : KiDispatcher[i]) {
			if (it == running) {
				return it;
			}
			if (it->Process_State == PCB::Proc_Ready) {
				if (running != NULL) {
					if ((running->Priority + running->PriorityDynamic) < (it->Priority + it->PriorityDynamic)) {
						//wywlaszczanie
						cout << "Wyzszy priorytet! " << running->nazwa << " oddaje procesor." << endl;
						running->Process_State = PCB::Proc_Ready;
						running = it;
						it->Process_State = PCB::Proc_Running;
						return it;
					}
					else continue;
				}
				it->Process_State = PCB::Proc_Running;
				running = it;
				return it; //znaleziono chetny proces - zwracamy go
			}
		}
	}
}

void ProcesoPriorytet::addProcess(PCB *a)
{
	if (a->nazwa == "IDLE") {
		a->Priority = 0;
		a->PriorityDynamic = 0;
	}
	else if (!running) {
		a->Process_State = PCB::Proc_Running;
		running = a;
	}
	int i = a->Priority + a->PriorityDynamic;

	KiDispatcher[i].push_back(a); //wrzucamy proces na jego liste
	KiReadySummary[i] = 1;
}
void ProcesoPriorytet::removeProcess(PCB * a)
{
	int i = a->Priority + a->PriorityDynamic;
	KiDispatcher[i].erase(std::remove(KiDispatcher[i].begin(), KiDispatcher[i].end(), a), KiDispatcher[i].end());	//funkcja usuwajaca konkretny element z wektora
	if (KiDispatcher[i].empty()) KiReadySummary[i] = 0;
}

bool ProcesoPriorytet::moveProcess(PCB *a)
{
	int i = a->Priority + a->PriorityDynamic;
	if (i + 1 >= NUMBER_OF_PRIORITIES) {
		cout << "Proces " << a->nazwa << " ma juz najwyzszy mozliwy priorytet." << endl;
		return true;
	}
	for (auto it : KiDispatcher[i]) {
		removeProcess(a); //usuwamy z aktualnej listy
		a->PriorityDynamic++; //zwiekszamy priorytet dynamiczny - maksymalnie 8
		i = a->Priority + a->PriorityDynamic;
		KiDispatcher[i].push_back(a); //dodajemy do nowej kolejki

		updateKiReadySummary();
		return true;
	}
	updateKiReadySummary();
	return false;
}

void ProcesoPriorytet::throwToBack(PCB *a)
{
	int i = a->Priority + a->PriorityDynamic;
	removeProcess(a);
	KiDispatcher[i].push_back(a);
	KiReadySummary[i] = 1;
}


void ProcesoPriorytet::tick_processes()
{
	if (running != NULL) {
		if ((running->ProgramCounter % NUMBER_OF_TIME_QUANTUM + 1) == 0 && running->ProgramCounter != 0) {
			cout << "Proces " << running->nazwa << " wykorzystal kwant czasu." << endl;
			//round-robin - przenosimy na koniec kolejki
			throwToBack(running);
		}
	}
	//zaczynamy od najwyzszych
	for (int i = NUMBER_OF_PRIORITIES - 1; i > 0; i--) {
		if (KiReadySummary[i] == 0) continue; //pomijamy ta iteracje petli, bo struktura jest pusta
		bool leave = false;
		
		while (!leave) {
			leave = true; //domyslnie opuszczamy petle, chyba, ze cos zostanie przeniesione
			for (auto it : KiDispatcher[i]) {
				if (it->Process_State == PCB::Proc_Ready) {
					it->idleTime++; //znaleziono kogos kto czekal -> zwiekszamy wartosc 'czekania'
					if (it->idleTime >= NUMBER_OF_HUNGER) {
						//proces czekal bardzo dlugo - pora go nagrodzic i podwyzszyc priorytet
						it->idleTime = 0; //zerujemy idleTime - bo dostal 'nagrode' za czekanie
						bool flag = false;
						flag = moveProcess(it); //przenosimy tylko, jezeli proces nie jest w najwyzszej kolejce
						if (flag) {
							leave = false; //przenieslismy proces z jednej kolejki do drugiej - nalezy ponownie przeiterowac nizsza kolejke
							break;
						}
					}
				}
			}
		}
	}
}




void ProcesoPriorytet::printMyBeautifulStructurePlease()
{
	for (int i = 0; i < NUMBER_OF_PRIORITIES; i++) {
		std::vector<PCB*>::iterator it;
		bool PrintPriority = true;
		for (auto it : KiDispatcher[i]) {
			if (PrintPriority) {
				std::cout << i << ":" << std::endl;
				PrintPriority = false;
			}
			std::cout << it->nazwa << " (" << it->Priority << "+" << it->PriorityDynamic << ") " << it->Process_State << "("<<it->ProgramCounter<<")"<<" IDLE: " << it->idleTime << std::endl;
		}
	}
}
void ProcesoPriorytet::printMyBeatufiulBitVectorPlease()
{
	cout << "Pomocniczy wektor bitowy:" << endl;
	for (int i = 0; i < NUMBER_OF_PRIORITIES; i++) {
		cout << i << ": " << KiReadySummary[i] << "|";
		if (i < 9)cout << " ";
		if (i % 8 == 0 && i != 0)cout << endl;
	}

}
void ProcesoPriorytet::updateKiReadySummary() {
	for (int i = 0; i < NUMBER_OF_PRIORITIES; i++) {
		if (KiDispatcher[i].empty()) {
			KiReadySummary[i] = 0;
		}
		else KiReadySummary[i] = 1;
	}
}