#include "stdafx.h"
#include "SystemPlikowFAT.h"

void Sector::view(){
	for (int i = 0; i < 64; i++){
		cout << setw(4) << (int)data[i] << " ";
	}
	cout << endl;
}

void Sector::clear(int file){
	for (int i = file; i < i+16; i++) {
		data[i] = 0;							// czyszczenie wpisu katalogowego
	}
}

void Sector::view_properties(){
	if (data[0] != 0){							// plik
		for (int i = 0;i <= 7;i++) {			// nazwa pliku
			if (data[i] != 0) cout << data[i]; 
		}
		if (data[8] != 0){						// rozszerzenie pliku
			cout << ".";
			for (int i = 8;i <= 10;i++) {
				cout << data[i];
			}
		}
		cout << "  rozmiar: ";					// rozmiar pliku
		if (data[13] != 0) cout << (int)data[13];
		cout << (int)data[12];

	}
	else{										// pusty sektor
			cout << "Sektor jest pusty" << endl;
	}	
}

void Sector::fill(string content,int pointer){
	for (int i = pointer; i < content.length(); i++){
		data[i] = content[i];
	}
}

HardDrive::HardDrive(){
	for (int i = 0; i < 64; i++){
		for (int j = 0; j < 64; j++) {			
			sector_data[i].data[j] = 0;			// tablica FAT zapisana na 0 sektorze
			free_sectors.push_back(j);
		}
	}
	free_space = 4096 - (9 * 64);				// 1 sektor na FAT i 8 sektory na wpisy katalogowe (max 32 wpisy po 4 wpisy na sektor)
}

void HardDrive::calculate_free_space() {
	free_space = 4096 - (9 * 64);
	for (int i = 9; i < 64; i++) {
		if(sector_data[0].data[i] != 0)	free_space -= 64;
	}
}

void HardDrive::view_free_space() {
	cout << "Na dysku zostalo: " << free_space << "B wolnego miejsca." << endl;
}

bool HardDrive::sector_availability(int sector_No){
	if(sector_data[0].data[sector_No] == 0) return true;
	else return false;
}

void HardDrive::view_sektor(int numer){
	if (sector_availability(numer)){
		cout << "Sektor: " << numer << " jest wolny: " << endl;
	}
	else{
		cout << "Sektor: " << numer << " jest zajety: " << endl;
	}
	sector_data[numer].view();
}

string HardDrive::find_file_by_name(string name){
	string buff, buff2;
	size_t pos = name.find(".");
	buff = name.substr(0, pos);
	if (pos != string::npos) buff2 = name.substr(pos + 1);
	int correct=0, correct2=0;
	string sector;
	for (int i = 1;i < 9;i++) {
		for (int j = 0;j < 64;j += 16) {
			if (sector_data[i].data[j] != 0) {
				for (int s = 0;i < buff.length();s++) {
					if(sector_data[i].data[j + s] == name[s]) correct++;
				}
				for (int s = 0;i < buff2.length();s++) {
					if (sector_data[i].data[j + s+8] == name[s]) correct2++;
				}

				if ((correct==buff.length()) && (correct2 == buff2.length())) return sector=to_string(i)+","+to_string(j);
			}
		}
	}
	return sector;									//wartosc "" w momencie nie znalezienia pliku
}

string HardDrive::find_place_in_root_directory() {
	for (int i = 1;i < 9;i++) {
		for (int j = 0;j < 64;j += 16) {
			if (sector_data[i].data[j] == 0) return to_string(i) + "," + to_string(j);
		}
	}
	return "";
}

void HardDrive::create_file(string name){
	string place = find_place_in_root_directory();
	string buff, buff2;
	size_t pos = name.find(".");
	buff = name.substr(0, pos);
	if (pos != string::npos) buff2 = name.substr(pos + 1);

	if (find_file_by_name(name) != "")	{
		cout << "Nie mo¿na utworzyæ pliku o takiej samej nazwie!!!" << endl;
	}
	else if ((buff.length() <= 8) && (buff2.length() <= 3)){
		if (free_sectors.size() == 0){
			cout << "Dysk jest pelny!!!" << endl;
		}
		else{
			if (place != "") {
				string buff3, buff4;
				size_t poss = place.find(",");
				buff3 = place.substr(0, poss);
				buff4 = place.substr(poss + 1);
				int a = atoi(buff3.c_str());
				int b = atoi(buff4.c_str());

				for (int i = 0;i < buff.length();i++) {
					sector_data[a].data[b + i] = buff[i];
				}
				for (int i = 0;i < buff2.length();i++) {
					sector_data[a].data[b + i + 8] = buff2[i];
				}
			}
			else cout << "Nie mozna utworzyc wiecej plikow, ten system ma ograniczenie do 32 plikow !!!" << endl;
		}
	}
	else cout << "Plik nie zostal utworzony z powodu dlugiej nazwy!!!!" << endl;
	calculate_free_space();
}

