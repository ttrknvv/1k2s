#include <iostream> // 11 laba
#include <fstream>
#include <windows.h>

using namespace std;

//int main() {
//	char stringFILE1[255] = {};
//	char stringFILE2[255] = {};
//	char letter;
//	int space = 0, j = 0, start, word = 0;
//	ifstream file1;
//	ofstream file2;
//	file1.open("FILE1.txt");
//	for (int i = 0; !file1.eof() && file1.get(letter);i++) {
//		stringFILE1[i] = letter;
//	}
//	file1.close();
//	file2.open("FILE2.txt");
//	for (int i = 0; stringFILE1[i] != 0; i++) {
//		if (stringFILE1[i] == '\n') {
//			start = i + 1;
//			space = 0;
//		}
//		else if (i == 0) {
//			start = 0;
//		}
//		if (stringFILE1[i] == ' ') {
//			space++;
//		}
//		if (stringFILE1[i + 1] == '\n' || stringFILE1[i + 1] == 0) {
//			if (space == 0) {
//				for (; start <= i; start++, j++) {
//					file2 << stringFILE1[start];
//					stringFILE2[j] = stringFILE1[start];
//				}
//				if (stringFILE1[start] != 0) {
//					stringFILE2[j] = '\n';
//					file2 << '\n';
//				}
//				j++;
//			}
//		}
//	}
//	j = 0;
//	while (stringFILE2[j] != 0) {
//		if (stringFILE2[j] != '\n')
//			word++;
//		j++;
//	}
//	file2 << '\n' << "Количество символов: " << word;
//	file2.close();
//	return 0;
//}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char firstLine[50] = {};
	char secondLine[50] = {};
	char read[100] = {};
	char letter;
	int word = 0, j = 0, start, start_small, start_big;
	int result = 1000;
	ofstream outfile1;
	ifstream infile1;
	cout << "Первая строка: "; cin.getline(firstLine, 50);
	cout << "Вторая строка: "; cin.getline(secondLine, 50);
	outfile1.open("FILE1.txt");
	for (int i = 0; firstLine[i] != 0; i++) {
		outfile1 << firstLine[i];
		if (firstLine[i+1] == 0) {
			outfile1 << '\n';
		}
	}
	for (int i = 0; secondLine[i] != 0; i++) {
		outfile1 << secondLine[i];
	}
	outfile1.close();
	infile1.open("FILE1.txt");
	for (int i = 0; i < 100 && infile1.get(letter); i++) {
		read[i] = letter;
	}
	while (read[j] != '\n') {
		word++;
		if (read[j] == ' ') {
			start = j + 1;
		}
		else if (j == 0) {
			start = j;
		}
		if (read[j+1] == ' ' || read[j+1] == '\n') {
			if (result > word) {
				result = word;
				start_small = start;
			}
			word = 0;
		}
		j++;
	}
	for (; read[start_small] != ' ' && read[start_small] != '\n'; start_small++) {
		cout << read[start_small];
	}
	cout << endl;
	result = 0;
	while (read[j] != 0) {
		word++;
		if (read[j] == ' ') {
			start = j + 1;
		}
		else if (read[j] == '\n') {
			start = j;
		}
		if (read[j + 1] == ' ' || read[j + 1] == 0) {
			if (result < word) {
				result = word;
				start_big = start;
			}
			word = 0;
		}
		j++;
	}
	for (; read[start_big] != ' ' && read[start_big] != 0; start_big++) {
		cout << read[start_big];
	}
	return 0;
}