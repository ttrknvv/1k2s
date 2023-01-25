#include<tchar.h>
#include "tree.h"
#include <fstream>
using namespace std;
int summ;
void Level(Tree* t, int level)
{
	if (t == NULL) return;
	else {
		Level(t->Left, level - 1);
		if (level == 0) {
			cout << t->key << " ";
			summ += t->key;
		}
		Level(t->Right, level - 1);
	}
}
int main()
{
	setlocale(0, "Russian");
	int key, choice, n, z = 0;
	//Tree* rc;
	int c = 0;
	Tree* Root = NULL;
	for (;;)
	{
		cout << endl;
		cout << "1 -создание дерева\n";
		cout << "2 -прямой(нисходящий) обход\n";
		cout << "3 -симметричный(смешанный) обход \n";
		cout << "4 -обратный(восходящий) обход\n";
		cout << "5 -вывод суммы по уровням\n";
		cout << "6 -Проверка на сбалансированность\n";
		cout << "7 -удаление дерева\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1: Root = makeTree(Root); break;
		case 2: if (Root->key >= 0)
			view(Root);
			  else cout << "Дерево пустое\n"; break;
		case 3: if (Root->key >= 0)
			view2(Root);
			  else cout << "Дерево пустое\n"; break;
		case 4: if (Root->key >= 0)
			view3(Root);
			  else cout << "Дерево пустое\n"; break;
		case 5:
			"Корень: ";
			Level(Root, 0);
			cout << "\tСумма: " << summ << endl;
			summ = 0;
			for (int i = 1; i < 10; i++) {
				cout << i << " уровень: ";
				Level(Root, i);
				cout << "\tСумма: " << summ << endl;
				summ = 0;
			}
			break;

		case 6:
			if (isBalanced(Root))
				cout << "Дерево сбалансированно";
			else
				cout << "Дерево несбалансированно";
			break;
		case 7: delAll(Root); break;

		case 8: exit(0);
		}
	}
}