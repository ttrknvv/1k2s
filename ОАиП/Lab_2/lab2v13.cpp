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