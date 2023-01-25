#include <iostream>
#include <fstream>
#include <windows.h> // 2 варик

using namespace std;

//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    int j = 0, word = 0, l = 0;
//    char letter;
//    char stringFILE1[255] = {};
//    char StringFILE2[255] = {};
//    ifstream file1;
//    ofstream file2;
//    file1.open("FILE1.txt");
//    for (int i = 0; !file1.eof() && file1.get(letter) && i < 255; i++) {
//        stringFILE1[i] = letter;
//    }
//    file1.close();
//    file2.open("FILE2.txt");
//    for (int i = 0; i < 255; i++) {
//        if (stringFILE1[i] == '\n') {
//            if (stringFILE1[i + 1] == 'А') {
//                j = i + 1;
//                for (; stringFILE1[j] != '\n' && stringFILE1[j] != 0; j++, l++) {
//                    file2 << stringFILE1[j];
//                    StringFILE2[l] = stringFILE1[j];
//                }
//                file2 << '\n';
//                StringFILE2[l] = '\n';
//                l++;
//            }
//        }
//        else if (i == 0 && stringFILE1[i] == 'А') {
//            for (; stringFILE1[j] != '\n' && stringFILE1[j] != 0; j++, l++) {
//                file2 << stringFILE1[j];
//                StringFILE2[l] = stringFILE1[j];
//               }
//            file2 << '\n';
//            StringFILE2[l] = '\n';
//            l++;
//        }
//    }
//    for (int i = 0; StringFILE2[i] != 0; i++) {
//        if (i == 0) { word++; }
//        if (StringFILE2[i] == ' ') {
//            word++;
//        }
//        else if (StringFILE2[i] == '\n' && StringFILE2[i+1] != 0) {
//            word++;
//        }
//    }
//    file2 << "Всего слов: " << word;
//    file2.close();
//    return 0;
//}

int main() {
	char string[255]= {};
	char data[255] = {};
	int first = 0, second = 256, j, start = 0;
	cin.getline(string,255);
	ofstream file1out("FILE1.txt");
	for (int i = 0; i < 255; i++) {
		file1out << string[i];
	}
	file1out.close();
	ifstream file1input("FILE1.txt");
	file1input.getline(data, 255);
	for (int i = 0; i < 255; i++) {
		if (data[i] != ' ' && data[i] != 0) {
			first++;
		}
		if (data[i] == 0 || data[i] == ' ') {
			if (first < second && first != 0) {
				second = first;
				first = 0;
				j = i;
			}
			else { first = 0; }
		}
	}
	start = j;
	for (; data[j - 1] != ' ' && j != 0; j--) {
		start = j;
	}
	start--;
	cout << endl;
	for (; data[start] != ' ' && data[start] != 0; start++) {
		cout << data[start];
	}
	file1input.close();
}
