#include "stdafx.h"
#include "Intro.h"


Intro::Intro()
{
}


Intro::~Intro()
{
}




#define cL 129
#define cLS 139
#define dL 146
#define dLS 156
#define eL 163
#define fL 173
#define fLS 185
#define gL 194
#define gLS 207
#define aL 219
#define aLS 228
#define bL 232

#define c 261
#define cS 277
#define d 294
#define dS 311
#define e 329
#define f 349
#define fS 370
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466

#define cH 523
#define cHS 554
#define dH 587
#define dHS 622
#define eH 659
#define fH 698
#define fHS 740
#define gH 784
#define gHS 830
#define aH 880
#define aHS 910
#define bH 933
using namespace std;
BOOL WINAPI Beep(
	DWORD dwFreq,
	DWORD dwDuration
	);
void Intro::lec(int &i)
{
	for (int x = 0; x <= i; x++)
	{
		cout << " ";
	}
}
void Intro::smu(int &i)
{
	for (int x = 0; x <= i; x++)
	{
		cout << "_";
	}
}
void Intro::stateczek(int i)
{
	smu(i); cout << "___________________.-----." << endl;
	lec(i); cout << "                   | |.-\  \\" << endl;
	lec(i); cout << "                   | ||_|\  \\" << endl;
	lec(i); cout << "                   | :   :  \\" << endl;
	lec(i); cout << "                   |  :___\   \\" << endl;
	lec(i); cout << "                   | _|   :___\\" << endl;
	lec(i); cout << "                   ||_|    \    \\" << endl;
	lec(i); cout << "                   ||_|    :    \\" << endl;
	lec(i); cout << "                   ||_| ____\____ \\" << endl;
	lec(i); cout << "                   |   |    :     \\" << endl;
	lec(i); cout << "                   | _ |     \      \\" << endl;
	lec(i); cout << "                   || ||     :     /" << endl;
	lec(i); cout << "                   || /-`.    \   /" << endl;
	lec(i); cout << "                    '-((((_|_---'-'" << endl;
	lec(i); cout << "                   _)____`.__`. ________" << endl;
	lec(i); cout << "                 ,'---.-. _...-/>._______." << endl;
	lec(i); cout << "             ____|____|_<__ __(/ (`.      `." << endl;
	lec(i); cout << "             / //    /   /,.\ | \  `._.------`." << endl;
	lec(i); cout << "              \_\\____\___\`'/_.___>.._ `,------`." << endl;
	lec(i); cout << "            |''  | '(_)|)   ||_    ``'-------'" << endl;
	lec(i); cout << "            |____|_____|    '--'--.---`'" << endl;
	lec(i); cout << "           /    /     /      \     \    \\" << endl;
	lec(i); cout << "          /    /    ,'      `.    `.   \\" << endl;
	lec(i); cout << "         /    /    /            \     \   \\" << endl;
	lec(i); cout << "        /    /   ,'             `.    \   \\" << endl;
	lec(i); cout << "       /``-,'._ /                 \    `.  \\" << endl;
	lec(i); cout << "      /   /   ,'                   `.    \  \\" << endl;
	lec(i); cout << "     /   /   /                        \ ___\__\\" << endl;
	lec(i); cout << "    /   /  ,'                        `. ____ \\" << endl;
	smu(i); cout << "___/   /  /_____________________________\______\\" << endl;
	lec(i); cout << "  /`-./_ /" << endl;
	lec(i); cout << " /`-._ ,'" << endl;
	smu(i); cout << "'-..__/" << endl;



}
void Intro::stateczku_lec(int i)
{
	system("CLS");
	stateczek(i);
}
void Intro::start()
{
	stateczku_lec(0);
	Beep(a, 500);
	Beep(a, 500);
	Beep(a, 500);
	Beep(f, 350);
	Beep(cH, 150);
	stateczku_lec(8);
	Beep(a, 500);
	Beep(f, 350);
	Beep(cH, 150);
	Beep(a, 1000);
	Beep(eH, 500);
	stateczku_lec(16);
	Beep(eH, 500);
	Beep(eH, 500);
	Beep(fH, 350);
	Beep(cH, 150);
	Beep(gS, 500);
	stateczku_lec(24);
	Beep(f, 350);
	Beep(cH, 150);
	Beep(a, 1000);
	Beep(aH, 500);
	Beep(a, 350);
	stateczku_lec(32);
	Beep(a, 150);
	Beep(aH, 500);
	Beep(gHS, 250);
	Beep(gH, 250);
	Beep(fHS, 125);
	
	Beep(fH, 125);
	Beep(fHS, 250);
	stateczku_lec(45);
	Sleep(250);
	
	Beep(aS, 250);
	Beep(dHS, 500);
	Beep(dH, 250);
	Beep(cHS, 250);
	Beep(cH, 125);
	stateczku_lec(56);
	Beep(b, 125);
	Beep(cH, 250);

	Sleep(250);

	Beep(f, 125);
	Beep(gS, 500);
	Beep(f, 375);
	Beep(a, 125);
	Beep(cH, 500);
	stateczku_lec(64);
	Beep(a, 375);
	Beep(cH, 125);
	Beep(eH, 1000);
	Beep(aH, 500);
	Beep(a, 350);
	stateczku_lec(72);
	Beep(a, 150);
	Beep(aH, 500);
	Beep(gHS, 250);
	Beep(gH, 250);
	Beep(fHS, 125);

	Beep(fH, 125);
	Beep(fHS, 250);
	stateczku_lec(80);
	Sleep(250);

	Beep(aS, 250);
	Beep(dHS, 500);
	Beep(dH, 250);
	Beep(cHS, 250);
	Beep(cH, 125);

	Beep(b, 125);
	Beep(cH, 250);

	Sleep(250);

	Beep(f, 250);
	Beep(gS, 500);
	Beep(f, 375);
	Beep(cH, 125);
	Beep(a, 500);

	Beep(f, 375);
	Beep(c, 125);
	Beep(a, 1000);

}


