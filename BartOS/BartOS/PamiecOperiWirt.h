#pragma once
#include <iostream>
#include <list>
#include "PCB.h"
using namespace std;
//proszê siê nie sugerowac moimi rozwi¹zaniami, tu jeszcze wszystko mo¿e siê zmieniæ

const int framesize = 16;//rozmiar ramki/strony
const int framecount = 8;//operacyjna sklada sie z 8 ramek, czyli 8*16 bajtów = 128 bajtów pamiêci
const int adreslength = 8;//2^8 = 256  /hex(FF)/  limit adresu dla stron ( (dec)1111_1111 = 255), istnieje 256 stron w pamieci wirtualnej, beda one sciagane do ramek

struct page {
	unsigned short nr;
	string data; //Nie wiem jaki typ tu daæ. Jak zostanie string, to bedzie to string na 14charów/bajtów, bo 2 bajty id¹ na NR, a ca³y page=16 bajtów
};

class PamiecOperiWirt
{
public:
	PamiecOperiWirt();
	~PamiecOperiWirt();
	unsigned short LicznikDoStron;
	unsigned short AktualnyRozmiarOP;//zlicza ile ramek jest zajetych
	unsigned short AktualnyRozmiarWIRT;//zlicza ile stron jest zajetych

	page *singlepage;
	list <page> POper;
	list <page> PWirt;
	list <page>::iterator iter;

	//PCB blok; //jeszcze nie jestem tego pewien

	//int WhichPage(short int); //MMU do przeliczania adresu logicznego na fizyczny, nie wiem czy sie przydadz¹ na ten moment
	//int WhatOffset(short int);  //MMU -||-

	void StworzPamiecWirtualna();//kontrowersyjna procedura, musze mieæ swój bank (pamiêc wirt.) z której bêdê przepisywa³ do operacyjnej pojedyncze bloki danych. Tym bankiem NIE mo¿e byæ sam dysk (s³owa bartoszka) wiêc trzeba dokonywaæ jakiegoœ przepisywania dysku do mojego banku, tym bêdzie siê zajmowaæ ta procedura
	stronice MemRequest();
	void DeleteProcess(PCB);

};

