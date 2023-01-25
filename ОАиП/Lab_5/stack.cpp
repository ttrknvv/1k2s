#include "stdafx.h"
#include "stack.h"
void push(struct Stack*& MyStack) {
	char chislo[9];
	cout << "Чтобы закончить, введите q\nВвод: ";
	while (cin >> chislo && *chislo != 'q') {
		Stack* data = new Stack;
		data->number = atoi(chislo);
		data->next = MyStack->head;
		MyStack->head = data;
	}
	cout << "Стек записан!\n";
	return ;
}
short int menu() {
	cout << "0) Выход из приложения\n1) Запись чисел в стек\n" <<
		"2) Подсчет количества повторяющихся элементов стека\n3) Очистка стека\n4) Вывод стека"
		<< "\n5) Запись стека в файл\n6)Считать стек из файла\nВаш выбор: ";
	return 1;
}
void showStack(Stack*& MyStack) {
	Stack* data = MyStack->head;
	if (!MyStack->head) { cout << "Стек пуст\n"; }
	else { cout << "Вывод стека: \n"; }
	while (data) {
		cout << data->number << "\n";
		data = data->next;
	}
}
void findRepeat(Stack* MySt) {
	if (!MySt->head) { cout << "Стек пуст\n"; }
	else {
		Stack* MyStack = new Stack;
		MyStack->head = MySt->head;
		int const N = 20;
		int Array[N];
		for (int i = 0; i < N; i++) {
			Array[i] = INT32_MAX;
		}
		int k = 0;
		while (MyStack->head) {
			Array[k] = MyStack->head->number;
			MyStack->head = MyStack->head->next;
			k++;
		}
		for (int i = 0; i < N - 1; i++) {
			for (int j = 1; j < N - i; j++) {
				if (Array[j - 1] > Array[j]) { swap(Array[j - 1], Array[j]); }
			}
		}
		k = 0;
		int counter = 0;
		while (Array[k] != INT32_MAX) {
			cout << Array[k] << " ";
			if (Array[k] == Array[k + 1]) { counter++; }
			k++;
		}
		if (counter) { cout << "\nЧисло повторяющихся пар элементов: " << counter << endl; }
		else { cout << "\nПовторяющихся элементов в стеке нет!\n"; }
	}
}
void WriteInFile(Stack* MySt) {
	if (!MySt->head) { cout << "Стек пустой\n"; }
	else {
		ofstream FILE;
		FILE.open("DATA.txt");
		Stack* MyStack = new Stack;
		MyStack->head = MySt->head;
		FILE << "Вывод стека: ";
		while (MyStack->head) {
			FILE << "\n\t\t" << MyStack->head->number;
			MyStack->head = MyStack->head->next;
		}
		cout << "Стек выведен в файл DATA.txt\n";
		FILE.close();
	}
}
void ReadFromFile(Stack* MySt) {
	int indicate;
	ifstream FILE;
	FILE.open("DATA.txt", ofstream::app);
	if (!(FILE >> indicate)) { cout << "Файл пуст\n"; }
	else {
		while (indicate) {
			Stack* data = new Stack;
			data->number = indicate;
			data->next = MySt->head;
			MySt->head = data;
			if (!(FILE >> indicate)) { break; }
		}
		cout << "Данные считаны!\n";
	}
	FILE.close();
}

