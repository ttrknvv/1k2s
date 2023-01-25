#include <iostream>

using namespace std;

#define DICTNAMEMAXSIZE 20		// максимальный размер имени словаря
#define ENTRYNAMEMAXSIZE 30   //   максимальная длина имени в словаре
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"


int defaultparm(int a, int b, int c, int d, int e, int j = 0, int k = 0) { // j и k параметры по умолчанию
	return (a + b + c + d + e + j + k) / 7;
}

struct Entry { // элемент словаря
	int id;  // уникальный идентификатор
	char name[ENTRYNAMEMAXSIZE] = {};  // символьная информация
};
struct Instance {  // экземпляр словаря
	char name[DICTNAMEMAXSIZE] = {};  // наименование словаря
	int maxsize;  // максимальная емкость словаря
	int size = 0;  // текущий размер словаря < DICTNAMEMAXSIZE
	Entry* dictionary;  // массив элементов словаря
};
void AddEntry(Instance& inst, Entry& ed) {
	bool compareSIZE = inst.size >= inst.maxsize;
	bool compareNAMES = strlen(ed.name) > ENTRYNAMEMAXSIZE;
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == ed.id) {
			throw THROW04;
		}
	}
	if (compareSIZE) {
		throw THROW03;
	}
	inst.dictionary[inst.size].id = ed.id;
	for (int i = 0; i < strlen(ed.name); i++) {
		inst.dictionary[inst.size].name[i] = ed.name[i];
	}
	inst.size++;

}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Для 5 параметров defaultparm: " << defaultparm(1, 2, 3, 4, 5) << endl;
	cout << "Для 7 параметров defaultparm: " << defaultparm(1, 2, 3, 4, 5, 6, 7); // изменение параметров по умолчанию на 6 и 7

	Instance students = { "Студенты", 20 };
	students.dictionary = new Entry[students.maxsize];
	Entry d1 = { 1, "Маша" }, d2 = { 2, "Петя" };
	AddEntry(students, d1); // _cdecl
	AddEntry(students, d2);
	return 0;
}

