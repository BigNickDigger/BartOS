#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <list>

using namespace std;

class Sector {
public:
	unsigned char data[64];
	void view();											// funkcja wyswietlajaca sektor
	void clear(int file);									// funkcja czyszczaca sektor
	void view_properties();									// funkcja pokazuj¹ca wlasciwosci pliku
	void fill(string content, int pointer);					// funkcja uzupelniajaca sektor danymi
};

class HardDrive{
private:
	Sector sector_data[64];
	int free_space;											// ilosc wolnego miejsca
	list<int> free_sectors;									// lista pustych sektorow
public:	
	HardDrive();											// konstruktor tworzacy dysk skladajacy sie z 64 sektorow wypelniony 0
	void calculate_free_space();							// funkcja obliczajaca ilosc wolnego miejsca na dysku
	void view_free_space();									// funkcja wyswietlajaca ilosc wolnego miejsca na dysku
	bool sector_availability(int sector_No);				// funkcja sprawdzajaca dostepnosc sektora
	void view_sektor(int numer);							// funkcja wyswieltajaca konkretny sektor
	string find_file_by_name(string name);					// funkcja szukajaca pliku po nazwie
	string find_place_in_root_directory();
	void create_file(string name);							// funkcja tworzaca plik
	void write_to_file(string name);						// funkcja uzupelniajaca plik danymi z klawiatury
	void write_to_file_from_file(string name, string path);	// funkcja przepisujaca dane z pliku znajdujacego sie na lokalnym dysku do dysku symulowanego
	void delete_file(int sector_No);						// funkcja usuwajaca plik
	void view_files();										// dunkcja wyswieltajaca wszystkie pliki w postaci listy nazw
	void view_harddrive();									// funkcja wyswietlajaca wszystkie sektory w postaci liczbowej
	void open_file(string name);							// funkcja otwierajaca plik 
};