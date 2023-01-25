#pragma once
#include <iostream>
#include <windows.h>

struct Queue {
	int negativeNumbers;
	Queue* next;
};

using namespace std;

void menu();
void inputQueue(Queue*& elements, Queue*& begin, Queue*& end);
void outputQueue(Queue* begin);
void inputElements(Queue*& elements, Queue*& end, Queue* begin);
void deleteQueue(Queue*& elements, Queue*& begin, Queue*& end);
void MINandMAX(Queue* begin);