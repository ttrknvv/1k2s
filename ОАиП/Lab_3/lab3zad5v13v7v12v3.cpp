//#include <iostream> // 13 вариант 5 задание
//#include <fstream>
//#include <windows.h>
//#include <string>
//
//using namespace std;
//
//void inputData();
//int menu();
//void outputData();
//void searchData();
//void writeInFile();
//void readFromFile();
//
//union forGover {
//	char line[30];
//	char variable[10];
//};
//struct gover {
//	forGover nameGover = {};
//	forGover capitalGover = {};
//	forGover numberGover = {};
//	forGover squareGover = {};
//	forGover surnamePrezGover = {};
//};
//
//struct gover goverment[30];
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	menu();
//	return 0;
//}
//
//int menu() {
//	int vibor = 0;
//	cout << "\n1 - Ввести данные\n" << "2 - Вывод данных в консоль" << "\n3 - Поиск информации государства по названию" 
//		<< "\n4 - Запись информации в файл" << "\n5 - Чтение данных\n"
//		<< "0 - Выход\n" << "Выбор: ";
//	cin >> vibor;
//	cout << endl;
//	switch (vibor) {
//	case 0: break;;
//	case 1: inputData();
//		break;
//	case 2: outputData();
//		break;
//	case 3: searchData();
//		break;
//	case 4: writeInFile();
//		break;
//	case 5: readFromFile();
//		break;
//	}
//	return 0;
//}
//
//void inputData() {
//	int vibor = 0;
//	for (int i = 0; i < 30; i++) {
//		cout << "Для выхода введите 0, иначе любое другое число\n";
//		cin >> vibor;
//		if (vibor == 0) {
//			break;
//		}
//		cin.ignore();
//
//		cout << "Название государства: ";
//		cin.getline(goverment[i].nameGover.line, 30);    
//
//		cout << "Столица: ";
//		cin.getline(goverment[i].capitalGover.line, 30);   
//
//		cout << "Численность населения(милл. чел.): ";
//		cin.getline(goverment[i].numberGover.variable, 10);					
//
//		cout << "Площадь(км2): ";
//		cin.getline(goverment[i].squareGover.variable, 10); 
//
//		cout << "Фамилия президента: ";
//		cin.getline(goverment[i].surnamePrezGover.line, 30);				
//	}
//	menu();
//}
//void outputData() {
//	for (int i = 0; i < 30; i++) {
//		if (goverment[i].numberGover.variable[0] == 0 && goverment[i].squareGover.variable[0] == 0) {
//			break;
//		}
//		cout << "Название государства: " << goverment[i].nameGover.line << endl;
//		cout << "Столица: " << goverment[i].capitalGover.line << endl;
//		cout << "Численность населения(милл. чел.): " << goverment[i].numberGover.variable << endl;
//		cout << "Площадь(км2): " << goverment[i].squareGover.variable << endl;
//		cout << "Фамилия президента: " << goverment[i].surnamePrezGover.line << endl << endl;
//	}
//	if (goverment[0].numberGover.variable[0] == 0 && goverment[0].squareGover.variable[0] == 0) {
//		cout << "\n!!!Нет данных!!!\n";
//	}
//	menu();
//}
//void searchData() {
//	string vibor;
//	int indicate = 0;
//	cout << "Введите название государства: ";
//	cin >> vibor;
//	for (int i = 0; i < 30; i++) {
//		if (goverment[i].nameGover.line == vibor) {
//			cout << "\nНайденные данные:\n\n";
//			cout << "Название государства: " << goverment[i].nameGover.line << endl;
//			cout << "Столица: " << goverment[i].capitalGover.line << endl;
//			cout << "Численность населения(милл. чел.): " << goverment[i].numberGover.variable << endl;
//			cout << "Площадь(км2): " << goverment[i].squareGover.variable << endl;
//			cout << "Фамилия президента: " << goverment[i].surnamePrezGover.line << endl << endl;
//			indicate++;
//		}
//	}
//	if (indicate == 0) {
//		cout << "\nДанные не найдены!\n\n";
//	}
//	menu();
//}
//void writeInFile() {
//	ofstream inFile;
//	int indicate = 0;
//	inFile.open("GOVERMENT.txt");
//	for (int i = 0; i < 30; i++) {
//		if (goverment[i].numberGover.variable[0] == 0 && goverment[i].squareGover.variable[0] == 0) {
//			break;
//		}
//		inFile << "Название государства: " << goverment[i].nameGover.line << "\n";
//		inFile << "Столица: " << goverment[i].capitalGover.line << "\n";
//		inFile << "Численность населения(милл. чел.): " << goverment[i].numberGover.variable << "\n";
//		inFile << "Площадь(км2): " << goverment[i].squareGover.variable << "\n";
//		inFile << "Фамилия президента: " << goverment[i].surnamePrezGover.line << "\n" << "\n";
//		indicate++;
//	}
//	if (indicate == 0) {
//		cout << "\nДанные не найдены!\n";
//	}
//	else { cout << "\nДанные записаны в файл GOVERMENT.txt\n"; }
//	inFile.close();
//	menu();
//}
//void readFromFile() {
//	int category = 0, i = 0;
//	ifstream fromFile;
//	fromFile.open("GOVERMENT.txt", ifstream::app);
//	string sentence = "1";
//	while (sentence != "") {
//		getline(fromFile, sentence);
//		if (sentence == "" || sentence == goverment[i-1].surnamePrezGover.line && i != 0) {
//			break;
//		}
//		else if (category == 0) {
//			for (int k = 0; k < sentence.size(); k++) {
//				goverment[i].nameGover.line[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 1) {
//			for (int k = 0; k < sentence.size(); k++) {
//				goverment[i].capitalGover.line[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 2) {
//			for (int k = 0; k < sentence.size(); k++) {
//				goverment[i].numberGover.variable[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 3) {
//			for (int k = 0; k < sentence.size(); k++) {
//				goverment[i].squareGover.variable[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 4) {
//			for (int k = 0; k < sentence.size(); k++) {
//				goverment[i].surnamePrezGover.line[k] = sentence[k];
//			}
//			category = 0;
//			i++;
//		}
//	}
//	if (i == 0) {
//		cout << "\nНет данных в файле!\n\n";
//	}
//	else { cout << "\nДанные считаны из файла GOVERMENT.txt!\n\n"; }
//	fromFile.close();
//	menu();
//}
//
//#include <iostream> // 7 вариант 5 задание
//#include<fstream>
//#include <windows.h>
//#include<string>
//# define sizeline 100
//using namespace std;
//void enter_new();
//void out();
//void writeInFile();
//void readFromFile();
//void search();
//union forSklad
//{
//	char str[20];
//	char limb[20];
//};
//struct Sklad
//{
//	forSklad name_of_product = {};
//	forSklad cell;
//	forSklad many;
//	forSklad per;
//};
//Sklad productOnSclad[sizeline];
//int current_size = 0; int choice;
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	cout << "Введите:" << endl;
//	cout << "1-для ввода записи" << endl;
//	cout << "2-для вывода записи" << endl;
//	cout << "3-для записи в файл" << endl;
//	cout << "4-для чтения из файла" << endl;
//	cout << "5-для поиска по имени товара" << endl;
//	cout << "0-для выхода" << endl;
//	cin >> choice;
//	do
//	{
//		switch (choice)
//		{
//		case 0: break;
//		case 1: enter_new(); break;
//		case 2: out(); break;
//		case 3: writeInFile(); break;
//		case 4: readFromFile(); break;
//		case 5: search(); break;
//		}
//	} while (choice != 0);
//	return 0;
//}
//void enter_new()
//{
//	cout << "Ввод информации" << endl;
//	if (current_size < sizeline)
//	{
//		cout << "Строка номер ";
//		cout << current_size + 1;
//		cout << endl << "Наименование товара" << endl;
//		cin >> productOnSclad[current_size].name_of_product.str;
//		cout << "Цена" << endl;
//		cin >> productOnSclad[current_size].cell.limb;
//		cout << "Количество" << endl;
//		cin >> productOnSclad[current_size].many.limb;
//		cout << "Процентная надбавка" << endl;
//		cin >> productOnSclad[current_size].per.limb;
//		current_size++;
//
//	}
//	else
//		cout << "Введено максимальное кол-во строк";
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void out()
//{
//	int sw, n;
//	cout << "1-вывод 1 строки" << endl;
//	cout << "2-вывод всех строк" << endl;
//	cin >> sw;
//	if (sw == 1)
//	{
//		cout << "Номер выводимой строки: " << endl;
//		cin >> n;
//		cout << endl;
//		cout << endl << "Наименование товара:" << endl;
//		cout << productOnSclad[n - 1].name_of_product.str << endl;
//		cout << "Цена:" << endl;
//		cout << productOnSclad[n - 1].cell.limb << endl;
//		cout << "Количество:" << endl;
//		cout << productOnSclad[n - 1].many.limb << endl;
//		cout << "Процентная надбавка:" << endl;
//		cout << productOnSclad[n - 1].per.limb << "%" << endl;
//	}
//	if (sw == 2)
//	{
//		for (int i = 0; i < current_size; i++)
//		{
//			cout << endl << "Наименование товара:" << endl;
//			cout << productOnSclad[i].name_of_product.str << endl;
//			cout << "Цена:" << endl;
//			cout << productOnSclad[i].cell.limb << endl;
//			cout << "Количество:" << endl;
//			cout << productOnSclad[i].many.limb << endl;
//			cout << "Процентная надбавка:" << endl;
//			cout << productOnSclad[i].per.limb << "%" << endl;
//
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void search()
//{
//	char name[16];
//	cout << "Введите наименование товара:" << "\n";
//	cin >> name;
//	for (int z = 0; z < current_size; z++)
//	{
//		if (strcmp(name, productOnSclad[z].name_of_product.str) == 0)
//		{
//			cout << endl << "Наименование товара:" << endl;
//			cout << productOnSclad[z].name_of_product.str << endl;
//			cout << "Цена:" << endl;
//			cout << productOnSclad[z].cell.limb << endl;
//			cout << "Количество:" << endl;
//			cout << productOnSclad[z].many.limb << endl;
//			cout << "Процентная надбавка:" << endl;
//			cout << productOnSclad[z].per.limb << "%" << endl;
//
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void writeInFile() {
//	ofstream inFile;
//	int indicate = 0;
//	inFile.open("product.txt");
//	for (int i = 0; i < 30; i++) {
//		if (productOnSclad[i].name_of_product.str[0] == 0) {
//			break;
//		}
//		inFile << "Наименование товара: " << productOnSclad[i].name_of_product.str << "\n";
//		inFile << "Цена: " << productOnSclad[i].cell.limb << "\n";
//		inFile << "Количество: " << productOnSclad[i].many.limb << "\n";
//		inFile << "Процентная надбавка: " << productOnSclad[i].per.limb << "\n";
//		indicate++;
//	}
//	if (indicate == 0) {
//		cout << "\nДанные не найдены!\n";
//	}
//	else { cout << "\nДанные записаны в файл product.txt\n"; }
//	inFile.close();
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void readFromFile() {
//	int category = 0, j = 0;
//	ifstream fromFile;
//	fromFile.open("product.txt", ifstream::app);
//	string sentence = "1";
//	while (sentence != "") {
//		getline(fromFile, sentence);
//		if (sentence == "" || sentence == productOnSclad[j-1].per.limb && j != 0) {
//			break;
//		}
//		else if (category == 0) {
//			for (int k = 0; k < sentence.size(); k++) {
//				productOnSclad[j].name_of_product.str[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 1) {
//			for (int k = 0; k < sentence.size(); k++) {
//				productOnSclad[j].cell.limb[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 2) {
//			for (int k = 0; k < sentence.size(); k++) {
//				productOnSclad[j].many.limb[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 3) {
//			for (int k = 0; k < sentence.size(); k++) {
//				productOnSclad[j].per.limb[k] = sentence[k];
//			}
//			category = 0;
//			j++;
//		}
//	}
//	if (j == 0) {
//		cout << "\nНет данных в файле!\n\n";
//	}
//	else { cout << "\nДанные считаны из файла product.txt!\n\n"; }
//	fromFile.close();
//	current_size = j;
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//#include <iostream> // 12 вариант 5 задание
//#include<fstream>
//#include <iomanip>
//#include <string>
//#include<Windows.h>
//using namespace std;
//# define str_len 256
//# define sizeline 100
//using namespace std;
//void enter_new();
//void out();
//void search();
//void writeInFile();
//void readFromFile();
//union fornotebook
//{
//	char str[40];
//	char limb[20];
//};
//struct notebook
//{
//	fornotebook name = {};
//	fornotebook surname = {};
//	fornotebook middleName = {};
//	fornotebook date = {};
//	fornotebook addres = {};
//	fornotebook phone = {};
//	fornotebook place_of_work = {};
//	fornotebook position = {};
//};
//notebook people_in_notebook[sizeline];
//int current_size = 0; int choice;
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	cout << "Введите:" << endl;
//	cout << "1-для ввода записи" << endl;
//	cout << "2-для вывода записи" << endl;
//	cout << "3-для поиска информации" << endl;
//	cout << "4-для вывода информации в файл" << endl;
//	cout << "5-для чтения информации" << endl;
//	cout << "0-для выхода" << endl;
//	cin >> choice;
//	do
//	{
//		switch (choice)
//		{
//		case 1: enter_new(); break;
//		case 2: out(); break;
//		case 3: search(); break;
//		case 4: writeInFile(); break;
//		case 5: readFromFile(); break;
//		}
//	} while (choice != 0);
//}
//void enter_new()
//{
//	cout << "Ввод информации" << endl;
//	if (current_size < sizeline)
//	{
//		cout << "Строка номер ";
//		cout << current_size + 1;
//		cout << endl << "Фамилия" << endl;
//		cin >> people_in_notebook[current_size].surname.str;
//		cout << "Имя" << endl;
//		cin >> people_in_notebook[current_size].name.str;
//		cout << "Отчество" << endl;
//		cin >> people_in_notebook[current_size].middleName.str;
//		cout << "Дата рождения: " << endl;
//		cin >> people_in_notebook[current_size].date.str;
//		cout << "Адрес:" << endl;
//		cin >> people_in_notebook[current_size].addres.str;
//		cout << "Номер телефона:" << endl;
//		cin >> people_in_notebook[current_size].phone.limb;
//		cout << "Место работы:" << endl;
//		cin >> people_in_notebook[current_size].place_of_work.str;
//		cout << "Должность:" << endl;
//		cin >> people_in_notebook[current_size].position.str;
//		current_size++;
//
//
//	}
//	else
//		cout << "Введено максимальное кол-во строк";
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void out()
//{
//	int sw, n;
//	cout << "1-вывод 1 строки" << endl;
//	cout << "2-вывод всех строк" << endl;
//	cin >> sw;
//	if (sw == 1)
//	{
//		cout << "Номер выводимой строки: " << endl;
//		cin >> n;
//		cout << endl;
//		cout << "Фамилия" << endl;
//		cout << people_in_notebook[n - 1].surname.str;
//		cout << endl;
//		cout << "Имя" << endl;
//		cout << people_in_notebook[n - 1].name.str;
//		cout << endl;
//		cout << "Отчество" << endl;
//		cout << people_in_notebook[n - 1].middleName.str;
//		cout << endl;
//		cout << "Дата рождения: " << endl;
//		cout << people_in_notebook[n - 1].date.str << endl;
//		cout << "Адрес:" << endl;
//		cout << people_in_notebook[n - 1].addres.str;
//		cout << endl;
//		cout << "Номер телефона:" << endl;
//		cout << people_in_notebook[n - 1].phone.limb;
//		cout << endl;
//		cout << "Место работы:" << endl;
//		cout << people_in_notebook[n - 1].place_of_work.str;
//		cout << endl;
//		cout << "Должность:" << endl;
//		cout << people_in_notebook[n - 1].position.str;
//		cout << endl;
//
//	}
//	if (sw == 2)
//	{
//		for (int i = 0; i < current_size; i++)
//		{
//			cout << "Фамилия" << endl;
//			cout << people_in_notebook[i].surname.str;
//			cout << endl;
//			cout << "Имя" << endl;
//			cout << people_in_notebook[i].name.str;
//			cout << endl;
//			cout << "Отчество" << endl;
//			cout << people_in_notebook[i].middleName.str;
//			cout << endl;
//			cout << "Дата рождения: " << endl;
//			cout << people_in_notebook[i].date.str;
//			cout << "\nАдрес:" << endl;
//			cout << people_in_notebook[i].addres.str;
//			cout << endl;
//			cout << "Номер телефона:" << endl;
//			cout << people_in_notebook[i].phone.limb;
//			cout << endl;
//			cout << "Место работы:" << endl;
//			cout << people_in_notebook[i].place_of_work.str;
//			cout << endl;
//			cout << "Должность:" << endl;
//			cout << people_in_notebook[i].position.str;
//			cout << endl;
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void search()
//{
//	char name[16];
//	cout << "Введите фамилию:" << "\n";
//	cin >> name;
//	for (int z = 0; z < current_size; z++)
//	{
//		if (strcmp(name, people_in_notebook[z].surname.str) == 0)
//		{
//			cout << "Фамилия" << endl;
//			cout << people_in_notebook[z].surname.str;
//			cout << endl;
//			cout << "Имя" << endl;
//			cout << people_in_notebook[z].name.str;
//			cout << endl;
//			cout << "Отчество" << endl;
//			cout << people_in_notebook[z].middleName.str;
//			cout << endl;
//			cout << "Дата рождения: " << endl;
//			cout << people_in_notebook[z].date.str;
//			cout << "Адрес:" << endl;
//			cout << people_in_notebook[z].addres.str;
//			cout << endl;
//			cout << "Номер телефона:" << endl;
//			cout << people_in_notebook[z].phone.limb;
//			cout << endl;
//			cout << "Место работы:" << endl;
//			cout << people_in_notebook[z].place_of_work.str;
//			cout << endl;
//			cout << "Должность:" << endl;
//			cout << people_in_notebook[z].position.str;
//			cout << endl;
//
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void writeInFile() {
//		ofstream inFile;
//		int indicate = 0;
//		inFile.open("notebook.txt");
//		for (int i = 0; i < 30; i++) {
//			if (people_in_notebook[i].surname.str[0] == 0) {
//				break;
//			}
//			inFile << "ФИО: " << people_in_notebook[i].surname.str << " " << people_in_notebook[i].name.str
//				<< " " << people_in_notebook[i].middleName.str << "\n";
//			inFile << "Дата рождения: " << people_in_notebook[i].date.str << "\n";
//			inFile << "Адресс: " << people_in_notebook[i].addres.str << "\n";
//			inFile << "Номер телефона: " << people_in_notebook[i].phone.limb << "\n";
//			inFile << "Место работы: " << people_in_notebook[i].place_of_work.str << "\n";
//			inFile << "Должность: " << people_in_notebook[i].position.str << "\n";
//			indicate++;
//		}
//		if (indicate == 0) {
//			cout << "\nДанные не найдены!\n";
//		}
//		else { cout << "\nДанные записаны в файл notebook.txt\n"; }
//		inFile.close();
//		cout << "Что дальше?" << endl;
//		cin >> choice;
//	}
//void readFromFile() {
//	int category = 0, j = 0;
//	ifstream fromFile;
//	fromFile.open("notebook.txt", ifstream::app);
//	string sentence = "1";
//	while (sentence != "") {
//		getline(fromFile, sentence);
//		if (sentence == "" || sentence == people_in_notebook[j-1].position.str && j != 0) {
//			break;
//		}
//		else if (category == 0) {
//			for (int k = 0; k < sentence.size(); k++) {
//				people_in_notebook[j].surname.str[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 1) {
//			for (int k = 0; k < sentence.size(); k++) {
//				people_in_notebook[j].name.str[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 2) {
//			for (int k = 0; k < sentence.size(); k++) {
//				people_in_notebook[j].middleName.str[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 3) {
//			for (int k = 0; k < sentence.size(); k++) {
//				people_in_notebook[j].date.str[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 4) {
//			for (int k = 0; k < sentence.size(); k++) {
//				people_in_notebook[j].addres.str[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 5) {
//			for (int k = 0; k < sentence.size(); k++) {
//				people_in_notebook[j].phone.str[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 6) {
//			for (int k = 0; k < sentence.size(); k++) {
//				people_in_notebook[j].place_of_work.str[k] = sentence[k];
//			}
//			category++;
//		}
//		else if (category == 7) {
//			for (int k = 0; k < sentence.size(); k++) {
//				people_in_notebook[j].position.str[k] = sentence[k];
//			}
//			category = 0;
//			j++;
//		}
//	}
//	if (j == 0) {
//		cout << "\nНет данных в файле!\n\n";
//	}
//	else { cout << "\nДанные считаны из файла notebook.txt!\n\n"; }
//	fromFile.close();
//	current_size = j;
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
#include <iostream>  // 3 вариант 5 задание
#include<fstream>
#include <windows.h>
#include<string>
# define sizeline 100  
using namespace std;
void enter_new();
void out();
void search();
void writeInFile();
void readFromFile();

union forLombard
{
	char str[20];
	char limb[20];
};
struct Lombard
{
	forLombard name = {};
	forLombard surname = {};
	forLombard middleName = {};
	forLombard date_of_birthday = {};
	forLombard place_of_live = {};
	forLombard name_of_product = {};
	forLombard sum = {};
	forLombard sum_of_client = {};
	forLombard date_of_issue = {};
	forLombard shelfLife = {};
};
Lombard base_of_lombard[sizeline];
int current_size = 0; int choice;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите число:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для поиска информации" << endl;
	cout << "4-для вывода информации" << endl;
	cout << "5-для чтения информации" << endl;
	cout << "0-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enter_new();	break;
		case 2:  out();  break;
		case 3:  search();	break;
		case 4: writeInFile(); break;
		case 5:readFromFile(); break;
		}
	} while (choice != 0);
}
void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < sizeline)
	{
		cout << "Строка номер  ";
		cout << current_size + 1;
		cout << "\n";
		cout << "                     " << "Анкета клиента" << "\n";
		cout << endl << "Фамилия" << endl;
		cin >> base_of_lombard[current_size].surname.str;
		cout << "Имя" << endl;
		cin >> base_of_lombard[current_size].name.str;
		cout << "Отчество" << endl;
		cin >> base_of_lombard[current_size].middleName.str;
		cout << "Дата рождения" << endl;
		cin >> base_of_lombard[current_size].date_of_birthday.str;
		cout << "Место проживания" << endl;
		cin >> base_of_lombard[current_size].place_of_live.str;
		cout << "                     " << "Информация о товаре" << "\n";
		cout << "Наименование товара" << endl;
		cin >> base_of_lombard[current_size].name_of_product.str;
		cout << "Оценочная стоимость" << endl;
		cin >> base_of_lombard[current_size].sum.limb;
		cout << "Сумма под залог" << endl;
		cin >> base_of_lombard[current_size].sum_of_client.limb;
		cout << "Дата сдачи" << endl;
		cin >> base_of_lombard[current_size].date_of_issue.str;
		cout << "Срок хранения" << endl;
		cin >> base_of_lombard[current_size].shelfLife.str;
		current_size++;

	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-вывести 1 строку" << endl;
	cout << "2-вывести все строки" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки: " << endl;
		cin >> n;
		cout << endl;
		cout << "                     " << "Анкета клиента" << "\n";
		cout << "Фамилия:";
		cout << base_of_lombard[n - 1].surname.str;
		cout << endl;
		cout << "Имя:";
		cout << base_of_lombard[n - 1].name.str;
		cout << endl;
		cout << "Отчество:";
		cout << base_of_lombard[n - 1].middleName.str;
		cout << endl;
		cout << "Дата рождения:";
		cout << base_of_lombard[n - 1].date_of_birthday.str;
		cout << endl;
		cout << "Место проживания:";
		cout << base_of_lombard[n - 1].place_of_live.str;
		cout << endl;
		cout << "                     " << "Информация о товаре" << "\n";
		cout << "Наименование товара:";
		cout << base_of_lombard[n - 1].name_of_product.str;
		cout << endl;
		cout << "Оценочная стоимость:";
		cout << base_of_lombard[n - 1].sum.limb;
		cout << endl;
		cout << "Сумма под залог:";
		cout << base_of_lombard[n - 1].sum_of_client.limb;
		cout << endl;
		cout << "Дата сдачи:";
		cout << base_of_lombard[n - 1].date_of_issue.str;
		cout << endl;
		cout << "Срок хранения:";
		cout << base_of_lombard[n - 1].shelfLife.str;
		cout << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "                     " << "Анкета клиента" << "\n";
			cout << "Фамилия:";
			cout << base_of_lombard[i].surname.str;
			cout << endl;
			cout << "Имя:";
			cout << base_of_lombard[i].name.str;
			cout << endl;
			cout << "Отчество:";
			cout << base_of_lombard[i].middleName.str;
			cout << endl;
			cout << "Дата рождения:";
			cout << base_of_lombard[i].date_of_birthday.str;
			cout << endl;
			cout << "Место проживания:";
			cout << base_of_lombard[i].place_of_live.str;
			cout << endl;
			cout << "                     " << "Информация о товаре" << "\n";
			cout << "Наименование товара:";
			cout << base_of_lombard[i].name_of_product.str;
			cout << endl;
			cout << "Оценочная стоимость:";
			cout << base_of_lombard[i].sum.limb;
			cout << endl;
			cout << "Сумма под залог:";
			cout << base_of_lombard[i].sum_of_client.limb;
			cout << endl;
			cout << "Дата сдачи:";
			cout << base_of_lombard[i].date_of_issue.str;
			cout << endl;
			cout << "Срок хранения:";
			cout << base_of_lombard[i].shelfLife.str;
			cout << endl;

		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void search()
{
	char name[16];
	cout << "Введите наименование товара:" << "\n";
	cin >> name;
	for (int z = 0; z < current_size; z++)
	{
		if (strcmp(name, base_of_lombard[z].name_of_product.str) == 0)
		{
			cout << " " << "\nАнкета клиента: " << "\n\n";
			cout << "Фамилия:";
			cout << base_of_lombard[z].surname.str;
			cout << endl;
			cout << "Имя:";
			cout << base_of_lombard[z].name.str;
			cout << endl;
			cout << "Отчество:";
			cout << base_of_lombard[z].middleName.str;
			cout << endl;
			cout << "Дата рождения:";
			cout << base_of_lombard[z].date_of_birthday.str;
			cout << endl;
			cout << "Место проживания:";
			cout << base_of_lombard[z].place_of_live.str;
			cout << endl;
			cout << " " << "\nИнформация о товаре: " << "\n\n";
			cout << "Наименование товара:";
			cout << base_of_lombard[z].name_of_product.str;
			cout << endl;
			cout << "Оценочаня стоимость:";
			cout << base_of_lombard[z].sum.limb;
			cout << endl;
			cout << "Сумма под залог:";
			cout << base_of_lombard[z].sum_of_client.limb;
			cout << endl;
			cout << "Дата сдачи:";
			cout << base_of_lombard[z].date_of_issue.str;
			cout << endl;
			cout << "Срок хранения:";
			cout << base_of_lombard[z].shelfLife.str;
			cout << endl;

		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void writeInFile() {
			ofstream inFile;
			int indicate = 0;
			inFile.open("lombard.txt");
			for (int i = 0; i < 30; i++) {
				if (base_of_lombard[i].name.str[0] == 0) {
					break;
				}
				inFile << "ФИО: " << base_of_lombard[i].surname.str << " " << base_of_lombard[i].name.str
					<< " " << base_of_lombard[i].middleName.str << "\n";
				inFile << "Дата рождения: " << base_of_lombard[i].date_of_birthday.str << "\n";
				inFile << "Адрес: " << base_of_lombard[i].place_of_live.str << "\n";
				inFile << "Наименование товара: " << base_of_lombard[i].name_of_product.str << "\n";
				inFile << "Оценочная стоимость: " << base_of_lombard[i].sum.limb << "\n";
				inFile << "Сумма под залог: " << base_of_lombard[i].sum_of_client.limb  << "\n";
				inFile << "Дата сдачи: " << base_of_lombard[i].date_of_issue.str << "\n";
				inFile << "Срок хранения: " << base_of_lombard[i].shelfLife.str << "\n";
				indicate++;
			}
			if (indicate == 0) {
				cout << "\nДанные не найдены!\n";
			}
			else { cout << "\nДанные записаны в файл lombard.txt\n"; }
			inFile.close();
			cout << "Что дальше?" << endl;
			cin >> choice;
		}
void readFromFile() {
	int category = 0, j = 0;
	ifstream fromFile;
	fromFile.open("lombard.txt", ifstream::app);
	string sentence = "1";
	while (sentence != "") {
		getline(fromFile, sentence);
		if (sentence == "" || sentence == base_of_lombard[j-1].name.str && j != 0) {
			break;
		}
		else if (category == 0) {
			for (int k = 0; k < sentence.size(); k++) {
				base_of_lombard[j].surname.str[k] = sentence[k];
			}
			category++;
		}
		else if (category == 1) {
			for (int k = 0; k < sentence.size(); k++) {
				base_of_lombard[j].name.str[k] = sentence[k];
			}
			category++;
		}
		else if (category == 2) {
			for (int k = 0; k < sentence.size(); k++) {
				base_of_lombard[j].middleName.str[k] = sentence[k];
			}
			category++;
		}
		else if (category == 3) {
			for (int k = 0; k < sentence.size(); k++) {
				base_of_lombard[j].date_of_birthday.str[k] = sentence[k];
			}
			category++;
		}
		else if (category == 4) {
			for (int k = 0; k < sentence.size(); k++) {
				base_of_lombard[j].place_of_live.str[k] = sentence[k];
			}
			category++;
		}
		else if (category == 5) {
			for (int k = 0; k < sentence.size(); k++) {
				base_of_lombard[j].name_of_product.str[k] = sentence[k];
			}
			category++;
		}
		else if (category == 6) {
			for (int k = 0; k < sentence.size(); k++) {
				base_of_lombard[j].sum.limb[k] = sentence[k];
			}
			category++;
		}
		else if (category == 7) {
			for (int k = 0; k < sentence.size(); k++) {
				base_of_lombard[j].sum_of_client.limb[k] = sentence[k];
			}
			category++;
		}
		else if (category == 8) {
			for (int k = 0; k < sentence.size(); k++) {
				base_of_lombard[j].date_of_issue.str[k] = sentence[k];
			}
			category++;
		}
		else if (category == 9) {
			for (int k = 0; k < sentence.size(); k++) {
				base_of_lombard[j].shelfLife.str[k] = sentence[k];
			}
			category = 0;
			j++;
		}
	}
	if (j == 0) {
		cout << "\nНет данных в файле!\n\n";
	}
	else { cout << "\nДанные считаны из файла lombard.txt!\n\n"; }
	fromFile.close();
	current_size = j;
	cout << "Что дальше?" << endl;
	cin >> choice;
}