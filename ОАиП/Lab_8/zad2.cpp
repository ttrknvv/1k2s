#include <iostream>

using namespace std;

unsigned short S(unsigned short x);

int main() {
	setlocale(LC_ALL, "rus");
	unsigned short x;
	cout << "Введите x: ";
	cin >> x;
	cout << "Вывод S(x): ";
	cout << S(x);
	return 0;
}

unsigned short S(unsigned short x) {
	if (x > 100) { return x + 10; }
	else { return S(S(x + 4)); }
}