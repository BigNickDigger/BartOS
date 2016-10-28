#pragma once
#include <iostream>
#include <list>

#define framesize = 16;
#define framecount = 3;//operacyjna sklada sie z 3 ramek
#define adreslength = 8;//2^8 = 256  /hex(FF)/  limit adresu dla stron, istnieje 256 stron na pamieci wirtualnej, beda one sciagane do ramek

using namespace std;
typedef struct page {
	int nr;
	char data; //albo string???? jak bedzie char, to chyba bez sensu bedzie
	bool valid = false; // true = jest w operacyjnej || false = nie ma w operacyjnej trzeba sciagnac z wirtualnej
};

class PamiecOperiWirt
{
public:
	
	list <page> POper;
	list <page> PWirt;

	PamiecOperiWirt();
	~PamiecOperiWirt();


};

