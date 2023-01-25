#include "stdafx.h"

void menu() {
	cout << "0) Выход из программы\n1) Ввод очереди\n2) Вывод элементов с их количеством\n3) Добавление элемента очереди\n" <<
		"4) Удаление элементов очереди" <<
		"\n5) Вывести минимальный и максимальный элемент очереди\nВаш выбор: ";
}
void inputQueue(Queue *&elements, Queue *&begin, Queue *&end) {
	if (begin == NULL) {
		short int SIZE;
		cout << "Введите количество элементов очереди: ";
		cin >> SIZE;
		int * Array = new int[SIZE];
		cout << "Введите элементы: ";
		for (int i = 0; i < SIZE; i++) {
			cin >> Array[i];
		}
		for (int i = 0; i < SIZE; i++) {
			if (Array[i] < 0 && begin != NULL) {
				elements = new Queue;
				elements->negativeNumbers = Array[i];
				elements->next = NULL;
				end->next = elements;
				end = elements;
			}
			else if (Array[i] < 0 && begin == NULL) {
				elements = new Queue;
				elements->next = NULL;
				elements->negativeNumbers = Array[i];
				begin = end = elements;
			}
		}
		delete[]Array;
	}
	else { cout << "У вас уже есть заполненная очередь!\n"; }

}
void outputQueue(Queue* begin) {
	if (begin == NULL) { cout << "Нет очереди!\n"; }
	else {
		unsigned short i = 0;
		cout << "Вывод очереди: ";
		while (begin != NULL) {
			cout << begin->negativeNumbers << " ";
			begin = begin->next;
			i++;
		}
		cout << endl << "Количество элементов очереди: " << i << endl;
	}
}
void inputElements(Queue*& elements, Queue*& end, Queue* begin) {
	if (begin == NULL) { cout << "Нет очереди!\n"; }
	else {
		short int number;
		cout << "Введите отрицательный элемент: ";
		cin >> number;
		elements = new Queue;
		elements->next = NULL;
		elements->negativeNumbers = number;
		end->next = elements;
		end = elements;
		cout << "Элемент добавлен!\n";
	}
}
void deleteQueue(Queue*& elements, Queue*& begin, Queue*& end) {
	if (begin == NULL) { cout << "Очередь пустая!\n"; }
	else {
		Queue* delElem = new Queue;
		while (begin != NULL) {
			delElem = begin;
			begin = begin->next;
			delete delElem;
		}
		cout << "Удаление завершено!\n";
	}
}
void MINandMAX(Queue* begin) {
	if (begin == NULL) { cout << "Очередь пустая!\n"; }
	else {
		short int max = MINSHORT, min = MAXSHORT;
		while (begin != NULL) {
			if (begin->negativeNumbers > max) {
				max = begin->negativeNumbers;
			}
			if (begin->negativeNumbers < min) {
				min = begin->negativeNumbers;
			}
			begin = begin->next;
		}
		cout << "Наибольший элемент очереди: " << max << "\nНайименьший элемент очереди: " << min << endl;
	}
}