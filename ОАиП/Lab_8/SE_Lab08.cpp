#include <iostream>

using namespace std;

unsigned short dnx(unsigned short n, unsigned short x);

int main() {
	unsigned short n, x;
	setlocale(LC_ALL, "rus");
	cout << "Введите число n: ";
	cin >> n;
	cout << "Введите число x: ";
	cin >> x;
	cout << "Вывод количества делителей числа " << n << " в диапазоне от 1 до " << x << ": ";
	cout << dnx(n, x);
	return 0;
}

unsigned short dnx(unsigned short n, unsigned short x) {
	if (x == 1) { return 1; }
	else if (!(n % x)) { return dnx(n, x - 1) + 1; }
	else if (n % x) { return dnx(n, x - 1) + 0; }
}