void HardDrive::write_to_file(string name) {
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void HardDrive::write_to_file_from_file(string name, string path){ // sciezka do pliku znadujacego sie na naszym lokalnym dysku np.: C://Desktop//dane.txt
	string place = find_file_by_name(name);
	string buff, buff2;
	size_t pos = place.find(",");
	buff = place.substr(0, pos);
	if (pos != string::npos) buff2 = place.substr(pos + 1);

	string buff3, buff4;
	size_t poss = place.find(",");
	buff3 = place.substr(0, poss);
	buff4 = place.substr(poss + 1);
	int a = atoi(buff3.c_str());
	int b = atoi(buff4.c_str());

	string cur_size = to_string((int)sector_data[a].data[b + 13]) + to_string((int)sector_data[a].data[b + 12]);
	int current_size = atoi(cur_size.c_str());

	string cur_pointer = to_string((int)sector_data[a].data[b + 15]) + to_string((int)sector_data[a].data[b + 14]);
	int current_pointer = atoi(cur_size.c_str());

	ifstream r_file(path);
	string data_from_file;
	getline(r_file, data_from_file);
	int size = data_from_file.size();
	if (place == ""){
		cout << "Plik o podanej nazwie nie istnieje." << endl;
	}
	else if (size == 0){
		cout << "Plik jest pusty, badz nie istnieje" << endl;
	}
	else if ((size+current_size) > 1024){
		cout << "Plik jest zaduzy by zapisac go na tym systemie. Maksymalny rozmiar pliku to 1kB" << endl;
	}
	else{
		if (free_space > size)	{
			if ((current_pointer == 0) && (sector_data[a].data[b + 11]==0)) {
				list<int>::iterator it = free_sectors.begin();
				sector_data[a].data[b + 11] = *it;
				sector_data[0].data[*it] = 1;							// 1 to oznaczenie ostatniego zapisanego sektoru
				free_sectors.pop_front();
			}
			else {				
				int	JAP = sector_data[a].data[b + 11];
				while (JAP != 1) {
					JAP = sector_data[0].data[JAP];
				}
				for (int i = 0;i < ceil((double)size / 64);i++) {
					if (current_pointer == 0) {
						list<int>::iterator it = free_sectors.begin();
						sector_data[0].data[JAP] = *it;
						sector_data[0].data[*it] = 1;
						free_sectors.pop_front();
					}
					for (int j = current_pointer;j < 64;j++) {
						sector_data[JAP].data[j] = data_from_file[i];
					}
					current_pointer = 0;
				}
			}
			current_pointer = size - (floor((double)size / 64)*64);
			
			string pom_pointer = to_string(size);
			if (pom_pointer.length() < 3) sector_data[a].data[b + 14] = atoi(pom_pointer.c_str());
			else if (pom_pointer.length() < 4) {
				string pom_pointer_m = pom_pointer.substr(0, 0);
				string pom_pointer_l = pom_pointer.substr(1, 2);
				sector_data[a].data[b + 14] = atoi(pom_pointer_l.c_str());
				sector_data[a].data[b + 15] = atoi(pom_pointer_m.c_str());
			}
			else {
				string pom_pointer_m = pom_pointer.substr(0, 1);
				string pom_pointer_l = pom_pointer.substr(2, 3);
				sector_data[a].data[b + 14] = atoi(pom_pointer_l.c_str());
				sector_data[a].data[b + 15] = atoi(pom_pointer_m.c_str());
			}

			size += current_size;			
			string pom_size = to_string(size);
			if (pom_size.length() < 3) sector_data[a].data[b + 12] = atoi(pom_size.c_str());
			else if (pom_size.length() < 4) {
				string pom_size_m = pom_size.substr(0, 0);
				string pom_size_l = pom_size.substr(1, 2);
				sector_data[a].data[b + 12] = atoi(pom_size_l.c_str());
				sector_data[a].data[b + 13] = atoi(pom_size_m.c_str());
			}
			else {
				string pom_size_m = pom_size.substr(0, 1);
				string pom_size_l = pom_size.substr(2, 3);
				sector_data[a].data[b + 12] = atoi(pom_size_l.c_str());
				sector_data[a].data[b + 13] = atoi(pom_size_m.c_str());
			}

			cout << "Zapisano dane do pliku: " << name << "." << endl;
		}else{
			cout << "Na dysku nie ma wystarczajacej ilosci wolnej pamieci do zapisania danych." << endl;
		}
	}
	calculate_free_space();	
}

void HardDrive::delete_file(int sector_No){
	////////////////////////////////////////////////////////////////////////////////////////////////////
	if (sector_No == 0)
	{
		cout << "Tablica FAT, nie da sie jej usunac." << endl;
	}
	else
	{


		cout << "Usunieto!!!" << endl;
	}
	calculate_free_space();
}

void HardDrive::view_files(){
	////////////////////////////////////////////////////////////////////////////////////////////////////
}

void HardDrive::view_harddrive(){
	////////////////////////////////////////////////////////////////////////////////////////////////////
}

void HardDrive::open_file(string name){
	////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
}
