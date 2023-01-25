#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

void push(struct Stack *&MyStack);
void clearStack(struct Stack *&MyStack);
short int menu();
void showStack(Stack*& MyStack);
void clearStack(Stack*& MyStack);
void findRepeat(Stack* MyStack);
void WriteInFile(Stack* MySt);
void ReadFromFile(Stack* MySt);