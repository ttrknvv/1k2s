#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	vector <int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// определить количество целых чисел в std::vector равных заданному
	int target1 = 3;
	int num_items1 = count(v.begin(), v.end(), target1);
	cout << "число: " << target1 << "   количество: " << num_items1 << "\n";
	// лямбда выражения для подсчета элементов, кратных 3
	int num_items3 = count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
	cout << "количество элементов, кратных 3: " << num_items3 << "\n";
	cout << "лямбда захват переменных: ";
	// лямбда выражение захват переменных
	for (auto i : v)[i]() {if (i % 3 == 0) cout << i << " "; }();
	cout << "\n" << "лямбда с параметрами ";
	// вывод значений, кратных 3. Значения будем передавать как параметр у обычной функции
	for (auto i : v)[](auto i) {if (i % 3 == 0) cout << i << " "; }(i);
	cout << "\nлямбда без параметров  ";
	// вывод значений кратных 3
	// значения передаются через захват переменных при этом пропустим скобки для добавления параметра
	for (auto i : v)[i]{if (i % 3 == 0) cout << i << " "; }();

	char str1[50] = {};
	char str2[50] = {};
	cout << "\n\nВведите первую строку: "; cin.getline(str1, 50);
	cout << "\n\nВведите вторую строку: "; cin.getline(str2, 50);
	cout << "Самая длинная строка: " <<
	[=]() {
		if (strlen(str1) >= strlen(str2))
			return str1;
		return str2;
	}();
}