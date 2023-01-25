// var 5

#include  <iostream>
using namespace std;

struct node {
	int info;
	node* l, * r;
};

node* tree1 = NULL;

void push(int a, node** t) {
	if ((*t) == NULL) {
		(*t) = new node;
		(*t)->info = a;
		(*t)->l = (*t)->r = NULL;
		return;
	}

	if (a > (*t)->info)
		push(a, &(*t)->r);
	else
		push(a, &(*t)->l);
}

void print(node* t, int u) {
	if (t == NULL) return;
	else
	{
		print(t->r, ++u);
		for (int i = 0; i < u; ++i)
			cout << "|";
		cout << t->info << endl;
		u--;
	}
	print(t->l, ++u);


}
int Summ;
void check_left(node* t)
{
	int col = 0;
	if (t->l != NULL)
	{
		check_left(t->l);
		col++;
		Summ++;
	}
	if (t->r != NULL)
		check_left(t->r);
	//cout << col << ' ';
}
void del(node** t)
{
	if (t != nullptr)
	{
		if ((*t)->l)del(&(*t)->l);
		if ((*t)->r)del(&(*t)->r);
		delete* t;
		*t = nullptr;
	}
}
void check(node* t)
{
	if (t == NULL)
	{
		cout << "Всё!" << endl;
	}
	else
	{
		return;
	}
}
int main() {
	setlocale(0, "");
	int amount, newnumber, ans = 0;
	cout << "Введите количество элементов:\t";
	cin >> amount;
	cout << "\nВведите элементы:\n";
	for (int i = 0; i < amount; ++i) {
		cin >> newnumber;
		push(newnumber, &tree1);
	}
	cout << "\nДерево:\n";
	print(tree1, 0);
	cout << endl;
	cout << "Левая часть: ";
	check_left(tree1);
	cout << Summ;
	del(&tree1);
	//cout << endl;
	//check(tree1);
}