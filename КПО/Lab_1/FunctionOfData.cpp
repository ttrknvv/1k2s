#include <iostream>
#include <windows.h>
#include <stdlib.h>

bool proverkaVisokosn(int year);
int daysInYear(int day, int month, int year);
void proverkaValidnosti(int day, int month, int year);
void daysToBirthday(int day, int month, int yearh);
void dayOfProgrammer(int day, int month, int year);
void nevalidno();

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
	
	if (proverkaVisokosn(year)) {cout << "Данный год является високосным" << endl;}
	// Функция проверки года на високосность
	else {cout << "Данный год является невисокосным" << endl;}
	
	cout << "В " << year << " году это " << daysInYear(day, month, year) << " день" << endl; 
	// Вывод дня в году
	
	daysToBirthday(day, month, year); // Вывод количества дней до дня рождения
	
	
	dayOfProgrammer(day, month, year); // Вывод количества дней до дня программиста
	
	main();
}

bool proverkaVisokosn(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0 && year % 4 == 0));
}
int daysInYear(int day, int month, int year) {
	int daysInYear = 0;
	/*for (int i = 1; i < month && i <= 7; i++) {
		if (i == 2) {
			if (proverkaVisokosn(year)) {daysInYear += 29;}
			else {daysInYear += 28;}
		}
		else if (i % 2 == 0) { daysInYear += 30; }
		else if (i % 2 != 0) { daysInYear += 31; }
	}
	for (int i = 8; i < month && i < 12; i++) {
		if (i % 2 != 0) { daysInYear += 30; }
		else if (i % 2 == 0) { daysInYear += 31; }
	}
	return (daysInYear + day);*/
	for (int i = 0; i < (month - 1); i++) {
		if (i == 1 && proverkaVisokosn(year)) {
			daysInYear++;
		}
		daysInYear+= dayInMonth[i];
	}
	return(daysInYear + day);
} 
void proverkaValidnosti(int day, int month, int year) {
	/*if (month <= 7) {
		if (month == 2) {
			if (proverkaVisokosn(year) && day > 29) {nevalidno();}
			else if (!proverkaVisokosn(year) && day > 28) {nevalidno();}
		}
		else if (month % 2 == 0 && day > 30) {nevalidno();}
		else if (month % 2 != 0 && day > 31) {nevalidno();}
	}
	else if (month > 7) {
		if (month % 2 != 0 && day > 30) {nevalidno();}
		else if (month % 2 == 0 && day > 31) {nevalidno();}
	}*/
	if (dayInMonth[month-1] < day && (month-1) != 1) {
		nevalidno();
	}
	else if((month-1) == 1) {
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
			if (proverkaVisokosn(year)) {daysToBirthday += 366;}
			else {daysToBirthday += 365;}
	}
		daysToBirthday += 38;
		cout << "До следующего моего дня рождения = " << daysToBirthday << " дней" << endl;
}
	else if(daysInYear(day, month, year) < 38) {
		daysToBirthday = 38 - daysInYear(day, month, year);
		cout << "До следующего моего дня рождения = " << daysToBirthday << " дней" << endl;
	}
	else if (daysInYear(day, month, year) > 38) {
		if (proverkaVisokosn(year)) {daysToBirthday = 366 - daysInYear(day, month, year) + 38;}
		else {daysToBirthday = 365 - daysInYear(day, month, year) + 38;}
		cout << "До следующего моего дня рождения = " << daysToBirthday << " дней" << endl;
	}
	else if (daysInYear(day, month, year) == 38) {
		cout << "У меня сегодня день рождения!!! Жду поздравлений :)" << endl;
	}
}
void dayOfProgrammer(int day, int month, int year) {
	int dayOfProgrammer = 0;
	if (daysInYear(day, month, year) > 256) {
		if (proverkaVisokosn(year)) {dayOfProgrammer = 366 - daysInYear(day, month, year) + 256;}
		else {dayOfProgrammer = 365 - daysInYear(day, month, year);}
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