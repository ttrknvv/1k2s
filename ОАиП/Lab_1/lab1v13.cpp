#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

int main() { 
	char letter;
	int space = 0, j = 0, k = 0, x = 0;
	int startOfTheWord = 0, endOfTheWord = 0;
	int first = 0, second = 0;
	char doSortirovki [255] = {};
	char afterSortirovki[255] = {};
	char glasnie[10] = {'а','е','ё','и','о','у','ы','э','ю','я'};
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream zad1, file2;
	zad1.open("FILE1.txt", fstream::in | fstream::out | fstream::app);
	file2.open("FILE2.txt", fstream::in | fstream::out | fstream::app);
	for (int i = 0; !zad1.eof() && zad1.get(letter); i++) {
		doSortirovki[i] = letter;
	}
	for (int i = 0; i < 255; i++) {
		if (doSortirovki[i] == ' ') {
			space++;
			if (space == 2 && doSortirovki[i+1] != '\n') {
				for (; doSortirovki[j] != '\n' && doSortirovki[j] != 0; j++, k++) {
					afterSortirovki[k] = doSortirovki[j];
					cout << afterSortirovki[k];
					file2 << afterSortirovki[k];
				}
				afterSortirovki[k] = '\n';
				file2 << afterSortirovki[k];
				k++;
				
			}
		}
		if (doSortirovki[i] == '\n') {
			j = i + 1;
			space = 0;
		}
	}
	k = 0;
	for (j = 0; j < sizeof(afterSortirovki) + 1; j++) {
		if (afterSortirovki[j] == ' ' || afterSortirovki[j] == '\n' || afterSortirovki[j] == 0) {
			for (; k < j; k++) {
				for (x = 0; x < 10; x++) {
					if (afterSortirovki[k] == glasnie[x]) {
						first++;
					}
				}
			}
			if (first >= second) {
				endOfTheWord = j;
				second = first;
				first = 0;
			}
			else {
				first = 0;
			}
		}
	}
	endOfTheWord--;
	while (afterSortirovki[endOfTheWord] != ' ' && afterSortirovki[endOfTheWord] != '\n' && endOfTheWord != 0) {
		endOfTheWord--;
	}
	if (endOfTheWord != 0)
		startOfTheWord = endOfTheWord + 1;
	else
		startOfTheWord = endOfTheWord;
	file2 << "Больше всего гласных букв в слове: ";
	while (afterSortirovki[startOfTheWord] != ' ' && afterSortirovki[startOfTheWord] != '\n') {
		file2 << afterSortirovki[startOfTheWord];
		startOfTheWord++ ;
	}
	zad1.close();
	file2.close();

	return 0;
}
//int main() {
//	char inputData[50] = {}, outPutData[50] = {};
//	char skobki[6] = { '{','}', '[', ']', '(', ')', };
//	int count = 0;
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	fstream outfile1("FILE1.txt", ofstream::app);
//	cin.getline(inputData, 50);
//	for (int i = 0; i < sizeof(inputData); i++) {
//		outfile1 << (inputData[i]);
//	}
//	outfile1.close();
//	ifstream infile1("FILE1.txt", ifstream::app);
//	infile1.getline(outPutData, 50);
//	for (int i = 0; i < sizeof(outPutData); i++) {
//		for (int j = 0; j < 6; j++) {
//			if (outPutData[i] == skobki[j]) {
//				count++;
//			}
//		}
//	}
//	infile1.close();
//	outfile1.open("FILE1.txt", ofstream::app);
//	outfile1 << "\nКоличество скобок разного вида: " << count;
//	outfile1.close();
//	return 0;
//}