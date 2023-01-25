#include <iostream>
#include <windows.h>

using namespace std;

int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] < brd);
		while (A[++i] > brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
int* sortHoar(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	return A;
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int A[20], B[20];
	int size, maxA = 0, numbA;
	cout << "Введите размер массива: "; cin >> size;
	cout << "Введите массив: ";
	for (int i = 0; i < size; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < size; i++) {
		if (maxA < A[i]) {
			maxA = A[i];
			numbA = i;
		}
	}
	for (int i = 0, j = 0; i < size - numbA; i++) {
		if ((numbA + i) % 2 == 0) {
			B[j] = A[numbA + i];
			j++;
		}
	}
	cout << "Сортировка пузырьком: ";
	/*for (int i = 0; i < (size - numbA) / 2; i++) {
		for (int j = 0; j < (size - numbA) / 2; j++) {
			if (B[j] < B[j + 1]) { swap(B[j], B[j + 1]); }
		}
	}
	for (int i = 0; i < (size - numbA) / 2; i++) {
		cout << B[i] << " ";
	}*/

	cout << "Сортировка Хоаром: ";
	sortHoar(B, 0, (size - numbA) / 2 - 1);
	for (int i = 0; i < (size - numbA) / 2; i++) {
		cout << B[i] << " ";
	}
	return 0;
}