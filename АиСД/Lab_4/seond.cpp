#include <iostream>
#include <windows.h>

using namespace std;

void quickSort(int*& Array, int first, int last);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int* Array;
	int SIZE;
	int step, max;
	int student = 1;
	cout << "Введите количество участников: ";
	cin >> SIZE;
	Array = new int[SIZE];
	cout << "\nВведите массив оценок учатсников: ";
	for (int i = 0; i < SIZE; i++) {
		cin >> Array[i];
	}
	quickSort(Array, 0, SIZE - 1);
	cout << "\nВведенные оценки: ";
	for (int i = 0; i < SIZE; i++) {
		cout << Array[i] << " ";
	}
	max = Array[0];
	step = 1;
	for (int i = 1; i < SIZE; i++) {
		if (Array[i] == max) {
			student++;
		}
		else if (step < 3) {
			step++;
			student++;
			max = Array[i];
		}
	}
	cout << "\nКоличество призеров: " << student;
	delete[]Array;
	return 0;
}

void quickSort(int*& Array, int first, int last) {
	int mid, count;
	int f = first;
	int l = last;
	mid = Array[(f + l) / 2];
	do {
		while (Array[f] > mid) { f++; }
		while (Array[l] < mid) { l--; }
		if (f <= l) {
			swap(Array[l], Array[f]);
			f++; l--;
		}
	} while (f < l);
	if (first < l) { quickSort(Array, first, l); };
	if (f < last) { quickSort(Array, f, last); };
}