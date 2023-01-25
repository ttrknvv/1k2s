#include "stdafx.h"

int sum(int a, int b);
int mul(int a, int b);
int sub(int a, int b);

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	int vibor, a , b;
	cout << "Выберите функцию: 1) sum 2) sub 3) mul : ";
	cin >> vibor;
	switch (vibor){
		case 1: cout << "Введите 2 числа a и b: ";
				cin >> a;
				cin >> b;
				cout << "a + b = " << sum(a, b);
				break;
		case 2: cout << "Введите 2 числа a и b: ";
				cin >> a;
				cin >> b;
				cout << "a - b = " << sub(a, b);
				break;
		case 3: cout << "Введите 2 числа a и b: ";
			cin >> a;
			cin >> b;
			cout << "a * b = " << mul(a, b);
			break;
		default: cout << "Неправильный выбор функции! Попробуйте еще раз!";
				 main();
	}
	return 0;
}