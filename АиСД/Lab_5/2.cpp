#include <iostream>
#include <windows.h>
#include <stack>			// библиотека <stack>

#define BKT1 '('
#define BKT2 '['
#define BKT3 '{'
#define BKT4 ')'
#define BKT5 ']'
#define BKT6 '}'

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	stack <char> Elements;  // объявление структуры stack типов char
	int i = 0;
	char el;
	cout << "Введите элементы(закончите ввод символом 'q'): ";
	cin >> el;
	while (el != 'q') {
		switch (el) {				// взять верхний элемент   
		case BKT1: Elements.push(el); // добавление элемента в стек
			i++;
			break;
		case BKT4: if (!Elements.empty() && BKT1 == Elements.top()) {
				Elements.pop();
		}
				 else { cout << "Скобки расставлены неправильно!";	return 0; }
			break;
		case BKT3: Elements.push(el); // заполнение стека и вынесение скобок в массив
			i++;
			break;
		case BKT6: if (!Elements.empty() && BKT3 == Elements.top()) {
			Elements.pop();
		}
				 else { cout << "Скобки расставлены неправильно!"; return 0; }
			break;
		case BKT2: Elements.push(el);
			i++;
			break;
		case BKT5: if (!Elements.empty() && BKT2 == Elements.top()) {
			Elements.pop();
		}
				 else { cout << "Скобки расставлены неправильно!"; return 0; }
			break;
		}
		cin >> el;
	}
	if (Elements.empty()) { cout << "Скобки расставлены правильно!"; }
	else if (i == 1 || !Elements.empty()) { cout << "Скобки расставлены неправильно!"; }
	return 0;
}
