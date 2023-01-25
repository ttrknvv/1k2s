#include <iostream>
#include <windows.h>
#include <ctime> 

using namespace std;

void quickSort(int*& Array, int first, int last);
void falseSort(int*& Array, int SIZE);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int SIZE, *Array;
	cout << "Добро пожаловать в магазин ФИТ-Аудио!\nТолько сегодня каждый второй товар – бесплатно.\n" <<
		"Введите число товаров: ";
	cin >> SIZE;
	Array = new int[SIZE];
	srand(time(NULL));
	cout << "Цены на заданное число товаров: ";
	for (int i = 0; i < SIZE; i++) {
		Array[i] = 1 + rand() % 100;
		cout << Array[i] << " ";
	}
	quickSort(Array, 0, SIZE - 1);
	cout << "\nПолучившийся массив цен: ";
	falseSort(Array, SIZE);	
	delete[]Array;
	return 0;
}

void quickSort(int*& Array, int first, int last) {
	int mid, count;
	int f = first;
	int l = last;
	mid = Array[(f + l) / 2];
	do {
		while (Array[f] < mid) { f++; }
		while (Array[l] > mid) { l--; }
		if (f <= l) {
			swap(Array[l], Array[f]);
			f++; l--;
		}
	} while (f < l);
		if (first < l) { quickSort(Array, first, l); };
		if (f < last) { quickSort(Array, f, last); };
}
void falseSort(int*& Array, int SIZE) {
	int mid = SIZE / 2;
	int money = 0;
	for (int i = 0; i < mid; i++) {
		cout << Array[SIZE - i - 1] << " " << Array[i] << " ";
		money += Array[SIZE - i - 1];
	}
	if (SIZE % 2 != 0) { cout << Array[mid];
	money += Array[mid];
	}
	cout << "\nДеньги: " << money;
}
