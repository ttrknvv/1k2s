#include <iostream>
#include <fstream>
#include <windows.h> 
#include <string>

void inputData();
int menu();
void outputData();
void deleteData();
void searchData();
void writeInFile();
void readFromFile();

struct vokzal {
	char numberTrain[4] = {}, daysIn[4] = {}, nameOut[30] = {}, timeOut[6] = {}, timeIn[6] = {};
};
struct vokzal train[30];

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
	return 0;
}

int menu() {
	int vibor = 0;
	cout << "\n1 - Ввести данные\n" << "2 - Вывод данных в консоль" << "\n3 - Удаление информации поезда по пункту назначения"
		<< "\n4 - Поиск информации поезда по пункту назначения" << "\n5 - Запись информации в файл" << "\n6 - Чтение данных\n"
		<< "0 - Выход\n" << "Выбор: ";
	cin >> vibor;
	cout << endl;
	switch (vibor) {
	case 0: break;;
	case 1: inputData();
		break;
	case 2: outputData();
		break;
	case 3: deleteData();
		break;
	case 4: searchData();
		break;
	case 5: writeInFile();
		break;
	case 6: readFromFile();
		break;
	}
	return 0;
}
void inputData() {
	int vibor = 0;
	for (int i = 0; i < 30; i++) {
		cout << "Для выхода введите 0, иначе любое другое число\n";
		cin >> vibor;
		if (vibor == 0) {
			break;
		}
		cin.ignore();

		cout << "Номер поезда: ";
		cin.getline(train[i].numberTrain,4);    // номер поезда

		cout << "Пункт назначения: ";
		cin.getline(train[i].nameOut, 30);   // пункт назначения

		cout << "Дни следования: ";
		cin.getline(train[i].daysIn,4);						// дни следования

		cout << "Время прибытия: ";
		cin.getline(train[i].timeOut, 6); // время прибытия
		
		cout << "Время отправления: ";
		cin.getline(train[i].timeIn, 6);				// время отправления
	}
	menu();
}
void outputData() {
	for (int i = 0; i < 30; i++) {
		if (train[i].numberTrain[0] == '\0' && train[i].daysIn[0] == '\0') {
			break;
		}
		cout << "Номер поезда: " << train[i].numberTrain << endl;
		cout << "Пункт назначения: " << train[i].nameOut << endl;
		cout << "Дни следования: " << train[i].daysIn << endl;
		cout << "Время прибытия: " << train[i].timeOut << endl;
		cout << "Время отправления: " << train[i].timeIn << endl << endl;
	}
	if (train[0].numberTrain[0] == '\0' && train[0].daysIn[0] == '\0') {
		cout << "\n!!!Нет данных!!!\n";
	}
	menu();
}
void deleteData() {
	string name;
	int j = 0, indicate = 0;
	cout << "Введите название пункта назначения: ";
	cin.ignore();
	cin >> name;
	for (int i = 0; train[i].numberTrain[0] != 0 && train[i].daysIn[0] != 0; i++) {
		if (train[i].nameOut == name && train[i + 1].numberTrain[0] != 0 && train[i + 1].daysIn[0] != 0) {
			for (j = i; train[j + 1].numberTrain[0] != 0 && train[j + 1].daysIn[0] != 0; j++) {
				for (int k = 0; k < 4; k++) {
					train[j].numberTrain[k] = 0;
					train[j].numberTrain[k] = train[j + 1].numberTrain[k];
				}
				for (int k = 0; k < 30; k++) {
					train[j].nameOut[k] = 0;
					train[j].nameOut[k] = train[j + 1].nameOut[k];
				}
				for (int k = 0; k < 4; k++) {
					train[j].daysIn[k] = 0;
					train[j].daysIn[k] = train[j + 1].daysIn[k];
				}
				for (int k = 0; k < 6; k++) {
					train[j].timeOut[k] = 0;
					train[j].timeOut[k] = train[j + 1].timeOut[k];
				}
				for (int k = 0; k < 6; k++) {
					train[j].timeIn[k] = 0;
					train[j].timeIn[k] = train[j + 1].timeIn[k];
				}
			}
			train[j].daysIn[0] = 0;
			train[j].numberTrain[0] = 0;
			cout << "\nУдаление завершено!\n";
			indicate++;
		}
		else if (train[i].nameOut == name && train[i + 1].numberTrain[0] == 0 && train[i + 1].daysIn[0] == 0) {
			for (int k = 0; k < 30; k++) {
				train[i].nameOut[k] = 0;
			}
			for (int k = 0; k < 6; k++) {
				train[i].timeOut[k] = 0;
			}
			for (int k = 0; k < 6; k++) {
				train[i].timeIn[k] = 0;
			}
			train[i].numberTrain[0] = 0;
			train[i].daysIn[0] = 0;
			cout << "\nУдаление завершено!\n";
			indicate++;
		}
	}
	if (indicate == 0) {
		cout << "\nЭлемент не найден!\n";
	}
	menu();
}
void searchData() {
	string vibor;
	int indicate = 0;
	cout << "Введите название пункта назначения: ";
	cin >> vibor;
	for (int i = 0; i < 30; i++) {
		if (train[i].nameOut == vibor) {
			cout << "\nНайденные данные:\n\n";
			cout << "Номер поезда: " << train[i].numberTrain << endl;
			cout << "Пункт назначения: " << train[i].nameOut << endl;
			cout << "Дни следования: " << train[i].daysIn << endl;
			cout << "Время прибытия: " << train[i].timeOut << endl;
			cout << "Время отправления: " << train[i].timeIn << endl;
			indicate++;
		}
	}
	if (indicate == 0) {
		cout << "\nДанные не найдены!\n\n";
	}
	menu();
}
void writeInFile() {
	ofstream inFile;
	int indicate = 0;
	inFile.open("TRAINS.txt");
	for (int i = 0; i < 30; i++) {
		if (train[i].daysIn[0] == 0) {
			break;
		}
		inFile << "Номер поезда: " << train[i].numberTrain << "\n";
		inFile << "Пункт назначения: " << train[i].nameOut << "\n";
		inFile << "Дни следования: " << train[i].daysIn << "\n";
		inFile << "Время прибытия: " << train[i].timeOut << "\n";
		inFile << "Время отправления: " << train[i].timeIn << "\n" << "\n";
		indicate++;
	}
	if (indicate == 0) {
		cout << "\nДанные не найдены!\n";
	}
	else { cout << "\nДанные записаны в файл TRAINS.txt\n"; }
	inFile.close();
	menu();
}
void readFromFile() {
	int category = 0, i = 0;
	ifstream fromFile;
	fromFile.open("TRAINS.txt", ifstream::app);
	string sentence = "1";
	while(sentence != "") {
		getline(fromFile, sentence);
		if (sentence == "" || sentence == train[i-1].timeIn && i != 0) {
			break;
		}
		else if (category == 0) {
			for (int k = 0; k < sentence.size(); k++) {
				train[i].numberTrain[k] = sentence[k];
			}
			category++;
		}
		else if (category == 1) {
			for (int k = 0; k < sentence.size(); k++) {
				train[i].nameOut[k] = sentence[k];
			}
			category++;
		}
		else if (category == 2) {
			for (int k = 0; k < sentence.size(); k++) {
				train[i].daysIn[k] = sentence[k];
			}
			category++;
		}
		else if (category == 3) {
			for (int k = 0; k < sentence.size(); k++) {
				train[i].timeOut[k] = sentence[k];
			}
			category++;
		}
		else if (category == 4) {
			for (int k = 0; k < sentence.size(); k++) {
				train[i].timeIn[k] = sentence[k];
			}
			category = 0;
			i++;
		}
	}
	if (i == 0) {
		cout << "\nНет данных в файле!\n\n";
	}
	else { cout << "\nДанные считаны из файла TRAINS.txt!\n\n"; }
	fromFile.close();
	menu();
}

