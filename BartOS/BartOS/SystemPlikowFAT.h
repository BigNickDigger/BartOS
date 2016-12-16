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
	char data[64];
	void view();											// funkcja wyswietlajaca sektor
	void clear(int file);									// funkcja czyszczaca sektor
};

class HardDrive {

private:
	Sector sector_data[64];
	int free_space;											// ilosc wolnego miejsca
	list<int> free_sectors;									// lista pustych sektorow
	void calculate_free_space();							// metoda obliczajaca ilosc wolnego miejsca na dysku
	string find_file_by_name(string name);					// metoda szukajaca pliku po nazwie
	string find_place_in_root_directory();					// metoda szujkajaca miejsca w root directory max 32 pliki
	void file_writing(string name, string content);			// metoda uzupelniajaca pliki danymi	

public:
	HardDrive();											// konstruktor tworzacy dysk skladajacy sie z 64 sektorow wypelniony 0		
	void create_file(string name);							// metoda tworzaca plik
	void write_to_file(string name, string content);			// metoda uzupelniajaca plik danymi z klawiatury 
	void write_to_file_from_file(string name, string path);	// metoda przepisujaca dane z pliku znajdujacego sie na lokalnym dysku do dysku symulowanego
	void delete_file(string name);							// metoda usuwajaca plik	
	int file_size(string name);								// metoda zwracajaca rozmiar pliku
	void view_files();										// metoda wyswieltajaca wszystkie pliki w postaci listy nazw
	void view_file_propertise(string name);					// metoda wyswietlajaca wlasciwosci pliku
	void view_harddrive();									// metoda wyswietlajaca wszystkie sektory w postaci liczbowej
	void view_sector(int sector_No);						// metoda wyswieltajaca konkretny sektor
	void view_free_space();									// metoda wyswietlajaca ilosc wolnego miejsca na dysku
	char* open_file(string name);							// metoda zwracajaca caly plik
};