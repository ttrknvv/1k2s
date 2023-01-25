#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string otvet;
	int N, middle;
	cout << "Введите число N: ";
	cin >> N;
	int itterate = 1;
	int low = 0;
	int hight = N - 1;
	int* Array = new int [N];
	for (int i = 0; i < N; i++) { // сортировка массива
		Array[i] = i + 1;
	}
	while (low <= hight) {
		middle = low + (hight - low) / 2;
		cout << "Ваше число " << Array[middle] << "?\n";
		cout << "Ответ: ";
		cin >> otvet;
		if (otvet == "мало") {                             // бинарный (двоичный) поиск
			low = middle + 1;
		}
		else if (otvet == "много") {
			hight = middle - 1;
		}
		else if (otvet == "угадал") {
			cout << "Ура! Ваще число: " << Array[middle] << "\nЧисло шагов: " << itterate;
			
			return 0;
		}
		itterate++;
	}
	if (otvet != "угадал") {
		cout << "Вашего числа нет в заданном промежутке!";
	}
	delete[] Array;
	return -1;
}