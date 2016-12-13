#include "SystemPlikowFAT.h"

void Sector::view() {
	for (int i = 0; i < 64; i++) {
		cout << setw(4) << (int)data[i] << " ";
	}
	cout << endl;
}

void Sector::clear(int file) {
	for (int i = file; i < i + 16; i++) {
		data[i] = 0;							// czyszczenie wpisu katalogowego
	}
}

void Sector::view_properties() {
	if (data[0] != 0) {							// plik
		for (int i = 0;i <= 7;i++) {			// nazwa pliku
			if (data[i] != 0) cout << data[i];
		}
		if (data[8] != 0) {						// rozszerzenie pliku
			cout << ".";
			for (int i = 8;i <= 10;i++) {
				cout << data[i];
			}
		}
		cout << "  rozmiar: ";					// rozmiar pliku
		if (data[13] != 0) cout << (int)data[13];
		cout << (int)data[12];

	}
	else {										// pusty sektor
		cout << "Sektor jest pusty" << endl;
	}
}

void Sector::fill(string content, int pointer) {
	for (int i = pointer; i < content.length(); i++) {
		data[i] = content[i];
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HardDrive::calculate_free_space() {
	free_space = 4096 - (9 * 64);
	for (int i = 9; i < 64; i++) {
		if (sector_data[0].data[i] != 0)	free_space -= 64;
	}
}

string HardDrive::find_file_by_name(string name) {
	string buff, buff2;
	size_t pos = name.find(".");
	buff = name.substr(0, pos);
	if (pos != string::npos) buff2 = name.substr(pos + 1);
	int correct = 0, correct2 = 0;
	string sector;
	for (int i = 1;i < 9;i++) {
		for (int j = 0;j < 64;j += 16) {
			if (sector_data[i].data[j] != 0) {
				for (int s = 0;s < buff.length();s++) {
					if (sector_data[i].data[j + s] == buff[s]) correct++;
					else break;
				}
				for (int s = 0;s < buff2.length();s++) {
					if (sector_data[i].data[j + s + 8] == buff2[s]) correct2++;
					else break;

				}
				if ((correct == buff.length()) && (correct2 == buff2.length())) return sector = to_string(i) + "," + to_string(j);
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

void HardDrive::file_writing(string name, string content) {
	string place = find_file_by_name(name);

	string buff, buff2;
	size_t poss = place.find(",");
	buff = place.substr(0, poss);
	buff2 = place.substr(poss + 1);
	int a = atoi(buff.c_str());
	int b = atoi(buff2.c_str());

	string cur_size = to_string((int)sector_data[a].data[b + 13]) + to_string((int)sector_data[a].data[b + 12]);
	int current_size = atoi(cur_size.c_str());

	string cur_pointer = to_string((int)sector_data[a].data[b + 15]) + to_string((int)sector_data[a].data[b + 14]);
	int current_pointer = atoi(cur_size.c_str());
	current_pointer = current_pointer - (floor((double)current_pointer / 64) * 64);

	int size = content.size();
	if (place == "") {
		cout << "Plik o podanej nazwie nie istnieje." << endl;
	}
	else if (size == 0) {
		cout << "Plik jest pusty, badz nie istnieje." << endl;
	}
	else if ((size + current_size) > 1024) {
		cout << "Plik jest zaduzy by zapisac go na tym systemie. Maksymalny rozmiar pliku to 1kB" << endl;
	}
	else {
		if (free_space > size) {
			int s = 0;
			int	JAP = sector_data[a].data[b + 11];
			while (JAP != 1 && JAP != 0) {
				JAP = sector_data[0].data[JAP];
			}
			for (int i = 0;i < ceil((double)size / 64);i++) {
				if (sector_data[a].data[b + 11] == 1) {
					list<int>::iterator it = free_sectors.begin();
					sector_data[a].data[b + 11] = *it;
					JAP = *it;
					sector_data[0].data[*it] = 1;							// 1 to oznaczenie ostatniego zapisanego sektoru
					free_sectors.pop_front();
				}
				else if (current_pointer == 0) {
					list<int>::iterator it = free_sectors.begin();
					sector_data[0].data[JAP] = *it;
					JAP = *it;
					sector_data[0].data[*it] = 1;
					free_sectors.pop_front();
				}
				for (int j = current_pointer;(j < 64) && (s < content.size());j++) {
					sector_data[JAP].data[j] = content[s];
					current_pointer++;
					s++;
					if (j == 63) current_pointer = 0;
				}
			}
			string pom_pointer = to_string(size);
			if (pom_pointer.length() < 3) sector_data[a].data[b + 14] = atoi(pom_pointer.c_str());
			else if (pom_pointer.length() < 4) {
				string pom_pointer_m = pom_pointer.substr(0, 1);
				string pom_pointer_l = pom_pointer.substr(1, 2);
				sector_data[a].data[b + 14] = atoi(pom_pointer_l.c_str());
				sector_data[a].data[b + 15] = atoi(pom_pointer_m.c_str());
			}
			else {
				string pom_pointer_m = pom_pointer.substr(0, 2);
				string pom_pointer_l = pom_pointer.substr(2, 3);
				sector_data[a].data[b + 14] = atoi(pom_pointer_l.c_str());
				sector_data[a].data[b + 15] = atoi(pom_pointer_m.c_str());
			}

			size += current_size;
			string pom_size = to_string((int)ceil((double)size / 64) * 64);
			if (pom_size.length() < 3) sector_data[a].data[b + 12] = atoi(pom_size.c_str());
			else if (pom_size.length() < 4) {
				string pom_size_m = pom_size.substr(0, 1);
				string pom_size_l = pom_size.substr(1, 2);
				sector_data[a].data[b + 12] = atoi(pom_size_l.c_str());
				sector_data[a].data[b + 13] = atoi(pom_size_m.c_str());
			}
			else {
				string pom_size_m = pom_size.substr(0, 2);
				string pom_size_l = pom_size.substr(2, 3);
				sector_data[a].data[b + 12] = atoi(pom_size_l.c_str());
				sector_data[a].data[b + 13] = atoi(pom_size_m.c_str());
			}

			cout << "Zapisano dane do pliku: " << name << endl;
		}
		else {
			cout << "Na dysku nie ma wystarczajacej ilosci wolnej pamieci do zapisania danych." << endl;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

HardDrive::HardDrive() {
	for (int i = 0; i < 64; i++) {
		for (int j = 9; j < 64; j++) {
			sector_data[i].data[j] = 0;			// tablica FAT zapisana na 0 sektorze
			free_sectors.push_back(j);
		}
	}
	free_space = 4096 - (9 * 64);				// 1 sektor na FAT i 8 sektory na wpisy katalogowe (max 32 wpisy po 4 wpisy na sektor)
}

void HardDrive::create_file(string name) {
	string place = find_place_in_root_directory();
	string buff, buff2;
	size_t pos = name.find(".");
	buff = name.substr(0, pos);
	if (pos != string::npos) buff2 = name.substr(pos + 1);

	if (find_file_by_name(name) != "") {
		cout << "Nie mozna utworzyæ pliku o takiej samej nazwie!!!" << endl;
	}
	else if ((buff.length() <= 8) && (buff2.length() <= 3)) {
		if (free_sectors.size() == 0) {
			cout << "Dysk jest pelny!!!" << endl;
		}
		else {
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
				sector_data[a].data[b + 11] = 1;
			}
			else cout << "Nie mozna utworzyc wiecej plikow, ten system ma ograniczenie do 32 plikow !!!" << endl;
		}
	}
	else cout << "Plik nie zostal utworzony z powodu dlugiej nazwy!!!!" << endl;
	calculate_free_space();
}

void HardDrive::write_to_file(string name, string content) {
	file_writing(name, content);
	calculate_free_space();
}

void HardDrive::write_to_file_from_file(string name, string path) { // sciezka do pliku znadujacego sie na naszym lokalnym dysku np.: C://Desktop//dane.txt

	ifstream r_file(path);
	string data_from_file;
	getline(r_file, data_from_file);
	int size = data_from_file.size();

	file_writing(name, data_from_file);

	calculate_free_space();
}

void HardDrive::delete_file(string name) {
	string place = find_file_by_name(name);
	string buff, buff2;
	size_t poss = place.find(",");
	buff = place.substr(0, poss);
	buff2 = place.substr(poss + 1);
	int a = atoi(buff.c_str());
	int b = atoi(buff2.c_str());
	int sector = sector_data[0].data[sector_data[a].data[b + 11]];
	int pom;

	if (place != "") {

		if (sector_data[a].data[b + 11] != 1) {
			while (sector_data[0].data[sector] != 1) {
				pom = sector_data[0].data[sector];
				sector_data[0].data[sector] = 0;
				free_sectors.push_back(pom);
				sector = sector_data[0].data[pom];
			}
		}
		for (int i = 0;i < b + 16;i++) {
			sector_data[a].data[b + i] = 0;
		}
		cout << "Plik zostal usuniety" << endl;
		free_sectors.sort();
	}
	else cout << "Nie znaleziono pliku o padanej nazwie" << endl;

	calculate_free_space();
}

void HardDrive::view_files() {
	for (int i = 1;i < 9;i++) {
		for (int j = 0;j < 64;j += 16) {
			if (sector_data[i].data[j] != 0) {
				for (int z = j;z < 8 + j;z++) {
					if (sector_data[i].data[z] != 0) cout << sector_data[i].data[z];
				}
				if (sector_data[i].data[j + 8] != 0) cout << ".";
				for (int z = j + 8;z < 11 + j;z++) {
					if (sector_data[i].data[z] != 0) cout << sector_data[i].data[z];
				}

				cout << endl;
			}
		}
	}
}

void HardDrive::view_harddrive() {
	for (int i = 0;i < 64;i++) {
		cout << "Sektor " << i << endl;
		sector_data[i].view();
		getchar();
	}
}

void HardDrive::view_sector(int numer) {
	cout << "Sektor " << numer << endl;
	sector_data[numer].view();
}

void HardDrive::view_free_space() {
	cout << "Na dysku zostalo: " << free_space << "B wolnego miejsca." << endl;
}