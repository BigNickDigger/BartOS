#pragma once
#include <iostream>
#include <list>
#include "PCB.h"
using namespace std;
//prosz� si� nie sugerowac moimi rozwi�zaniami, tu jeszcze wszystko mo�e si� zmieni�

const int framesize = 16;//rozmiar ramki/strony
const int framecount = 8;//operacyjna sklada sie z 8 ramek, czyli 8*16 bajt�w = 128 bajt�w pami�ci
const int adreslength = 8;//2^8 = 256  /hex(FF)/  limit adresu dla stron ( (dec)1111_1111 = 255), istnieje 256 stron w pamieci wirtualnej, beda one sciagane do ramek

struct page {
	unsigned short nr;
	string data; //Nie wiem jaki typ tu da�. Jak zostanie string, to bedzie to string na 14char�w/bajt�w, bo 2 bajty id� na NR, a ca�y page=16 bajt�w
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

	//int WhichPage(short int); //MMU do przeliczania adresu logicznego na fizyczny, nie wiem czy sie przydadz� na ten moment
	//int WhatOffset(short int);  //MMU -||-

	void StworzPamiecWirtualna();//kontrowersyjna procedura, musze mie� sw�j bank (pami�c wirt.) z kt�rej b�d� przepisywa� do operacyjnej pojedyncze bloki danych. Tym bankiem NIE mo�e by� sam dysk (s�owa bartoszka) wi�c trzeba dokonywa� jakiego� przepisywania dysku do mojego banku, tym b�dzie si� zajmowa� ta procedura
	stronice MemRequest();
	void DeleteProcess(PCB);

};

