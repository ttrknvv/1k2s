//#include <iostream> // 4 задание 13 вариант
//#include <windows.h>
//
//void inputData();
//int menu();
//void outputData();
//void deleteData();
//void searchData();
//
//using namespace std;
//
//struct exampleForStudent {
//	char fio[50] = {}, speciality[30] = {};
//	string faculty;
//	unsigned dateOfEnter:12;
//	int group = -1;
//	float GPA = 0;
//};
//exampleForStudent student[30];
//
//enum faculties {
//	fit, htit, tov, iaf, lf
//};
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	menu();
//	return 0;
//}
//
//int menu() {
//	int vibor;
//	cout << "\n1 - Ввод данных\n2 - Вывод данных\n3 - Удаление данных\n4 - Поиск данных\n0 - Выход из програмы"
//		<< "\nВыбор: ";
//	cin >> vibor;
//	cout << endl;
//	switch (vibor) {
//		case 0: break;
//		case 1:inputData();
//			break;
//		case 2:outputData();
//			break;
//		case 3:deleteData();
//			break;
//		case 4: searchData();
//			break;
//	}
//	return 0;
//}
//void inputData() {
//	int vibor, chislo, change;
//	for (int i = 0; i < 30; i++) {
//		cout << "Для выхода введите 0, иначе любое другое число\n";
//		cin >> vibor;
//		if (vibor == 0) {
//			break;
//		}
//		cin.ignore();
//
//		cout << "ФИО студента: ";
//		cin.getline(student[i].fio, 50);   
//
//		cout << "Дата поступления: ";
//		cin >> chislo;
//		student[i].dateOfEnter = chislo;  
//		cin.ignore();
//
//		cout << "Специальность: ";
//		cin.getline(student[i].speciality, 30);						
//
//		cout << "Группа: ";
//		cin >> student[i].group; 
//		cin.ignore();
//
//		cout << "Факультет:\n0 - ФИТ\n1 - ХТИТ\n2 - ТОВ\n3 - ИЭФ\n4 - ЛФ\nВыбор: ";
//		cin >> change;
//		switch (change) {
//		case fit:
//			student[i].faculty = "ФИТ";
//			break;
//		case htit:
//			student[i].faculty = "ХТИТ";
//			break;
//		case tov:
//			student[i].faculty = "ТОВ";
//			break;
//		case iaf:
//			student[i].faculty = "ИЭФ";
//			break;
//		case lf:
//			student[i].faculty = "ЛФ";
//			break;
//		}
//		
//		cout << "Срений балл: ";
//		cin >> student[i].GPA;
//	}
//	menu();
//}
//void outputData() {
//	for (int i = 0; i < 30; i++) {
//		if (student[i].group == -1) {
//			break;
//		}
//		cout << "ФИО: " << student[i].fio << endl;
//		cout << "Дата поступления: " << student[i].dateOfEnter << endl;
//		cout << "Специальность: " << student[i].speciality << endl;
//		cout << "Группа: " << student[i].group << endl;
//		cout << "Факультет: " << student[i].faculty << endl;
//		cout << "Средний балл: " << student[i].GPA << endl << endl;
//	}
//	if (student[0].group == -1) {
//		cout << "\n!!!Нет данных!!!\n\n";
//	}
//	menu();
//}
//void deleteData() {
//	float number;
//	int j = 0, indicate = 0;
//	cout << "Введите средний балл: ";
//	cin >> number;
//	for (int i = 0; student[i].group != -1; i++) {
//		if (student[i].GPA == number && student[i + 1].group != -1) {
//			for (j = i; student[j + 1].group != -1; j++) {
//				for (int k = 0; k < 50; k++) {
//					student[j].fio[k] = 0;
//					student[j].fio[k] = student[j + 1].fio[k];
//				}
//				student[j].dateOfEnter = student[j + 1].dateOfEnter;
//				for (int k = 0; k < 30; k++) {
//					student[j].speciality[k] = 0;
//					student[j].speciality[k] = student[j + 1].speciality[k];
//				}
//				student[j].group = student[j + 1].group;
//				
//					student[j].faculty = student[j + 1].faculty;
//				
//				student[j].GPA = student[j + 1].GPA;
//			}
//			student[j].group = -1;
//			cout << "\nУдаление завершено!\n";
//			indicate++;
//		}
//		else if (student[i].GPA == number && student[i + 1].group == -1) {
//			for (int k = 0; k < 50; k++) {
//				student[i].fio[k] = 0;
//			}
//			student[i].dateOfEnter = 0;
//			student[i].GPA = 0;
//			for (int k = 0; k < 30; k++) {
//				student[j].speciality[k] = 0;
//			}
//			student[i].faculty = "";	
//			student[i].group = -1;
//			cout << "\nУдаление завершено!\n";
//			indicate++;
//		}
//	}
//	if (indicate == 0) {
//		cout << "\nЭлемент не найден!\n";
//	}
//	menu();
//}
//void searchData() {
//	float vibor;
//	int indicate = 0;
//	cout << "Введите средний балл: ";
//	cin >> vibor;
//	for (int i = 0; i < 30; i++) {
//		if (student[i].GPA == vibor) {
//			cout << "\nНайденные данные:\n\n";
//			cout << "ФИО: " << student[i].fio << endl;
//			cout << "Дата поступления: " << student[i].dateOfEnter << endl;
//			cout << "Специальность: " << student[i].speciality << endl;
//			cout << "Группа: " << student[i].group << endl;
//			cout << "Факультет: " << student[i].faculty << endl;
//			cout << "Средний балл: " << student[i].GPA << endl;
//			indicate++;
//		}
//	}
//	if (indicate == 0) {
//		cout << "\nДанные не найдены!\n\n";
//	}
//	menu();
//}

