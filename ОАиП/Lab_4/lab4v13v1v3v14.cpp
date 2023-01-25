//#include <iostream>
//#include <windows.h>
//#include <fstream>
//
//using namespace std;
//
//struct Data {
//	int variable;
//	Data* next;
//};
//
//void menu();
//void inputSpisok(Data *&first);
//void printSpisok(Data* first);
//void findData(Data* first);
//void addData(Data*& first);
//void summOfInt(Data* first);
//void deleteData(Data*& first);
//void writeFile(Data* first);
//void readFile(Data*& first);
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	Data* first = nullptr;
//	int vibor = INT16_MIN;
//	while(vibor != 9) {
//		menu();
//		cin >> vibor;
//		switch (vibor) {
//		case 1: inputSpisok(first);
//			break;
//		case 2: addData(first);
//				break;
//		case 3: deleteData(first);
//				break;
//		case 4: findData(first);
//				break;
//		case 5: printSpisok(first);
//				break;
//		case 6: writeFile(first);
//				break;
//		case 7: readFile(first);
//				break;
//		case 8: summOfInt(first);
//				break;
//		}
//	}
//	return 0;
//}
//
//void menu() {
//	cout << "1 - Запись в список\n2 - Добавление элемента\n3 - Удаление элемента\n4 - Поиск элемента\n5 - Вывод списка\n"
//		<< "6 - Запись в файл\n7 - Считывание из файла\n8 - Вывести сумму отрицательных двухзначных элементов\n9 - Выход из программы\nВыбор: ";
//}
//void inputSpisok(Data *&first) {
//	int vibor = 1;
//	Data* nextData;
//	while (1) {
//		cout << "Введите 0, чтобы закончить ввод, иначе любое другое число: ";
//		cin >> vibor;
//		if (!vibor) { break;}
//		nextData = new Data;
//		cout << "Введите число списка: ";
//		cin >> nextData->variable;
//		nextData->next = first;
//		first = nextData;
//	}
//}
//void addData(Data* &first) {
//	Data* newData;
//	int variable;
//	if (!first) { cout << "Данных нет! Вернитесь в пункт 1!\n"; }
//	else {
//		cout << "Введите число: ";
//		cin >> variable;
//		newData = new Data;
//		newData->variable = variable;
//		newData->next = first;
//		first = newData;
//		cout << "Число успешно добавлено!\n";
//	}
//}
//void deleteData(Data*& first) {
//	Data* DataRight;
//	Data* DataLeft;
//	Data* deleteData;
//	int variable;
//	int proverka = 0;
//	if (!first) { cout << "Данных нет! Вернитесь в пункт 1!\n"; }
//	else {
//		cout << "Введите число для удаления: ";
//		cin >> variable;
//			if (variable == first->variable) {
//				deleteData = first;
//				first = first->next;
//				delete deleteData;
//				proverka++;
//			}
//			else {
//				deleteData = first;
//				while (deleteData) {
//					DataRight = deleteData;
//					deleteData = deleteData->next;
//					if (deleteData && deleteData->variable == variable) {
//						DataLeft = deleteData->next;
//						delete deleteData;
//						DataRight->next = DataLeft;
//						proverka++;
//						break;
//					}
//				}
//			}
//		
//		if (!proverka) { cout << "Такого числа в списке нет!\n"; }
//		else { cout << "Число успешно удалено!\n"; }
//	}
//}
//void findData(Data* first) {
//	int find;
//	int pokazatel = 0;
//	if (!first) { 
//		cout << "Нет данных!\n";
//		pokazatel = 1;
//	}
//	else {
//		cout << "Введите число, данные которого хотите найти: ";
//		cin >> find;
//	}
//	while (!pokazatel) {
//		if (!first) { break; }
//		if (find == first->variable) {
//			cout << "Есть данные!\nЧисло: " << find << "\nСсылается на: " << first->next << endl;
//			pokazatel++;
//			break;
//		}
//		first = first->next;
//	}
//	if (!pokazatel) { cout << "Числа в списке не найдено!\n"; }
//}
//void printSpisok(Data *first) {
//	if (!first) {
//		cout << "Нет данных!\n";
//	}
//	else {
//		cout << "Данные: ";
//		while (first) {
//			cout << first->variable << " ";
//			first = first->next;
//		}
//		cout << endl;
//	}
//}
//void writeFile(Data* first) {
//	if (!first) { cout << "Нет данных!\n"; }
//	else {
//		ofstream FILE;
//		FILE.open("NUMBERS.txt");
//		if (FILE.is_open()) {
//			while (first) {
//				FILE << "Число: " << first->variable << "\nАдрес элемента списка: " << &first << "\nАрес следующего элемента списка: " << first->next;
//					FILE << "\n\n----------------------------------------------------------------------------------\n\n";
//					first = first->next;
//			}
//			cout << "Данные успешно выведены!\n";
//			FILE.close();
//		}
//		else { cout << "Не удалось открыть файл!\n"; }
//	}
//}
//void readFile(Data*& first) {
//	int variable = 0;
//	Data* newData;
//	if (!first) {
//		ifstream FILE;
//		FILE.open("NUMBERS.txt", fstream::app);
//		if (FILE.is_open()) {
//			while (!FILE.eof()) {
//				FILE >> variable;
//				newData = new Data;
//				newData->variable = variable;
//				newData->next = first;
//				first = newData;
//			}
//			cout << "Данные считаны!\n";
//		}
//		else { cout << "Не удалось открыть файл!\n"; }
//		FILE.close();
//	}
//	else { cout << "У вас уже есть данные!\n"; }
//}
//void summOfInt(Data* first) {
//	int Summ = 0;
//	if (!first) {cout << "Данных нет!\n";}
//	else {
//		while (first) {
//			if (first->variable < 0 && first->variable <= -10 && first->variable >= -99) {
//				Summ += first->variable;
//			}
//			first = first->next;
//		}
//		if (!Summ) { cout << "Двухзначных отрицательных чисел не найдено!\n"; }
//		else { cout << "Сумма двухзначных отрицательных чисел: " << Summ << endl; }
//	}
//}

