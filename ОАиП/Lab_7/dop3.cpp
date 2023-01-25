﻿//N человек  располагаются  по кругу.  Начав отсчет от первого, удаляют каждого k-го, 
//смыкая круг после удаления. Определить порядок удаления людей из круга. Использовать линейный список.

#include <iostream>
#include <fstream>
using namespace std;

struct Address
{
	int id;
	Address* next;
	Address* prev;
};
void insert(Address* e, Address** phead, Address** plast)
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
Address* setElement()
{
	static int user_id = 0;
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	temp->id = user_id++;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void outputList(Address** phead, Address** plast)
{
	Address* t = *phead;
	while (t)
	{
		cout << t->id << endl;
		t = t->next;
	}
	cout << "" << endl;
}
bool delet(int id, Address** phead, Address** plast)
{
	struct Address* t = *phead;
	while (t)
	{
		if (id == t->id) break;
		t = t->next;
	}
	if (!t)
		return 0;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
		return 1;
	}
}
int main(void)
{
	int m, a;
	Address* head = NULL;
	Address* last = NULL;

	int length = 20;
	for (size_t i = 0; i < length; insert(setElement(), &head, &last), i++) {}
	outputList(&head, &last);
	int id = 0;
	int k = 5;

	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		cout << endl;
		cout << "1. Удалить к-го и определить порядок" << endl;
		cout << "0. Выход" << endl;
		cout << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			if (delet(id, &head, &last)) {
				cout << "Удален элемент с айди = " << id << endl;
				id += k;
				--length;
			}
			else {
				cout << "Удален элемент с айди = " << id << endl;
				id += 1;
			}
			outputList(&head, &last);
			if (id > length) id -= length;
			break;
		case 0:  exit(0);
		default: exit(1);
		}
	}
	system("pause");
	return 0;
}