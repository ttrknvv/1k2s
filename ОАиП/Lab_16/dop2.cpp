// v7
#include <iostream>
#include <ctime>
using namespace std;
int* arrC = NULL;

void hoarasort(int* a, int first, int last)
{

	int i = first, j = last;
	double tmp, x = a[(first + last) / 2];

	do {
		while (a[i] > x)
			i++;
		while (a[j] < x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		hoarasort(a, i, last);
	if (first < j)
		hoarasort(a, first, j);
}

void bubbleSort(int* a, int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] < a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
}
void randomize(int* arr, int n)
{
	int i = 0;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << " ";

	}
	cout << endl;
}
int transfer(int* arr, int* arr2, int n, int n2)
{
	int j = 0;
	arrC = new int[n + n2];
	int buf = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
			arrC[j++] = arr[i];

	}
	for (int i = 0; i < n2; i++)
	{
		if (!(arr2[i] % 2 == 0))
			arrC[j++] = arr2[i];

	}
	return j;

}
void print(int* arr, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";

	}
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	int n, n2;
	cout << "Введите размер массива А :";
	cin >> n;
	int* arrA = new int[n];
	cout << "Введите размер массива B :";
	cin >> n2;
	int* arrB = new int[n2];

	randomize(arrA, n);
	randomize(arrB, n2);
	int j = transfer(arrA, arrB, n, n2);
	/*bubbleSort(arrC, j);
	cout << "Сортировка пузырьком: ";
	print(arrC, j);*/
	cout << "Сортировка Хоара: ";
	hoarasort(arrC, 0, j - 1);
	print(arrC, j);



}