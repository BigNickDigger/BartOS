#pragma once
#include <iostream>
#include <list>

#define pagesize = 16;
#define pagecount = 3;
#define adreslength = 8;

using namespace std;
typedef struct page {
	int nr;
	char data;
	bool valid = false;
};

class PamiecOperiWirt
{
public:
	list <page> TAB[10];
	list <page> POper;
	list <page> PWirt;

	PamiecOperiWirt();
	~PamiecOperiWirt();


};

