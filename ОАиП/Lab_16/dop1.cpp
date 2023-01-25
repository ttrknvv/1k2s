// v5
#include <iostream>
#include <ctime>
using namespace std;
int* arrC = NULL;

void choicesSort(int* arrayPtr, int length_array) // сортировка выбором
{
	for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
	{
		int temp = arrayPtr[0]; // временная переменная для хранения значения перестановки
		for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
		{
			if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
			{
				temp = arrayPtr[repeat_counter];
				arrayPtr[repeat_counter] = arrayPtr[element_counter];
				arrayPtr[element_counter] = temp;
			}
		}
	}
}


void bubbleSort(int* a, int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] > a[j])
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
	bubbleSort(arrC, j);
	print(arrC, j);
	choicesSort(arrC, j);
	print(arrC, j);



}