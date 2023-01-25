// dop1
#include <iostream>
#include<tchar.h>
#include<fstream>

using namespace std;

ofstream file1("file.txt");
int arr[256];
int A;
void ch(int k) {
	int i, j, t, p;
	for (i = 0; i < A - k; i++)
	{
		if (k < A - 2)
			ch(k + 1);
		else {
			for (p = 0; p < A; p++)
				file1 << arr[p];
			file1 << endl;
		}
		t = arr[k];
		for (j = k + 1; j < A; j++)
			arr[j - 1] = arr[j];
		arr[j - 1] = t;
	}

}

int  main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите цифру:";
	cin >> A;
	cout << endl;
	int i;
	for (i = 0; i < A; i++)
		arr[i] = i + 1;
	ch(0);
	file1.close();
	cout << "Данные записаны в файл." << endl;
}