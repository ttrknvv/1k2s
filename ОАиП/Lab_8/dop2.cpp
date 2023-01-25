// dop3
#include <iostream>
#include<tchar.h>

using namespace std;

const int z = 5;
int a[z];
void perm(int k) {
	int q, j, t, p;
	for (q = 0; q < z - k; q++) {
		if (k < z - 2)
			perm(k + 1);
		else {
			for (p = 0; p < z; p++)
				cout << " " << a[p];
			cout << endl;
		}
		t = a[k];
		for (j = k + 1; j < z; j++)
			a[j - 1] = a[j];
		a[j - 1] = t;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int q;
	cout << "Введите числа(" << z << "): ";
	for (q = 0; q < z; q++)
		cin >> a[q];
	perm(0);
}