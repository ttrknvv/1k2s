// dop 3
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void dop2(string s, int count);

int a;

char c[50] = {};
char tr[50] = {};

int main()
{
	int count = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string s;
	cout << "Введите count: ";
	//cin >> count;
	//cin.ignore();
	cout << "Введите s: ";
	cin.getline(c, 50);
	a = strlen(c);
	dop2(c, count);
	return 0;
}

int k = 0;
void dop2(string s, int count)
{
	int cou;
	if (count == strlen(c))
	{
		cout << s << endl;
		return;
	}
	
	for (int i = 0; i < strlen(c); i++)
	{
		if (!tr[i])
		{
			count++;
			string save = s;
			s += c[i];
			tr[i] = 1;
			dop2(s, count);
			count--;
			s = save;
			tr[i] = 0;
		}
	}
}