//#include <iostream>
//#include <windows.h> // вариант 1
//#include <fstream>
//
//using namespace std;
//
//struct Data {
//	int variable;
//	Data* next;
//};
//
//void menu();
//void inputSpisok(Data*& first);
//void printSpisok(Data* first);
//void findData(Data* first);
//void addData(Data*& first);
//void summOfInt(Data* first);
//void deleteData(Data*& first);
//void writeFile(Data* first);
//void readFile(Data*& first);
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	Data* first = nullptr;
//	int vibor = INT16_MIN;
//	while (vibor != 9) {
//		menu();
//		cin >> vibor;
//		switch (vibor) {
//		case 1: inputSpisok(first);
//			break;
//		case 2: addData(first);
//			break;
//		case 3: deleteData(first);
//			break;
//		case 4: findData(first);
//			break;
//		case 5: printSpisok(first);
//			break;
//		case 6: writeFile(first);
//			break;
//		case 7: readFile(first);
//			break;
//		case 8: summOfInt(first);
//			break;
//		}
//	}
//	return 0;
//}
//
//void menu() {
//	cout << "1 - Запись в список\n2 - Добавление элемента\n3 - Удаление элемента\n4 - Поиск элемента\n5 - Вывод списка\n"
//		<< "6 - Запись в файл\n7 - Считывание из файла\n8 - Вывести сумму положительных элементов\n9 - Выход из программы\nВыбор: ";
//}
//void inputSpisok(Data*& first) {
//	int vibor = 1;
//	Data* nextData;
//	while (1) {
//		cout << "Введите 0, чтобы закончить ввод, иначе любое другое число: ";
//		cin >> vibor;
//		if (!vibor) { break; }
//		nextData = new Data;
//		cout << "Введите число списка: ";
//		cin >> nextData->variable;
//		nextData->next = first;
//		first = nextData;
//	}
//}
//void addData(Data*& first) {
//	Data* newData;
//	int variable;
//	if (!first) { cout << "Данных нет! Вернитесь в пункт 1!\n"; }
//	else {
//		cout << "Введите число: ";
//		cin >> variable;
//		newData = new Data;
//		newData->variable = variable;
//		newData->next = first;
//		first = newData;
//		cout << "Число успешно добавлено!\n";
//	}
//}
//void deleteData(Data*& first) {
//	Data* DataRight;
//	Data* DataLeft;
//	Data* deleteData;
//	int variable;
//	int proverka = 0;
//	if (!first) { cout << "Данных нет! Вернитесь в пункт 1!\n"; }
//	else {
//		cout << "Введите число для удаления: ";
//		cin >> variable;
//		if (variable == first->variable) {
//			deleteData = first;
//			first = first->next;
//			delete deleteData;
//			proverka++;
//		}
//		else {
//			deleteData = first;
//			while (deleteData) {
//				DataRight = deleteData;
//				deleteData = deleteData->next;
//				if (deleteData->variable == variable && deleteData) {
//					DataLeft = deleteData->next;
//					delete deleteData;
//					DataRight->next = DataLeft;
//					proverka++;
//					break;
//				}
//			}
//		}
//
//		if (!proverka) { cout << "Такого числа в списке нет!\n"; }
//		else { cout << "Число успешно удалено!\n"; }
//	}
//}
//void findData(Data* first) {
//	int find;
//	int pokazatel = 0;
//	if (!first) {
//		cout << "Нет данных!\n";
//		pokazatel = 1;
//	}
//	else {
//		cout << "Введите число, данные которого хотите найти: ";
//		cin >> find;
//	}
//	while (!pokazatel) {
//		if (!first) { break; }
//		if (find == first->variable) {
//			cout << "Есть данные!\nЧисло: " << find << "\nСсылается на: " << first->next << endl;
//			pokazatel++;
//			break;
//		}
//		first = first->next;
//	}
//	if (!pokazatel) { cout << "Числа в списке не найдено!\n"; }
//}
//void printSpisok(Data* first) {
//	if (!first) {
//		cout << "Нет данных!\n";
//	}
//	else {
//		cout << "Данные: ";
//		while (first) {
//			cout << first->variable << " ";
//			first = first->next;
//		}
//		cout << endl;
//	}
//}
//void writeFile(Data* first) {
//	if (!first) { cout << "Нет данных!\n"; }
//	else {
//		ofstream FILE;
//		FILE.open("NUMBERS2.txt");
//		if (FILE.is_open()) {
//			while (first) {
//				FILE << "Число: " << first->variable << "\nАдрес элемента списка: " << &first << "\nАрес следующего элемента списка: " << first->next;
//				FILE << "\n\n----------------------------------------------------------------------------------\n\n";
//				first = first->next;
//			}
//			cout << "Данные успешно выведены!\n";
//			FILE.close();
//		}
//		else { cout << "Не удалось открыть файл!\n"; }
//	}
//}
//void readFile(Data*& first) {
//	int variable = 0;
//	Data* newData;
//	if (!first) {
//		ifstream FILE;
//		FILE.open("NUMBERS2.txt", fstream::app);
//		if (FILE.is_open()) {
//			while (!FILE.eof()) {
//				FILE >> variable;
//				newData = new Data;
//				newData->variable = variable;
//				newData->next = first;
//				first = newData;
//			}
//			cout << "Данные считаны!\n";
//		}
//		else { cout << "Не удалось открыть файл!\n"; }
//		FILE.close();
//	}
//	else { cout << "У вас уже есть данные!\n"; }
//}
//void summOfInt(Data* first) {
//	int Summ = 0;
//	if (!first) { cout << "Данных нет!\n"; }
//	else {
//		while (first) {
//			if (first->variable > 0) {
//				Summ += first->variable;
//			}
//			first = first->next;
//		}
//		if (!Summ) { cout << "Положительных чисел не найдено!\n"; }
//		else { cout << "Сумма положительных чисел: " << Summ << endl; }
//	}
//}