//
//#include <iostream> // 12 вариант 4 задание
//#include <fstream>
//#include <windows.h>
//# define str_len 256
//# define size 100
//using namespace std;
//void enter_new();
//void out();
//void del();
//void search();
//struct notebook
//{
//	char name[str_len];
//	char surname[str_len];
//	char middleName[str_len];
//	unsigned day : 4;
//	unsigned month : 4;
//	unsigned year : 4;
//	char addres[str_len];
//	int phone;
//	char place_of_work[str_len];
//	char position[str_len];
//};
//struct notebook people_in_notebook[size];
//int current_size = 0; int choice;
//notebook all;
//notebook b;
//int l, z, x;
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	cout << "Введите:" << endl;
//	cout << "1-для ввода записи" << endl;
//	cout << "2-для вывода записи" << endl;
//	cout << "3-для удаления" << endl;
//	cout << "4-для поиска информации" << endl;
//	cout << "5-для выхода" << endl;
//	cin >> choice;
//	do
//	{
//		switch (choice)
//		{
//		case 1: enter_new(); break;
//		case 2: out(); break;
//		case 3: del(); break;
//		case 4: search(); break;
//
//
//		}
//	} while (choice != 5);
//	return 0;
//}
//void enter_new()
//{
//	cout << "Ввод информации" << endl;
//	if (current_size < size)
//	{
//		cout << "Строка номер ";
//		cout << current_size + 1;
//		cout << endl << "Фамилия" << endl;
//		cin >> people_in_notebook[current_size].surname;
//		cout << "Имя" << endl;
//		cin >> people_in_notebook[current_size].name;
//		cout << "Отчество" << endl;
//		cin >> people_in_notebook[current_size].middleName;
//		cout << "Дата рождения: " << endl;
//		cout << "День:";
//		cin >> l; b.day = l;
//		cout << endl;
//		cout << "Месяц:";
//		cin >> z; b.month = z;
//		cout << endl;
//		cout << "Год:";
//		cin >> x; b.year = x;
//		cout << endl;
//		cin.ignore();
//		cout << "Адрес:" << endl;
//		cin.getline(people_in_notebook[current_size].addres, 256);
//		cout << "Номер телефона:" << endl;
//		cin >> people_in_notebook[current_size].phone;
//		cin.ignore();
//		cout << "Место работы:" << endl;
//		cin.getline(people_in_notebook[current_size].place_of_work,256);
//		cout << "Должность:" << endl;
//		cin.getline(people_in_notebook[current_size].position, 256);
//		current_size++;
//
//	}
//	else
//		cout << "Введено максимальное кол-во строк";
//	cout << "Что дальше?\n0 - ввести еще\n1 - закончить ввод" << endl;
//	cin >> choice;
//	switch (choice) {
//	case 0: enter_new(); break;
//	case 1: main();
//	}
//}
//void out()
//{
//	int sw, n;
//	cout << "1-вывод 1 строки" << endl;
//	cout << "2-вывод всех строк" << endl;
//	cin >> sw;
//	if (sw == 1)
//	{
//		cout << "Номер выводимой строки: " << endl; cin >> n; cout << endl;
//		cout << "Фамилия" << endl;
//		cout << people_in_notebook[n - 1].surname;
//		cout << endl;
//		cout << "Имя" << endl;
//		cout << people_in_notebook[n - 1].name;
//		cout << endl;
//		cout << "Отчество" << endl;
//		cout << people_in_notebook[n - 1].middleName;
//		cout << endl;
//		cout << "Дата рождения: " << endl;
//		cout << "День:";
//		cout << l;
//		cout << endl;
//		cout << "Месяц:";
//		cout << z;
//		cout << endl;
//		cout << "Год:";
//		cout << x;
//		cout << endl;
//		cout << "Адрес:" << endl;
//		cout << people_in_notebook[n - 1].addres;
//		cout << endl;
//		cout << "Номер телефона:" << endl;
//		cout << people_in_notebook[n - 1].phone;
//		cout << endl;
//		cout << "Место работы:" << endl;
//		cout << people_in_notebook[n - 1].place_of_work;
//		cout << endl;
//		cout << "Должность:" << endl;
//		cout << people_in_notebook[n - 1].position;
//		cout << endl;
//
//
//	}
//	if (sw == 2)
//	{
//		for (int i = 0; i < current_size; i++)
//		{
//			cout << "Фамилия" << endl;
//			cout << people_in_notebook[i].surname;
//			cout << endl;
//			cout << "Имя" << endl;
//			cout << people_in_notebook[i].name;
//			cout << endl;
//			cout << "Отчество" << endl;
//			cout << people_in_notebook[i].middleName;
//			cout << endl;
//			cout << "Дата рождения: " << endl;
//			cout << "День:";
//			cout << l;
//			cout << endl;
//			cout << "Месяц:";
//			cout << z;
//			cout << endl;
//			cout << "Год:";
//			cout << x;
//			cout << endl;
//			cout << "Адрес:" << endl;
//			cout << people_in_notebook[i].addres;
//			cout << endl;
//			cout << "Номер телефона:" << endl;
//			cout << people_in_notebook[i].phone;
//			cout << endl;
//			cout << "Место работы:" << endl;
//			cout << people_in_notebook[i].place_of_work;
//			cout << endl;
//			cout << "Должность:" << endl;
//			cout << people_in_notebook[i].position;
//			cout << endl;
//
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void del()
//{
//	int d;
//	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
//	cin >> d;
//	if (d != 99)
//	{
//		for (int de1 = (d - 1); de1 < current_size; de1++)
//			people_in_notebook[de1] = people_in_notebook[de1 + 1];
//		current_size = current_size - 1;
//	}
//	if (d == 99)
//		for (int i = 0; i < size; i++)
//			people_in_notebook[i] = all;
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void search()
//{
//	char surname[16];
//	cout << "Фамилия:" << "\n";
//	cin >> surname;
//	for (int q = 0; q < current_size; q++)
//	{
//		if (strcmp(surname, people_in_notebook[q].surname) == 0)
//		{
//			cout << "Фамилия" << endl;
//			cout << people_in_notebook[q].surname;
//			cout << endl;
//			cout << "Имя" << endl;
//			cout << people_in_notebook[q].name;
//			cout << endl;
//			cout << "Отчество" << endl;
//			cout << people_in_notebook[q].middleName;
//			cout << endl;
//			cout << "Дата рождения: " << endl;
//			cout << "День:";
//			cout << l;
//			cout << endl;
//			cout << "Месяц:";
//			cout << z;
//			cout << endl;
//			cout << "Год:";
//			cout << x;
//			cout << endl;
//			cout << "Адрес:" << endl;
//			cout << people_in_notebook[q].addres;
//			cout << endl;
//			cout << "Номер телефона:" << endl;
//			cout << people_in_notebook[q].phone;
//			cout << endl;
//			cout << "Место работы:" << endl;
//			cout << people_in_notebook[q].place_of_work;
//			cout << endl;
//			cout << "Должность:" << endl;
//			cout << people_in_notebook[q].position;
//			cout << endl;
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//
//#include <iostream>  // 3 вариант 4 задание
//#include<fstream>
//#include <windows.h>
//# define str_len 256 
//# define size 100  
//using namespace std;
//void enter_new();
//void out();
//void del();
//void search();
//struct Pupil
//{
//	char name[str_len];
//	char surname[str_len];
//	char middleName[str_len];
//	unsigned  number : 4;
//	unsigned letter : 8;
//	float average_scoree;
//};
//enum Subjects
//{
//	Math, Biology, History, Chemistry, Physics, Englysh, PE, Geography
//} subject;
//int marks;
//int average_score;
//struct Pupil pupilss_of_school[size];
//int current_size = 0; int choice;
//Pupil b;
//Pupil all;
//int l;
//char f;
//float markss[8];
//float average;
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	cout << "Введите:" << endl;
//	cout << "1-для ввода записи" << endl;
//	cout << "2-для вывода записи" << endl;
//	cout << "3-для удаления" << endl;
//	cout << "4-для поиска информации" << endl;
//	cout << "5-для выхода" << endl;
//	cin >> choice;
//	do
//	{
//		switch (choice)
//		{
//		case 1:  enter_new();	break;
//		case 2:  out();  break;
//		case 3:  del();  break;
//		case 4:  search();	break;
//
//
//		}
//	} while (choice != 5);
//}
//void enter_new()
//{
//	cout << "Вывод информации" << endl;
//	if (current_size < size)
//	{
//		cout << "Строка номер ";
//		cout << current_size + 1;
//		cout << endl << "Фамилия" << endl;
//		cin >> pupilss_of_school[current_size].surname;
//		cout << "Имя" << endl;
//		cin >> pupilss_of_school[current_size].name;
//		cout << "Отчество" << endl;
//		cin >> pupilss_of_school[current_size].middleName;
//		cout << "Класс: " << endl;
//		cin >> l; b.number = l;
//		cin >> f; b.letter = f;
//		cout << "Предметы:" << endl;
//		Subjects::Math;
//		cout << "Математка:";
//		cin >> markss[0];
//		cout << "\n";
//		Subjects::Biology;
//		cout << "Биология:";
//		cin >> markss[1];
//		cout << "\n";
//		Subjects::History;
//		cout << "История:";
//		cin >> markss[2];
//		cout << "\n";
//		Subjects::Chemistry;
//		cout << "Химия:";
//		cin >> markss[3];
//		cout << "\n";
//		Subjects::Physics;
//		cout << "Физика:";
//		cin >> markss[4];
//		cout << "\n";
//		Subjects::Englysh;
//		cout << "Английский:";
//		cin >> markss[5];
//		cout << "\n";
//		Subjects::PE;
//		cout << "Физкультура:";
//		cin >> markss[6];
//		cout << "\n";
//		Subjects::Geography;
//		cout << "География:";
//		cin >> markss[7];
//		cout << "\n";
//		cout << "Средний балл:" << endl;
//		average = ((markss[0] + markss[1] + markss[2] + markss[3] + markss[4] + markss[5] + markss[6] + markss[7]) / 8);
//		cout << average << "\n";
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
//		cout << "Номер выводимой строки: " << endl;   cin >> n;  cout << endl;
//		cout << "Фамилия:";
//		cout << pupilss_of_school[n - 1].surname << endl;
//		cout << "Имя:";
//		cout << pupilss_of_school[n - 1].name << endl;
//		cout << "Отчество:";
//		cout << pupilss_of_school[n - 1].middleName << endl;
//		cout << "Класс: " << endl;
//		cout << l;
//		cout << f;
//		cout << "\n";
//		cout << "Предметы и оценки:" << endl;
//		Subjects::Math;
//		cout << "Математка:";
//		cout << markss[0];
//		cout << "\n";
//		Subjects::Biology;
//		cout << "Биология:";
//		cout << markss[1];
//		cout << "\n";
//		Subjects::History;
//		cout << "История:";
//		cout << markss[2];
//		cout << "\n";
//		Subjects::Chemistry;
//		cout << "Химия:";
//		cout << markss[3];
//		cout << "\n";
//		Subjects::Physics;
//		cout << "Физика:";
//		cout << markss[4];
//		cout << "\n";
//		Subjects::Englysh;
//		cout << "Английский:";
//		cout << markss[5];
//		cout << "\n";
//		Subjects::PE;
//		cout << "Физкультура:";
//		cout << markss[6];
//		cout << "\n";
//		Subjects::Geography;
//		cout << "География:";
//		cout << markss[7];
//		cout << "\n";
//		cout << "Средний балл:" << endl;
//		cout << average << "\n";
//
//	}
//	if (sw == 2)
//	{
//		for (int i = 0; i < current_size; i++)
//		{
//			cout << "Фамилия:";
//			cout << pupilss_of_school[i].surname << endl;
//			cout << "Имя:";
//			cout << pupilss_of_school[i].name << endl;
//			cout << "Отчество:";
//			cout << pupilss_of_school[i].middleName << endl;
//			cout << "Класс: " << endl;
//			cout << l;
//			cout << f;
//			cout << "\n";
//			cout << "Предметы и оценки:" << endl;
//			Subjects::Math;
//			cout << "Математка:";
//			cout << markss[0];
//			cout << "\n";
//			Subjects::Biology;
//			cout << "Биология:";
//			cout << markss[1];
//			cout << "\n";
//			Subjects::History;
//			cout << "История:";
//			cout << markss[2];
//			cout << "\n";
//			Subjects::Chemistry;
//			cout << "Химия:";
//			cout << markss[3];
//			cout << "\n";
//			Subjects::Physics;
//			cout << "Физика:";
//			cout << markss[4];
//			cout << "\n";
//			Subjects::Englysh;
//			cout << "Английский:";
//			cout << markss[5];
//			cout << "\n";
//			Subjects::PE;
//			cout << "Физкультура:";
//			cout << markss[6];
//			cout << "\n";
//			Subjects::Geography;
//			cout << "Ã=ГЕография:";
//			cout << markss[7];
//			cout << "\n";
//			cout << "Средний балл:" << endl;
//			cout << average << "\n";
//			cout << "_________________________________________________________________________________" << "\n";
//
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void del()
//{
//	int d;
//	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
//	cin >> d;
//	if (d != 99)
//	{
//		for (int de1 = (d - 1); de1 < current_size; de1++)
//			pupilss_of_school[de1] = pupilss_of_school[de1 + 1];
//		current_size = current_size - 1;
//	}
//	if (d == 99)
//		for (int i = 0; i < size; i++)
//			pupilss_of_school[i] = all;
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void search()
//{
//	char surname[16];
//	cout << "Фамилия учащегося:" << "\n";
//	cin >> surname;
//	for (int z = 0; z < current_size; z++)
//	{
//		if (strcmp(surname, pupilss_of_school[z].surname) == 0)
//		{
//			cout << "Фамилия:";
//			cout << pupilss_of_school[z].surname << endl;
//			cout << "Имя:";
//			cout << pupilss_of_school[z].name << endl;
//			cout << "Отчество:";
//			cout << pupilss_of_school[z].middleName << endl;
//			cout << "Класс: " << endl;
//			cout << l;
//			cout << f;
//			cout << "\n";
//			cout << "Предметы и оценки:" << endl;
//			Subjects::Math;
//			cout << "Математка:";
//			cout << markss[0];
//			cout << "\n";
//			Subjects::Biology;
//			cout << "Биология:";
//			cout << markss[1];
//			cout << "\n";
//			Subjects::History;
//			cout << "История:";
//			cout << markss[2];
//			cout << "\n";
//			Subjects::Chemistry;
//			cout << "Химия:";
//			cout << markss[3];
//			cout << "\n";
//			Subjects::Physics;
//			cout << "Физика:";
//			cout << markss[4];
//			cout << "\n";
//			Subjects::Englysh;
//			cout << "Английский:";
//			cout << markss[5];
//			cout << "\n";
//			Subjects::PE;
//			cout << "Физкультура:";
//			cout << markss[6];
//			cout << "\n";
//			Subjects::Geography;
//			cout << "Ã=ГЕография:";
//			cout << markss[7];
//			cout << "\n";
//			cout << "Средний балл:" << endl;
//			cout << average << "\n";
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//
#include <iostream> // 7 вариант 4 задание
#include<fstream> 
#include <windows.h>
# define str_len 256
# define size 100
using namespace std;
void enter_new();
void out();
void del();
void search();
struct Sklad
{
	char name_of_product[str_len];
	float cell;
	int many;
	int per;
};
enum Percent
{
	five = 5, seven = 7, eleven = 11, twenty = 20, twentyFive = 25, thirty = 30
};
Sklad productOnSclad[size];
Sklad all;
int choice; int current_size = 0;
int sell;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для удаления" << endl;
	cout << "4-для поиска информации" << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1: enter_new(); break;
		case 2: out(); break;
		case 3: del(); break;
		case 4: search(); break;


		}
	} while (choice != 5);
}
void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Наименование товара" << endl;
		cin >> productOnSclad[current_size].name_of_product;
		cout << "Цена" << endl;
		cin >> productOnSclad[current_size].cell;
		cout << "Количество" << endl;
		cin >> productOnSclad[current_size].many;
		cout << "Процентная надбавка" << endl;
		cin >> productOnSclad[current_size].per;
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
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Строка номер "; cin >> n;
		cout << endl << "Наименование товара:" << endl;
		cout << productOnSclad[n - 1].name_of_product << endl;
		cout << "Цена:" << endl;
		cout << productOnSclad[n - 1].cell << endl;
		cout << "Количество:" << endl;
		cout << productOnSclad[n - 1].many << endl;
		if (productOnSclad[n - 1].per == 5)
		{
			cout << "Процентная надбавка=" << five << "%" << endl;
		}
		else if (productOnSclad[n - 1].per == 7)
		{
			cout << "Процентная надбавка=" << seven << "%" << endl;
		}
		else if (productOnSclad[n - 1].per == 11)
		{
			cout << "Процентная надбавка=" << eleven << "%" << endl;
		}
		else if (productOnSclad[n - 1].per == 20)
		{
			cout << "Процентная надбавка=" << twenty << "%" << endl;
		}
		else if (productOnSclad[n - 1].per == 25)
		{
			cout << "Процентная надбавка=" << twentyFive << "%" << endl;
		}
		else if (productOnSclad[n - 1].per == 30)
		{
			cout << "Процентная надбавка=" << thirty << "%" << endl;
		}

	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "Наименование товара:" << endl;
			cout << productOnSclad[i].name_of_product << endl;
			cout << "Цена:" << endl;
			cout << productOnSclad[i].cell << endl;
			cout << "Количество:" << endl;
			cout << productOnSclad[i].many << endl;
			if (productOnSclad[i].per == 5)
			{
				cout << "Процентная надбавка=" << five << "%" << endl;
			}
			else if (productOnSclad[i].per == 7)
			{
				cout << "Процентная надбавка=" << seven << "%" << endl;
			}
			else if (productOnSclad[i].per == 11)
			{
				cout << "Процентная надбавка=" << eleven << "%" << endl;
			}
			else if (productOnSclad[i].per == 20)
			{
				cout << "Процентная надбавка=" << twenty << "%" << endl;
			}
			else if (productOnSclad[i].per == 25)
			{
				cout << "Процентная надбавка=" << twentyFive << "%" << endl;
			}
			else if (productOnSclad[i].per == 30)
			{
				cout << "Процентная надбавка=" << thirty << "%" << endl;
			}

		}

	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			productOnSclad[de1] = productOnSclad[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			productOnSclad[i] = all;
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void search()
{
	cout << "Цена товара:" << "\n";
	cin >> sell;
	for (int z = 0; z < current_size; z++)
	{
		if (sell == productOnSclad[z].cell)
		{
			cout << endl << "Наименование товара:" << endl;
			cout << productOnSclad[z].name_of_product << endl;
			cout << "Цена:" << endl;
			cout << productOnSclad[z].cell << endl;
			cout << "Количество:" << endl;
			cout << productOnSclad[z].many << endl;
			if (productOnSclad[z].per == 5)
			{
				cout << "Процентная надбавка=" << five << "%" << endl;
			}
			else if (productOnSclad[z].per == 7)
			{
				cout << "Процентная надбавка=" << seven << "%" << endl;
			}
			else if (productOnSclad[z].per == 11)
			{
				cout << "Процентная надбавка=" << eleven << "%" << endl;
			}
			else if (productOnSclad[z].per == 20)
			{
				cout << "Процентная надбавка=" << twenty << "%" << endl;
			}
			else if (productOnSclad[z].per == 25)
			{
				cout << "Процентная надбавка=" << twentyFive << "%" << endl;
			}
			else if (productOnSclad[z].per == 30)
			{
				cout << "Процентная надбавка=" << thirty << "%" << endl;
			}

		}

	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}