#include <iostream>
#include <windows.h>
#include <stdlib.h>

bool proverkaVisokosn(int year);
int daysInYear(int day, int month, int year);
void proverkaValidnosti(int day, int month, int year);
void daysToBirthday(int day, int month, int yearh);
void dayOfProgrammer(int day, int month, int year);
void nevalidno();
void nameOfMonth(int month);

using namespace std;

int dayInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	int vibor;
	char cData[100];
	int iData[8];
	int year = 0;
	int month = 0;
	int day = 0;
	int n = 3;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << endl << "\t!!! Для ввыхода из программы введите 0 !!!" << endl
		<< "\t!!! Для перехода к программе введите 1 !!!" << endl << endl;

	cin >> vibor;
	if (vibor == 0) {
		cout << "Выход из программы...";
		exit(0);
	}
	else if (vibor != 1) {
		cout << "Неправильно введен символ! Попробуйте еще раз!";
		main();
	}
	cin.ignore();
	cout << endl << "Введите дату в формате ДДММГГГГ для выполнения последующих функций"
		<< endl << "ДДММГГГГ = ";
	cin.getline(cData, 100);

	if (cData[8] != 0) { nevalidno(); }
	for (int i = 0; i < 8; i++) {
		iData[i] = cData[i] - '0';
		if (iData[i] > 9 || iData[i] < 0) { nevalidno(); }
	}
	for (int i = 4; i < 8; i++, n--) {
		year += iData[i] * pow(10, n);
	}
	for (int i = 0, n = 1; i < 2; i++) {
		day += iData[i] * pow(10, n);
		n--;
	}					// Отделение дня, месяца и года от массива даты
	for (int i = 2, n = 1; i < 4; i++) {
		month += iData[i] * pow(10, n);
		n--;
	}

	proverkaValidnosti(day, month, year); // Проверка на корректность даты

	if (proverkaVisokosn(year)) { cout << "Данный год является високосным" << endl; }
	// Функция проверки года на високосность
	else { cout << "Данный год является невисокосным" << endl; }



	cout << "В " << year << " году это " << daysInYear(day, month, year) << " день" << endl;
	// Вывод дня в году

	daysToBirthday(day, month, year); // Вывод количества дней до дня рождения


	dayOfProgrammer(day, month, year); // Вывод количества дней до дня программиста

	nameOfMonth(month); // Вывод названия месяца

	main();
}

