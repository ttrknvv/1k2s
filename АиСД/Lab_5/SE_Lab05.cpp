#include <iostream>
#include <windows.h>
#include <stack>			// библиотека <stack>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	stack <char> Elements;  // объявление структуры stack типов char
	char hooks[100] = {}; // массив для скобок
	int circle = 0, figure = 0, square = 0, i = 0;
	bool indicate = true;
	char el;
	cout << "Введите элементы(закончите ввод символом 'q'): ";
	cin >> el;
	while (el != 'q') {
		Elements.push(el);			// добавление элемента в стек
		cin >> el;
	}
	while (!Elements.empty() && indicate) {				// проверка на пустоту стека
		switch (Elements.top()) {				// взять верхний элемент   [ ( ] )
		case '(': hooks[i] = Elements.top();
				  i++;
				  break;
		case ')': hooks[i] = Elements.top();
				  i++;
				  break;
		case '{': hooks[i] = Elements.top();
				  i++;
				  break;
		case '}': hooks[i] = Elements.top();
				  i++;
				  break;
		case '[': hooks[i] = Elements.top();
				  i++;
				  break;
		case ']': hooks[i] = Elements.top();
				  i++;
				  break;
		} 
		Elements.pop();			// удалить верхний элемент
	}
	for (int j = 0; j < strlen(hooks); j++) {
		for (int k = i; k < strlen(hooks); k++) {
			
		}
	}
	if (Elements.empty() && i % 2 == 0 && i != 0) { cout << "Скобки расставлены правильно!"; }
	else if (i % 2 == 0 && i != 0) { cout << "Скобки расставлены неправильно!"; }
	else if (i == 0) { cout << "Скобок нет!"; }

	return 0;
}
