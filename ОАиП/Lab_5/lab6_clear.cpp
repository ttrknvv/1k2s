#include "stdafx.h"
#include "stack.h"

void clearStack(Stack*& MyStack) {
	if (!MyStack->head) { cout << "Стек пуст!\n"; }
	else {
		while (MyStack->head) {
			Stack* delStack = MyStack->head;
			MyStack->head = MyStack->head->next;
			delete delStack;
		}
		cout << "Стек очищен!\n";
	}
}