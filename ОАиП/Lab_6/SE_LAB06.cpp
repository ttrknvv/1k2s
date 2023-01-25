#include "stdafx.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int vibor = 1;
	Queue *elements, * end;
	Queue * begin = NULL;
	do {
		menu();
		cin >> vibor;
		switch (vibor) {
		case 0: cout << "Выход из программы...";
			break;
		case 1: inputQueue(elements, begin, end);
			break;
		case 2: outputQueue(begin);
			break;
		case 3: inputElements(elements, end, begin);
			break;
		case 4: deleteQueue(elements, begin, end);
			break;
		case 5: MINandMAX(begin);
				break;
		default: cout << "Неправильно введен номер!\n";
		}
	} while (vibor);
	return 0;
}