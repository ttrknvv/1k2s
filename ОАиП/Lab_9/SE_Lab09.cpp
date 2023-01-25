#include <iostream>

using namespace std;

#include <iostream>
#include<conio.h>  
using namespace std;
struct Node
{
	int data = 0;             //Информационное поле
	Node* left, * right;   //Указатели на левую и правую ветви дерева
};
Node* tree = nullptr;
int SummRight[1024];
int Right;
int SummLeft[1024];
int Left;

void insert(int a, Node** t)  //Добавление элемента a 
{
	if ((*t) == NULL)              //если дерева нет, то создается элемент
	{
		(*t) = new Node;
		(*t)->data = a;
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if (a > (*t)->data) { //дерево есть, если а больше текущего55
		insert(a, &(*t)->right);
		if (Right != 0 && SummRight[Right - 1] != a) {
			SummRight[Right] = a;
			Right++;		//то элемент помещается вправо
		}
		else if (Right == 0) {
			SummRight[Right] = a;
			Right++;
		}
	}
	else {
		insert(a, &(*t)->left);   //иначе - влево
	}
	
}
void menu() {
	cout << "1 - Добавить элементы дерева\n2 - Вывод дерева\n3 - Вывод суммы данных на каждом из уровней\n0 - Выход из программы\nВаш выбор: ";
}

void print(Node* t, int u)    //Вывод на экран
{
	if (t == NULL)  return;
	else
	{
		print(t->left, ++u);     //левое поддерево
		for (int i = 0; i < u; ++i)
			cout << "|";
		cout << t->data << endl;
		u--;
	}
	print(t->right, ++u);          // правое поддерево
}
int summ;
void Level(Node* t, int level)
{
	if (t == NULL) return;
	else {
		Level(t->left, level - 1);
		if (level == 0) {
			cout << t->data << " ";
			summ += t->data;
		}
		Level(t->right, level - 1);
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int count, temp, choose;
	do {
		menu();
		cin >> choose;
		switch (choose) {
		case 1: cout << "Введите количество элементов дерева: ";
				cin >> count;
				for (int i = 0; i < count; ++i)
				{
					cout << "Введите число  ";	cin >> temp;

					insert(temp, &tree);
				}
				break;
		case 2: cout << "Вывод дерева:\n";
				print(tree, 0);
				break;
		case 3: cout << "Корень: ";
				Level(tree, 0);
				cout << "\tСумма: " << summ << endl;
				summ = 0;
				for (int i = 1; i < 10; i++) {
					cout << i << " уровень: ";
					Level(tree, i);
					cout << "\tСумма: " << summ << endl;
					summ = 0;
				}	
				break;
		case 0: break;
		} 
	} while (choose);
	return 0;
}