bool proverkaVisokosn(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0 && year % 4 == 0));
}
int daysInYear(int day, int month, int year) {
	int daysInYear = 0;
	for (int i = 0; i < (month - 1); i++) {
		if (i == 1 && proverkaVisokosn(year)) {
			daysInYear++;
		}
		daysInYear += dayInMonth[i];
	}
	return(daysInYear + day);
}
void proverkaValidnosti(int day, int month, int year) {
	if (dayInMonth[month - 1] < day && (month - 1) != 1) {
		nevalidno();
	}
	else if ((month - 1) == 1) {
		if (proverkaVisokosn(year) && day > 29) {
			nevalidno();
		}
		else if (!proverkaVisokosn(year) && day > 28) {
			nevalidno();
		}
	}
}
void daysToBirthday(int day, int month, int year) {
	int daysToBirthday = 0;
	int yearsToBirthday = 0;
	if (year < 2004) {
		for (; year < 2004; year++) {
			if (proverkaVisokosn(year)) { daysToBirthday += 366; }
			else { daysToBirthday += 365; }
		}
		daysToBirthday += 38;
		cout << "До следующего моего дня рождения = " << daysToBirthday << " дней" << endl;
	}
	else if (daysInYear(day, month, year) < 38) {
		daysToBirthday = 38 - daysInYear(day, month, year);
		cout << "До следующего моего дня рождения = " << daysToBirthday << " дней" << endl;
	}
	else if (daysInYear(day, month, year) > 38) {
		if (proverkaVisokosn(year)) { daysToBirthday = 366 - daysInYear(day, month, year) + 38; }
		else { daysToBirthday = 365 - daysInYear(day, month, year) + 38; }
		cout << "До следующего моего дня рождения = " << daysToBirthday << " дней" << endl;
	}
	else if (daysInYear(day, month, year) == 38) {
		cout << "У меня сегодня день рождения!!! Жду поздравлений :)" << endl;
	}
}
void dayOfProgrammer(int day, int month, int year) {
	int dayOfProgrammer = 0;
	if (daysInYear(day, month, year) > 256) {
		if (proverkaVisokosn(year)) { dayOfProgrammer = 366 - daysInYear(day, month, year) + 256; }
		else { dayOfProgrammer = 365 - daysInYear(day, month, year); }
		cout << "До следующего Дня программиста осталось " << dayOfProgrammer << " дней" << endl;
	}
	else if (daysInYear(day, month, year) < 256) {
		dayOfProgrammer = 256 - daysInYear(day, month, year);
		cout << "До следующего Дня программиста осталось " << dayOfProgrammer << " дней" << endl;
	}
	else if (daysInYear(day, month, year) == 256) {
		cout << "Сегодня празднуется день программиста! Поздравляем!" << endl;
	}
}
void nevalidno() {
	cout << "Неверно введена дата! Попробуйте еще раз!";
	main();
}
void nameOfMonth(int month) {
	cout << "Текущий месяц: ";
	switch (month) {
	case 1: cout << "январь\n";
		break;
	case 2: cout << "февраль\n";
		break;
	case 3: cout << "март\n";
		break;
	case 4: cout << "апрель\n";
		break;
	case 5: cout << "май\n";
		break;
	case 6: cout << "июнь\n";
		break;
	case 7: cout << "июль\n";
		break;
	case 8: cout << "август\n";
		break;
	case 9: cout << "сентябрь\n";
		break;
	case 10: cout << "октябрь\n";
		break;
	case 11: cout << "ноябрь\n";
		break;
	case 12: cout << "декабрь\n";
		break;
	}
}