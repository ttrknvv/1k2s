#include <iostream>
#include <windows.h>

using namespace std;

typedef char locate[50];
typedef long l_index;
typedef short int number;

struct mailingAddress {
	l_index index;
	locate country = {};
	locate locality = {};
	locate street = {};
	number house, frame, flat;
};

bool operator == (mailingAddress data1, l_index index) {
	return data1.index == index;
}

void operator >> (l_index index, mailingAddress& data) {
	data.index = index;
}

int main() {
	l_index index;
	unsigned short data, vibor;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	mailingAddress Europe[3] = { 220039, "Беларусь", "Минск", "Магистральная", 4, 2, 37,
								223604, "Беларусь", "Слуцк", "Жуковского", 6, 1, 2,
								360268, "Россия", "Москва", "Жукова", 3, 4, 68 };
	cout << "Введите индекс: ";
	cin >> index;
	for (int i = 0; i < 3; i++) {
		if (Europe[i] == index) {
			data = i;
			cout << "\nГород: " << (Europe + data)->locality;
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << endl << i << ") " << (Europe + i)->index;
	}
	cout << "\nВыберите, какой индекс поменять: ";
	cin >> vibor;
	cout << "\nВведите индекс: ";
	cin >> index;
	index >> Europe[vibor];
	cout << "\nИзмененная группа индексов: ";
	for (int i = 0; i < 3; i++) {
		cout << endl << i << ") " << (Europe + i)->index;
	}
	return 0;
}
