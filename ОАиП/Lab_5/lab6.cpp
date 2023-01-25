#include "stdafx.h"
#include "stack.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number, vibor;
	Stack* MyStack = new Stack;
	MyStack->head = nullptr;
	while (menu() && cin >> vibor && vibor) {
		switch (vibor) {
		case 1: push(MyStack);
			break;
		case 2: findRepeat(MyStack);
			break;
		case 3: clearStack(MyStack);
			break;
		case 4: showStack(MyStack);
			break;
		case 5: WriteInFile(MyStack);
			break;
		case 6: ReadFromFile(MyStack);
			break;
		}
	}
}

