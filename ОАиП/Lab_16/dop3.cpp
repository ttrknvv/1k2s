// v16
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
}
int transfer(int* arr, int n)
{
	int max = 0;
	int max_id = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			max_id = i;

		}

	}
	arrC = new int[(n - max_id) / 2];
	cout << endl << "Массив B:" << endl;
	int j = 0;
	for (int i = max_id; i < n; i++)
	{
		if (!(i % 2 == 0))
		{
			arrC[j] = arr[i];
			cout << arrC[j++] << " ";
		}
	}
	return ((n - max_id) / 2);

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

	int n;
	cout << "Введите размер массива А :";
	cin >> n;
	int* arrA = new int[n];

	randomize(arrA, n);
	int j = transfer(arrA, n);
	bubbleSort(arrC, j);
	cout << "\nСортировка пузырьком: ";
	print(arrC, j);
	cout << "\nСортировка Хоара: ";
	hoarasort(arrC, 0, j - 1);
	print(arrC, j);



}