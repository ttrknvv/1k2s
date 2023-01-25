#include <iostream>
#include <windows.h>
#include <chrono>

using namespace std;

void menu(); // меню
void inputData(short size); // ввод данных
short hashFUNC(int key, short size); // хэш - функция
void printData(short size); // вывод
void findData(short size); // поиск элемента
void deleteData(short size); // удаление элемента

struct Own {
	int phoneNumber = 0; // телефон - ключ
	char ownerName[50] = {}; // имя владельца
	Own *pNext = nullptr; // указатель при коллизии
};

Own* Numbers;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	short size, choise;
	cout << "Введите количество данных: ";
	cin >> size;
	Numbers = new Own[size];
	do {
		menu();
		cin >> choise;
		switch (choise) {
			case 0: break;
			case 1: inputData(size);
					break;
			case 2: findData(size);
					break;
			case 3: deleteData(size);
					break;
			case 4: printData(size);
					break;
		}
	} while (choise);

	return 0;
}
void menu() {
	cout << "1 - Ввести данные\n2 - Поиск элемента\n3 - Удаление элемента\n4 - Вывод элементов\n0 - Выход\n" 
		<< "-----------------------------------------------------\nВаш выбор : ";
}
void inputData(short size) {
	int phone, hash;
	Own* next;
	cout << "Введите номер телефона: "; cin >> phone;
	hash = hashFUNC(phone, size);
	if (Numbers[hash].phoneNumber == 0) {
		Numbers[hash].phoneNumber = phone; cin.ignore();
		cout << "Введите ФИО владельца: "; cin.getline(Numbers[hash].ownerName, 50);
		return;
	}
	next = &Numbers[hash];
	while (next->pNext) {
		next = next->pNext;
	}
	next->pNext = new Own; cin.ignore();
	next->pNext->phoneNumber = phone;
	cout << "Введите ФИО владельца: "; cin.getline(next->pNext->ownerName, 50);
}
short hashFUNC(int key, short size) {
	return key % size;
}
void printData(short size) {
	Own* next;
	for (int i = 0; i < size; i++) {
		cout << "Номер ячейки(HASH): " << i << "\n";
		cout << "Номер телефона: " << Numbers[i].phoneNumber << "\n";
		cout << "Владелец: " << Numbers[i].ownerName << "\n";
		next = Numbers[i].pNext;
		while (next) {
			cout << "\nНомер телефона: " << next->phoneNumber;
			cout << "\nВладелец: " << next->ownerName << "\n";
			next = next->pNext;
		}
		cout << "\n-----------------------------------------------\n";
	}
}
void findData(short size) {
	int phone, hash;
	cout << "Введите телефон элемента: "; cin >> phone;
	auto start = chrono::high_resolution_clock::now();
	hash = hashFUNC(phone, size);
	if (Numbers[hash].phoneNumber == phone) {
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float>duration = end - start;
		cout << "Найденные данные:\n";
		cout << "-----------------------------------------------\n";
		cout << "Номер ячейки(HASH): " << hash << "\n";
		cout << "Номер телефона: " << Numbers[hash].phoneNumber << "\n";
		cout << "Владелец: " << Numbers[hash].ownerName << "\n";
		cout << "-----------------------------------------------\n";
		cout << "Время поиска: " << duration.count() << " секунд\n";

		return;
	}
	else if(Numbers[hash].phoneNumber != 0) {
		Own* next = &Numbers[hash];
		while (next->pNext) {
			if (next->pNext->phoneNumber == phone) {
				cout << "Найденные данные:\n";
				cout << "-----------------------------------------------\n";
				cout << "Номер ячейки(HASH): " << hash << "\n";
				cout << "Номер телефона: " << next->pNext->phoneNumber << "\n";
				cout << "Владелец: " << next->pNext->ownerName << "\n";
				cout << "-----------------------------------------------\n";
				auto end = chrono::high_resolution_clock::now();
				chrono::duration<float>duration = end - start;
				cout << "Время поиска: " << duration.count() << " секунд\n";
				return;
			}
			next = next->pNext;
		}
	}
	cout << "Данные не найдены!\n";
}
void deleteData(short size) {
	int phone, hash;
	cout << "Введите телефон для удаления: "; cin >> phone;
	hash = hashFUNC(phone, size);
	if (Numbers[hash].phoneNumber == phone) {
		if (Numbers[hash].pNext == nullptr) {
			*Numbers[hash].ownerName = {};
			Numbers[hash].phoneNumber = 0;
			cout << "\nУдаление успешно!\n";
			return;
		}
		else {
			Own* del;
			del = Numbers[hash].pNext; 
			swap(Numbers[hash], *Numbers[hash].pNext);
			delete del;
			cout << "\nУдаление успешно!\n";
			return;
		}
	}
	else if (Numbers[hash].phoneNumber != phone) {
		Own* next = &Numbers[hash];
		while (next->pNext) {
			if (next->pNext->phoneNumber == phone) {
				if (next->pNext->pNext != nullptr) {
					Own* del;
					del = next->pNext;
					next->pNext = next->pNext->pNext;
					delete del;
					cout << "\nУдаление успешно!\n";
					return;
				}
				else {
					delete next->pNext;
					next->pNext = nullptr;
					cout << "\nУдаление успешно!\n";
					return;
				}
			}
			next = next->pNext;
		}
	}
	cout << "Данные не найдены!\n";
}