#include <iostream>
#include <windows.h>

using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct date {
	day dd;
	month mm;
	year yyyy;
};

bool operator < (date date1, date date2) {
	return (date1.yyyy < date2.yyyy) || (date1.yyyy == date2.yyyy && date1.mm < date2.mm) 
		||	(date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd < date2.dd);
}

bool operator > (date date1, date date2) {
	return (date1.yyyy > date2.yyyy) || (date1.yyyy == date2.yyyy && date1.mm > date2.mm)
		|| (date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd > date2.dd);
	return !(date1 < date2);
}

bool operator == (date date1, date date2) {
	return date1.dd == date2.dd && date1.mm == date2.mm && date1.yyyy == date2.yyyy;
}

int main() {
	setlocale(LC_ALL, "rus");
	date date1 = { 7,1, 1980 }; 
	date date2 = { 7,2, 1993 };
	date date3 = { 7,1, 1980 };

	if (date1 < date2) { cout << "истина\n"; }
	else { cout << "ложь\n"; }

	if (date1 > date2) { cout << "истина\n"; }
	else { cout << "ложь\n"; }

	if (date1 == date2) { cout << "истина\n"; }
	else { cout << "ложь\n"; }

	if (date1 == date3) { cout << "истина\n"; }
	else { cout << "ложь\n"; }

	return 0;
}


