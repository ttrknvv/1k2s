#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <chrono>

using namespace std;

void zapolnenie(int*& Arr, int*& Brr, int*& Crr, int*& Drr, int*& Err, int N);
void outputArray(int* Arr, int N);
void bubbleSort(int* Arr, int N);
void insertionSort(int* Brr, int N);
void ShallSort(int* Crr, int N);
void ChoiseSort(int* Drr, int N);
void quickSort(int* Err, int first, int last);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N; int Airr[5] = { 5, 4, 3, 2, 1 };
	int* Arr, * Brr, * Crr, * Drr, * Err;
	cout << "Введите размер массива: ";
	cin >> N; cout << endl;
	Arr = new int[N];
	zapolnenie(Arr, Brr, Crr, Drr, Err, N); // заполнение случайными данными
	
	cout << "Исходный массив A: \n\n";
	outputArray(Arr, N); // вывод массива
	cout << "\n" << setfill('-') << setw(120) << '-' << "\n\n";
	
	auto start = chrono::high_resolution_clock::now();
	bubbleSort(Arr, N); // пузырьковая сортировка
	auto end = chrono::high_resolution_clock::now();;
	cout << "Отсортированный методом пузырька: \n";
	outputArray(Arr, N);
	chrono::duration<float>time = end - start;
	cout << "\nЗатраченное время: " << time.count() * pow(10,3);
	cout << "\n" << setfill('-') << setw(120) << '-' << "\n\n";

	start = chrono::high_resolution_clock::now();
	insertionSort(Brr, N); // сортировка методом вставок
	end = chrono::high_resolution_clock::now();
	cout << "Отсортированный методом вставок: \n";
	outputArray(Brr, N);
	time = end - start;
	cout << "\nЗатраченное время: " << time.count() * pow(10, 3);
	cout << "\n" << setfill('-') << setw(120) << '-' << "\n\n";

	start = chrono::high_resolution_clock::now();
	ShallSort(Crr, N); // сортировка методом Шэлла
	end = chrono::high_resolution_clock::now();
	cout << "Отсортированный методом Шэлла: \n";
	outputArray(Crr, N);
	time = end - start;
	cout << "\nЗатраченное время: " << time.count() * pow(10, 3);
	cout << "\n" << setfill('-') << setw(120) << '-' << "\n\n";

	start = chrono::high_resolution_clock::now();
	ChoiseSort(Drr, N); // сортировка выбором
	end = chrono::high_resolution_clock::now();
	cout << "Отсортированный методом выбора: \n";
	outputArray(Drr, N);
	time = end - start;
	cout << "\nЗатраченное время: " << time.count() * pow(10, 3);
	cout << "\n" << setfill('-') << setw(120) << '-' << "\n\n";

	start = chrono::high_resolution_clock::now();
	quickSort(Err, 0, N-1); // быстрая сортировка
	end = chrono::high_resolution_clock::now();
	cout << "Отсортированный быстрой сортировкой: \n";
	outputArray(Err, N);
	time = end - start;
	cout << "\nЗатраченное время: " << time.count() * pow(10, 3);
	cout << "\n" << setfill('-') << setw(120) << '-' << "\n\n";

	delete[] Arr;
	delete[] Brr;
	delete[] Drr; // очистка динамической памяти
	delete[] Crr;
	delete[] Err;
	return 0;
}
void zapolnenie(int*& Arr, int*& Brr, int*& Crr, int*& Drr, int*& Err, int N) {
	Brr = new int[N];
	Crr = new int[N];
	Drr = new int[N];
	Err = new int[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		Arr[i] = rand() % 100;
		Brr[i] = Arr[i];
		Crr[i] = Arr[i];
		Drr[i] = Arr[i];
		Err[i] = Arr[i];
	}
}
void outputArray(int* Arr, int N) {
	for(int i = 0; i < N; i++) {
		cout << Arr[i] << " ";
	}
}
void bubbleSort(int* Arr, int N) {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N - i; j++) {    // сравнивает последовательно элементы попарно
			if (Arr[j] > Arr[j+1]) { swap(Arr[j], Arr[j+1]); }
		}
	}
}
void insertionSort(int* Brr, int N) {
	for (int i = 1; i < N; i++) {
		for (int j = i; j > 0 && Brr[j - 1] > Brr[j]; j--) { // берем один элемент и находим позицию для вставки
			swap(Brr[j - 1], Brr[j]);
		}
	}
}
void ShallSort(int* Crr, int N) {
	for (int d = N / 2; d > 0; d /= 2) { // сравнивает элементы стоящие на определенном расстоянии и заканчивает обычной сортировкой вставками
		for (int i = d; i < N; i++) {
			for (int j = i - d; j >= 0 && Crr[j] > Crr[j + d]; j -= d) {
				swap(Crr[j], Crr[j + d]);
			}
		}
	}
}
void ChoiseSort(int* Drr, int N) {
	int min, j;
	for (int i = 0; i < N-1; i++) {
		min = i;
		for (j = i+1; j < N; j++) { // находит самое маленькое и ставит на первую позицию и т. д.
			if (Drr[j] < Drr[min]) { min = j; }
		}
		if (min != i) { swap(Drr[i], Drr[min]); }
	}
}
void quickSort(int* Err, int first, int last) {
	int mid, count;
	int f = first, l = last;
	mid = Err[(f + l) / 2]; //вычисление опорного элемента, разделение на меньше, равно и больше, и рекурсивный повтор
	do
	{
		while (Err[f] < mid) { f++; }
		while (Err[l] > mid) { l--; }
		if (f <= l) 
		{
			swap(Err[l], Err[f]);
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) { quickSort(Err, first, l); }
	if (f < last) { quickSort(Err, f, last); }
}
