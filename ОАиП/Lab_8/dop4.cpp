// dop4

#include <iostream>

using namespace std;

char f1(char s, int n)
{
	static char s1 = s;
	setlocale(LC_ALL, "rus");
	static int loop = 1;
	loop++;
	s1++;
	if (loop < n)
		f1(s1, n);
	return s1;
}

int main()
{
	char s = 'a';
	for (int i = 0; i < 26; i++)
		s++;
	int n = 0;
	cout << "n > "; cin >> n;
	cout << "Полученный символ > " << f1(s, n);
}

