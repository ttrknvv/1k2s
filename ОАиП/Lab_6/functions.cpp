#include "stdafx.h"

void menu() {
	cout << "0) ����� �� ���������\n1) ���� �������\n2) ����� ��������� � �� �����������\n3) ���������� �������� �������\n" <<
		"4) �������� ��������� �������" <<
		"\n5) ������� ����������� � ������������ ������� �������\n��� �����: ";
}
void inputQueue(Queue *&elements, Queue *&begin, Queue *&end) {
	if (begin == NULL) {
		short int SIZE;
		cout << "������� ���������� ��������� �������: ";
		cin >> SIZE;
		int * Array = new int[SIZE];
		cout << "������� ��������: ";
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
	else { cout << "� ��� ��� ���� ����������� �������!\n"; }

}
void outputQueue(Queue* begin) {
	if (begin == NULL) { cout << "��� �������!\n"; }
	else {
		unsigned short i = 0;
		cout << "����� �������: ";
		while (begin != NULL) {
			cout << begin->negativeNumbers << " ";
			begin = begin->next;
			i++;
		}
		cout << endl << "���������� ��������� �������: " << i << endl;
	}
}
void inputElements(Queue*& elements, Queue*& end, Queue* begin) {
	if (begin == NULL) { cout << "��� �������!\n"; }
	else {
		short int number;
		cout << "������� ������������� �������: ";
		cin >> number;
		elements = new Queue;
		elements->next = NULL;
		elements->negativeNumbers = number;
		end->next = elements;
		end = elements;
		cout << "������� ��������!\n";
	}
}
void deleteQueue(Queue*& elements, Queue*& begin, Queue*& end) {
	if (begin == NULL) { cout << "������� ������!\n"; }
	else {
		Queue* delElem = new Queue;
		while (begin != NULL) {
			delElem = begin;
			begin = begin->next;
			delete delElem;
		}
		cout << "�������� ���������!\n";
	}
}
void MINandMAX(Queue* begin) {
	if (begin == NULL) { cout << "������� ������!\n"; }
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
		cout << "���������� ������� �������: " << max << "\n����������� ������� �������: " << min << endl;
	}
}