#pragma once
#include <iostream>
#include <list>
#include "PCB.h"
using namespace std;
//prosz� si� nie sugerowac moimi rozwi�zaniami, tu jeszcze wszystko mo�e si� zmieni�

const int framesize = 16;//rozmiar ramki/strony
const int framecount = 8;//operacyjna sklada sie z 8 ramek, czyli 8*16 bajt�w = 128 bajt�w pami�ci
const int adreslength = 8;//2^8 = 256  /hex(FF)/  limit adresu dla stron ( (dec)1111_1111 = 255), istnieje 256 stron na pamieci wirtualnej, beda one sciagane do ramek

struct page {
	unsigned short nr;
	string data; //Nie wiem jaki typ tu da�. Jak zostanie string, to bedzie to string na 14char�w/bajt�w, bo 2 bajty id� na NR, a ca�y page=16 bajt�w
};

class PamiecOperiWirt
{
public:
	PamiecOperiWirt();
	~PamiecOperiWirt();

	int AktualnyRozmiarOP;//zlicza ile razy u�yta zostanie operacja push_back
	int AktualnyRozmiarWIRT;//zlicza ile razy u�yta zostanie operacja push_back
	page *singlepage;
	list <page> POper;
	list <page> PWirt;

	int WhichPage(short int);//MMU do przeliczania adresu logicznego na fizyczny
	int WhatOffset(short int);//MMU

	void AktualizujPamiecWirtualna();//kontrowersyjna procedura, musze mie� sw�j bank (pami�c wirt.) z kt�rej b�d� przepisywa� do operacyjnej pojedyncze bloki danych. Tym bankiem nie mo�e by� sam dysk (s�owa bartoszka) wi�c trzeba dokonywa� jakiego� przepisywania dysku do mojego banku, tym b�dzie si� zajmowa� ta procedura

};