//#include <iostream>
//#include <windows.h> // вариант 3
//#include <fstream>
//
//using namespace std;
//
//struct Data {
//	int variable;
//	Data* next;
//};
//
//void menu();
//void inputSpisok(Data*& first);
//void printSpisok(Data* first);
//void findData(Data* first);
//void addData(Data*& first);
//void summOfInt(Data* first);
//void deleteData(Data*& first);
//void writeFile(Data* first);
//void readFile(Data*& first);
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	Data* first = nullptr;
//	int vibor = INT16_MIN;
//	while (vibor != 9) {
//		menu();
//		cin >> vibor;
//		switch (vibor) {
//		case 1: inputSpisok(first);
//			break;
//		case 2: addData(first);
//			break;
//		case 3: deleteData(first);
//			break;
//		case 4: findData(first);
//			break;
//		case 5: printSpisok(first);
//			break;
//		case 6: writeFile(first);
//			break;
//		case 7: readFile(first);
//			break;
//		case 8: summOfInt(first);
//			break;
//		}
//	}
//	return 0;
//}
//
//void menu() {
//	cout << "1 - Запись в список\n2 - Добавление элемента\n3 - Удаление элемента\n4 - Поиск элемента\n5 - Вывод списка\n"
//		<< "6 - Запись в файл\n7 - Считывание из файла\n8 - Вывести сумму положительных элементов кратных 5\n9 - Выход из программы\nВыбор: ";
//}
//void inputSpisok(Data*& first) {
//	int vibor = 1;
//	Data* nextData;
//	while (1) {
//		cout << "Введите 0, чтобы закончить ввод, иначе любое другое число: ";
//		cin >> vibor;
//		if (!vibor) { break; }
//		nextData = new Data;
//		cout << "Введите число списка: ";
//		cin >> nextData->variable;
//		nextData->next = first;
//		first = nextData;
//	}
//}
//void addData(Data*& first) {
//	Data* newData;
//	int variable;
//	if (!first) { cout << "Данных нет! Вернитесь в пункт 1!\n"; }
//	else {
//		cout << "Введите число: ";
//		cin >> variable;
//		newData = new Data;
//		newData->variable = variable;
//		newData->next = first;
//		first = newData;
//		cout << "Число успешно добавлено!\n";
//	}
//}
//void deleteData(Data*& first) {
//	Data* DataRight;
//	Data* DataLeft;
//	Data* deleteData;
//	int variable;
//	int proverka = 0;
//	if (!first) { cout << "Данных нет! Вернитесь в пункт 1!\n"; }
//	else {
//		cout << "Введите число для удаления: ";
//		cin >> variable;
//		if (variable == first->variable) {
//			deleteData = first;
//			first = first->next;
//			delete deleteData;
//			proverka++;
//		}
//		else {
//			deleteData = first;
//			while (deleteData) {
//				DataRight = deleteData;
//				deleteData = deleteData->next;
//				if (deleteData->variable == variable && deleteData) {
//					DataLeft = deleteData->next;
//					delete deleteData;
//					DataRight->next = DataLeft;
//					proverka++;
//					break;
//				}
//			}
//		}
//
//		if (!proverka) { cout << "Такого числа в списке нет!\n"; }
//		else { cout << "Число успешно удалено!\n"; }
//	}
//}
//void findData(Data* first) {
//	int find;
//	int pokazatel = 0;
//	if (!first) {
//		cout << "Нет данных!\n";
//		pokazatel = 1;
//	}
//	else {
//		cout << "Введите число, данные которого хотите найти: ";
//		cin >> find;
//	}
//	while (!pokazatel) {
//		if (!first) { break; }
//		if (find == first->variable) {
//			cout << "Есть данные!\nЧисло: " << find << "\nСсылается на: " << first->next << endl;
//			pokazatel++;
//			break;
//		}
//		first = first->next;
//	}
//	if (!pokazatel) { cout << "Числа в списке не найдено!\n"; }
//}
//void printSpisok(Data* first) {
//	if (!first) {
//		cout << "Нет данных!\n";
//	}
//	else {
//		cout << "Данные: ";
//		while (first) {
//			cout << first->variable << " ";
//			first = first->next;
//		}
//		cout << endl;
//	}
//}
//void writeFile(Data* first) {
//	if (!first) { cout << "Нет данных!\n"; }
//	else {
//		ofstream FILE;
//		FILE.open("NUMBERS3.txt");
//		if (FILE.is_open()) {
//			while (first) {
//				FILE << "Число: " << first->variable << "\nАдрес элемента списка: " << &first << "\nАрес следующего элемента списка: " << first->next;
//				FILE << "\n\n----------------------------------------------------------------------------------\n\n";
//				first = first->next;
//			}
//			cout << "Данные успешно выведены!\n";
//			FILE.close();
//		}
//		else { cout << "Не удалось открыть файл!\n"; }
//	}
//}
//void readFile(Data*& first) {
//	int variable = 0;
//	Data* newData;
//	if (!first) {
//		ifstream FILE;
//		FILE.open("NUMBERS3.txt", fstream::app);
//		if (FILE.is_open()) {
//			while (!FILE.eof()) {
//				FILE >> variable;
//				newData = new Data;
//				newData->variable = variable;
//				newData->next = first;
//				first = newData;
//			}
//			cout << "Данные считаны!\n";
//		}
//		else { cout << "Не удалось открыть файл!\n"; }
//		FILE.close();
//	}
//	else { cout << "У вас уже есть данные!\n"; }
//}
//void summOfInt(Data* first) {
//	int Summ = 0;
//	if (!first) { cout << "Данных нет!\n"; }
//	else {
//		while (first) {
//			if (first->variable > 0 && first->variable % 5 == 0) {
//				Summ += first->variable;
//			}
//			first = first->next;
//		}
//		if (!Summ) { cout << "Положительных чисел кратных 5 не найдено!\n"; }
//		else { cout << "Сумма положительных чисел кратных 5: " << Summ << endl; }
//	}
//}

