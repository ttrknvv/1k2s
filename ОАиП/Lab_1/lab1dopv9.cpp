#include <iostream> // 9 varik
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// 1 часть

int main() {
    setlocale(LC_ALL, "rus");
    int N1;
    int N2;
    int count = 1, l = 0;
    int countLine = 1;
    char stringFILE1[255] = {}, stringFILE2[255] = {};
    char letter;
    ifstream file1;
    ofstream file2;
    file1.open("FILE1.txt");
    cout << "Введите границы N1 и N2: ";
    cin >> N1 >> N2;
    for (int i = 0; !file1.eof() && file1.get(letter); i++) {
        stringFILE1[i] = letter;
    }
    file1.close();
    file2.open("FILE2.txt");
    for (int i = 0; i < 255; i++) {
        if (countLine >= N1 && countLine <= N2) {
            if (i == 0 && stringFILE1[i] == 'С') {
            for (int j = i; stringFILE1[j] != '\n' && stringFILE1[j] != 0; j++) {
                    file2 << stringFILE1[j];
                    if (stringFILE1[j] == ' ') {
                        count++;
                    }
                }
                    file2 << '\n';
                    
            }
            if (stringFILE1[i] == 'С' && stringFILE1[i - 1] == '\n') {
                for (int j = i; stringFILE1[j] != '\n' && stringFILE1[j] != 0; j++, l++) {
                    file2 << stringFILE1[j];
                    if (stringFILE1[j] == ' ') {
                        count++;
                    }
                    stringFILE2[l] = stringFILE1[j];
                }
                file2 << '\n';
                stringFILE2[l] = '\n'; l++;
            }
        }
        if (stringFILE1[i] == '\n') {
            countLine++;
        }
    }
    if (N1 != 1 && stringFILE1[0] == 'С') {
        for (int i = 0; stringFILE2[i] != '\n' && stringFILE2[i] != 0; i++) {
            if (stringFILE2[i] == ' ') {
                count++;
            }
        }
        }
    file2 << "Количество слов в первой строке: " << count;
    file2.close();
    return 0;
}

// 2 часть
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    char stringFILE[255] = {};
//    char letter;
//    int minim = INT_MAX;
//    int id;
//    int count = 0;
//    int countSpace = 1;
//    int place;
//    cin.getline(stringFILE, 255);
//    ofstream outfile1("FILE1.txt");
//    for (int i = 0; i < 255; i++) {
//        outfile1 << stringFILE[i];
//    }
//    outfile1.close();
//    ifstream infile1("FILE1.txt");
//    for (int i = 0; !infile1.eof() && infile1.get(letter); i++) {
//        stringFILE[i] = letter;
//    }
//        for (int i = 0; i < 255; i++) {
//            if (stringFILE[i] != ' ' && stringFILE[i] != 0)
//                count++;
//            else {
//                if (minim > count) {
//                    minim = count;
//                    id = i - count;
//                    place = countSpace;
//                }
//                countSpace++;
//                if (stringFILE[i] != 0)
//                count = 0;
//            }
//        }
//        for (int i = id; i <= id + minim; i++) {
//            cout << stringFILE[i];
//        }
//        cout << endl << "Кол-во букв в слове: " << minim;
//        cout << endl << "Слово по счету: " << place;
//    }
// 