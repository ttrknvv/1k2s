#include <iostream>
#include <windows.h>
#include <ctime>

void cycle(int n);
int recursion(int n);

using namespace std;

int main() {
	int vibor;
	unsigned long recur = 0;
	unsigned long n, i;
	unsigned long start_time, end_time;

	SetConsoleOutputCP(1251);

	cout << "Выберите способ вывода n-го числа Фибоначчи:" <<
			"\n 1 - цикл \n 2 - рекурсия\nВаш выбор: ";
	cin >> vibor;
	switch (vibor) {
		case 1: 
				cout << "Введите n-ое число: ";
				cin >> n; 
				cout << "\nЦиклом:\n";
				cycle(n);
				break;
		case 2: cout << "Введите n-ое число: ";
				cin >> n; 
				cout << "\nРекурсией:\n";
				start_time = clock();
				for (i = n, n = 0; n < i; n++) {
					cout << recursion(n) << " ";
					recur = recursion(n);
				}
				cout << "\nВаше n-ое число: " << recur;
				end_time = clock();
				cout << "\nРасчетное время циклом " 
					<< (end_time - start_time) << " миллисекунд";
				break;
		default: cout << "Неправильный ввод. Попробуйте еще раз!\n";
				 main();
	}
}
void cycle(int n) {
	unsigned long long first = 0;
	unsigned long long second = 1, third = 0;
	unsigned long end_time, start_time;
	cout << first << " " << second;
	start_time = clock();
	for (int i = 3; i <= n; i++) {
		third = first + second;
		first = second;
		second = third;
		cout << " " << third;
	}
	end_time = clock();
	cout << "\nРасчетное время циклом "
		<< (end_time - start_time) << " миллисекунд";
	cout << "\nВаше n-ое число: " << third;
}
int recursion(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return(recursion(n-1) + recursion(n-2));
}