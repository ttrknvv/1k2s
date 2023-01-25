#include <iostream>
#include <windows.h>
using namespace std;
struct tree {
	int data;
	tree* left, * right;
};
tree* tree1 = NULL;
void insert(int a, tree** t, int N)
{
	if (!N) return;
	if (*t == nullptr)
	{
		(*t) = new tree;
		(*t)->data = a;
		(*t)->left = (*t)->right = nullptr;
		return;
	}
	if (!(*t)->left)
		insert(a, &(*t)->left, N);
	else
		insert(a, &(*t)->right, N);
}
void print(tree* t, int level)
{
	if (t == nullptr)return;
	else
	{
		print(t->left, ++level);
		for (int i = 0; i < level; ++i)
			cout << "|";
		cout << t->data << endl;
		level--;
	}
	print(t->right, ++level);
}
void del(tree** t)
{
	if (t != nullptr)
	{
		if ((*t)->left)del(&(*t)->left);
		if ((*t)->right)del(&(*t)->right);
		delete* t;
		*t = nullptr;
	}
}
int summ;
void Level(tree* t, int level)
{
	if (t == NULL) return;
	else {
		Level(t->left, level - 1);
		if (level == 0) {
			cout << t->data << "\t";
			summ += t->data;
		}
		Level(t->right, level - 1);
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice, n, i = 1;
	for (;;)
	{
		cout << "1 -Создать дерево\n";
		cout << "2 -Вывести дерево\n";
		cout << "3 -Удалить Дерево\n";
		cout << "4 - Выход \n";
		cout << "Ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:
			cout << "Введите N:" << endl;
			cin >> n;
			int a;
			while (i++ <= n)
			{
				cout << "Введите значение:";
				cin >> a;
				cout << endl;
				insert(a, &tree1, n);
			}
			break;
		case 2:
			cout << "Корень: ";
			Level(tree1, 0);
			summ = 0;
			for (int i = 1; i < 10; i++) {
				cout << i << " уровень: ";
				Level(tree1, i);
				cout << endl;
				summ = 0;
			}
			break;
		case 3: break;
			del(&tree1);
		case 4:
			exit(0);
			break;
		}
	}

}