#include <iostream>
#include <windows.h> // вариант 14
#include <fstream>

using namespace std;

struct Data {
	int variable;
	Data* next;
};

void menu();
void inputSpisok(Data*& first);
void printSpisok(Data* first);
void findData(Data* first);
void addData(Data*& first);
void summOfInt(Data* first);
void deleteData(Data*& first);
void writeFile(Data* first);
void readFile(Data*& first);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Data* first = nullptr;
	int vibor = INT16_MIN;
	while (vibor != 9) {
		menu();
		cin >> vibor;
		switch (vibor) {
		case 1: inputSpisok(first);
			break;
		case 2: addData(first);
			break;
		case 3: deleteData(first);
			break;
		case 4: findData(first);
			break;
		case 5: printSpisok(first);
			break;
		case 6: writeFile(first);
			break;
		case 7: readFile(first);
			break;
		case 8: summOfInt(first);
			break;
		}
	}
	return 0;
}

void menu() {
	cout << "1 - Запись в список\n2 - Добавление элемента\n3 - Удаление элемента\n4 - Поиск элемента\n5 - Вывод списка\n"
		<< "6 - Запись в файл\n7 - Считывание из файла\n8 - Вывести сумму отрицательных элементов кратных 5\n9 - Выход из программы\nВыбор: ";
}
void inputSpisok(Data*& first) {
	int vibor = 1;
	Data* nextData;
	while (1) {
		cout << "Введите 0, чтобы закончить ввод, иначе любое другое число: ";
		cin >> vibor;
		if (!vibor) { break; }
		nextData = new Data;
		cout << "Введите число списка: ";
		cin >> nextData->variable;
		nextData->next = first;
		first = nextData;
	}
}
void addData(Data*& first) {
	Data* newData;
	int variable;
	if (!first) { cout << "Данных нет! Вернитесь в пункт 1!\n"; }
	else {
		cout << "Введите число: ";
		cin >> variable;
		newData = new Data;
		newData->variable = variable;
		newData->next = first;
		first = newData;
		cout << "Число успешно добавлено!\n";
	}
}
void deleteData(Data*& first) {
	Data* DataRight;
	Data* DataLeft;
	Data* deleteData;
	int variable;
	int proverka = 0;
	if (!first) { cout << "Данных нет! Вернитесь в пункт 1!\n"; }
	else {
		cout << "Введите число для удаления: ";
		cin >> variable;
		if (variable == first->variable) {
			deleteData = first;
			first = first->next;
			delete deleteData;
			proverka++;
		}
		else {
			deleteData = first;
			while (deleteData) {
				DataRight = deleteData;
				deleteData = deleteData->next;
				if (deleteData->variable == variable && deleteData) {
					DataLeft = deleteData->next;
					delete deleteData;
					DataRight->next = DataLeft;
					proverka++;
					break;
				}
			}
		}

		if (!proverka) { cout << "Такого числа в списке нет!\n"; }
		else { cout << "Число успешно удалено!\n"; }
	}
}
void findData(Data* first) {
	int find;
	int pokazatel = 0;
	if (!first) {
		cout << "Нет данных!\n";
		pokazatel = 1;
	}
	else {
		cout << "Введите число, данные которого хотите найти: ";
		cin >> find;
	}
	while (!pokazatel) {
		if (!first) { break; }
		if (find == first->variable) {
			cout << "Есть данные!\nЧисло: " << find << "\nСсылается на: " << first->next << endl;
			pokazatel++;
			break;
		}
		first = first->next;
	}
	if (!pokazatel) { cout << "Числа в списке не найдено!\n"; }
}
void printSpisok(Data* first) {
	if (!first) {
		cout << "Нет данных!\n";
	}
	else {
		cout << "Данные: ";
		while (first) {
			cout << first->variable << " ";
			first = first->next;
		}
		cout << endl;
	}
}
void writeFile(Data* first) {
	if (!first) { cout << "Нет данных!\n"; }
	else {
		ofstream FILE;
		FILE.open("NUMBERS4.txt");
		if (FILE.is_open()) {
			while (first) {
				FILE << "Число: " << first->variable << "\nАдрес элемента списка: " << &first << "\nАрес следующего элемента списка: " << first->next;
				FILE << "\n\n----------------------------------------------------------------------------------\n\n";
				first = first->next;
			}
			cout << "Данные успешно выведены!\n";
			FILE.close();
		}
		else { cout << "Не удалось открыть файл!\n"; }
	}
}
void readFile(Data*& first) {
	int variable = 0;
	Data* newData;
	if (!first) {
		ifstream FILE;
		FILE.open("NUMBERS4.txt", fstream::app);
		if (FILE.is_open()) {
			while (!FILE.eof()) {
				FILE >> variable;
				newData = new Data;
				newData->variable = variable;
				newData->next = first;
				first = newData;
			}
			cout << "Данные считаны!\n";
		}
		else { cout << "Не удалось открыть файл!\n"; }
		FILE.close();
	}
	else { cout << "У вас уже есть данные!\n"; }
}
void summOfInt(Data* first) {
	int Summ = 0;
	if (!first) { cout << "Данных нет!\n"; }
	else {
		while (first) {
			if (first->variable < 0 && first->variable % 5 == 0) {
				Summ += first->variable;
			}
			first = first->next;
		}
		if (!Summ) { cout << "Отрицательных чисел кратных 5 не найдено!\n"; }
		else { cout << "Сумма отрицательных чисел кратных 5: " << Summ << endl; }
	}
}
