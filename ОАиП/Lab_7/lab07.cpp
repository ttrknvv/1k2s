#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE] = {};
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};

void menu();
void input(Address*& Data, Address*& DataLast);
void deleteName(Address*& DataHead, Address*& DataLast);
void print(Address* DataHead, Address* DataLast);
void find(Address* DataHead);
void funclab(Address* DataHead);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Address* DataHead = nullptr;
	Address* DataLast = nullptr;
	char s[80];
	int c;
	do
	{
		menu();
		cin >> c;
		switch (c)
		{
		case 1:  input(DataHead, DataLast);
			break;
		case 2:  deleteName(DataHead, DataLast);
			break;
			  
		case 3:  print(DataHead, DataLast);
			break;
		case 4:  find(DataHead);
			  break;
		case 5:	 funclab(DataHead);
			break;
		} 
	} while (c);
	return 0;
}

void menu() {
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Подсчёта числа элементов списка с заданным значением x" << endl;
	cout << "0. Выход" << endl;
	cout << endl;
	cout << "Ваш выбор: ";
}
void input(Address*& DataHead, Address*& DataLast) {
	Address *spisok;
	short unsigned number;
	cout << "Введите количество элементов списка: ";
	cin >> number;
	for (int i = 0; i < number; i++) {
		spisok = new Address;
		cin.ignore();
		cout << "Введите имя: ";
		cin.getline(spisok->name, NAME_SIZE);
		cin.ignore();
		cout << "Введите название города: ";
		cin.getline(spisok->city, CITY_SIZE);
		spisok->next = DataHead;
		if (i != 0) { spisok->next->prev = spisok; }
		if (i == 0) { DataLast = spisok; }
		DataHead = spisok;
		spisok->prev = nullptr;
	}
}
void deleteName(Address*& DataHead, Address*& DataLast) {
	int indicate = 0;
	Address* dele;
	Address* DataH = DataHead;
	cout << "Введите имя для удаления: ";
	char name[30] = {};
	cin.ignore();
	cin.getline(name, 30);
	while (DataH) {
		for (int i = 0; i < 30; i++) {
			if (DataH->name[i] == name[i]) { indicate++; }
		}
		if (indicate == 30) { 
			dele = DataH;
			if (!DataH->next) {
				DataH->prev->next = DataH->next;
				DataLast = DataLast->prev;
			}
			else if (!DataH->prev) {
				DataH->next->prev = DataH->prev;
				DataHead = DataH->next;
			}
			else {
				DataH->prev->next = DataH->next;
				DataH->next->prev = DataH->prev;
			}
			delete dele;
			cout << "Удаление завершено!";
			break;
		}
		else { indicate = 0; }
		DataH = DataH->next;
	}
}
void print(Address* DataHead, Address* DataLast) {
	while (DataHead) {
		cout << "Имя - " << DataHead->name << endl;
		cout << "Город - " << DataHead->city << endl;
		DataHead = DataHead->next;
	}
}
void find(Address* DataHead) {
	int indicate = 0;
	char name[30] = {};
	cout << "Введите имя - ";
	cin.ignore();
	cin.getline(name, 30);
	while (DataHead) {
		for (int i = 0; i < 30; i++) {
			if (DataHead->name[i] == name[i]) { indicate++; }
		}
		if (indicate == 30) {
			cout << "Имя - " << DataHead->name;
			cout << "\nГород - " << DataHead->city;
			break;
		}
		else { indicate = 0; }
		DataHead = DataHead->next;
	}
}
void funclab(Address* DataHead) {
	char name[30] = {};
	int indicate = 0;
	int answer = 0;
	cin.ignore();
	cout << "Введите имя: ";
	cin.getline(name, 30);
	while (DataHead) {
		for (int i = 0; i < 30; i++) {
			if (DataHead->name[i] == name[i]) { indicate++; }
		}
		if (indicate == 30) {
			answer++;
			indicate = 0;
		}
		else { indicate = 0; }
		DataHead = DataHead->next;
	}
	if (answer) { cout << "Количество элементов: " << answer; }
	else { cout << "Ничего не найдено!"; }
}


