#include "Dictionary.h"
#include "stdafx.h"

using namespace Dictionary;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool a = 24, b = true, c = false;
	if (a + b + c > 1) {
		std::cout << "0";
	}
	else std::cout << "1";
	try {
	#ifdef TEST_CREATE_01
		Instance d1 = Create("очееень много слов очеень много слов очеень много слов", 5); // THROW01 "Create: превышен размер имени словаря"
	#endif

	#ifdef TEST_CREATE_02
		Instance d1 = Create("Студенты", 101); // THROW02 "Create: превышен размер максимальной емкости словаря"
	#endif
		Instance d2 = Create("Студенты", 3);
	#ifdef TEST_ADDENTRY_03
		Entry a[4] = { {1, "Макаров"}, {2, "Савченя"}, {3, "Сидоров"}, {4, "Тараканов"}};
		for (int i = 0; i < 4; i++) {
			AddEntry(d2, a[i]);				// THROW03 "AddEntry: переполнение словаря"
		}
	#endif

	#ifdef TEST_ADDENTRY_04
		Entry a[4] = { {1, "Макаров"}, {2, "Савченя"}, {1, "Сидоров"} };
		for (int i = 0; i < 3; i++) {
			AddEntry(d2, a[i]);				// THROW04 "AddEntry: дублирование идентификатора"
	}
	#endif
		Entry a[4] = { {1, "Макаров"}, {2, "Савченя"}, {3, "Сидоров"} };
		for (int i = 0; i < 3; i++) {
			AddEntry(d2, a[i]);				
		}
	#ifdef TEST_GETENTRY_05
		GetEntry(d2, 25);   // THROW05 "GetEntry: не найден элемент"
	#endif

	#ifdef  TEST_DELENTRY_06
		DelEntry(d2, 25);   // THROW06 "DelEntry: не найден элемент"
	#endif
		a[3] = { 2, "Макаед" };
	#ifdef  TEST_UPDENTRY_07
		UpdEntry(d2, 25, a[3]);			// THROW07 "UpdEntry: не найден элемент"
	#endif

	#ifdef  TEST_UPDENTRY_08
		UpdEntry(d2, 1, a[3]);			// THROW08 "UpdEntry: дублирование идентефикатора"
	#endif

	#ifdef TEST_DICTIONARY
		Instance STUDENTS, TEACHERS;
		STUDENTS = Create("Студенты", 10);		// создание словаря студенты размером 10
		TEACHERS = Create("Преподаватели", 8);		// создание словаря преподаватели размером 8

		Entry people1[10] = { {10, "Тараканов"}, {2, "Поздняков"}, {15, "Каребо"}, {4, "Яшный"}, {7, "Савеня"},	// студенты
							 {21, "Ружицкий"}, {3, "Макаров"}, {11, "Пушкарёв"}, {8, "Бенько"}, {33, "Шпаковский"} };
		Entry people2[8] = { {1, "Наркевич"}, {4, "Шиман"}, {9, "Белодед"}, {2, "Андронова"}, {15, "Мисевич"},	// преподаватели
							 {13, "Мущук"}, {3, "Пахолко"}, {10, "Барковский"}};
		
		for (int i = 0; i < 10; i++) {
			AddEntry(STUDENTS, people1[i]);						// добавление элементов в словарь Студенты
		}
		for (int j = 0;j < 8; j++) {					
			AddEntry(TEACHERS, people2[j]);						// добавление элементов в словарь Преподаватели
		}

		Print(STUDENTS);   // вывод словаря Студенты
		Print(TEACHERS);	// вывод словаря Преподаватели

		DelEntry(STUDENTS, 33);
		DelEntry(STUDENTS, 7);   // удаление 33 и 7 из словаря Студенты
		DelEntry(TEACHERS, 9);
		DelEntry(TEACHERS, 15);	// удаление 9 и 15 из словаря Преподаватели

		std::cout << "\n\n";
		Print(STUDENTS);   // вывод словаря Студенты
		Print(TEACHERS);	// вывод словаря Преподаватели

		Entry change = { 100, "Изменённый" };
		UpdEntry(STUDENTS, 8, change);		// замена 8 в словаре Студенты
		UpdEntry(TEACHERS, 2, change);		// замена 2 в словаре Преподаватели

		std::cout << "\n\n";
		Print(STUDENTS);   // вывод словаря Студенты
		Print(TEACHERS);	// вывод словаря Преподаватели

		Entry read1 = GetEntry(STUDENTS, 10);	// получить элемент 10
		Entry read2 = GetEntry(TEACHERS, 1);	// получить элемент 1
		std::cout << "\n\n" << "STUDENTS: " << read1.id << "\t" << read1.name << std::endl;
		std::cout << "TEACHERS: " << read2.id << "\t" << read2.name << std::endl;

		Delete(STUDENTS);	// удаление словаря Студенты
		Delete(TEACHERS);	// удаление словаря Преподаватели

		std::cout << "\n\n";
		Print(STUDENTS);   // вывод словаря Студенты
		Print(TEACHERS);	// вывод словаря Преподаватели
	#endif
	}
	catch(const char* e) {
			std::cout << e << std::endl;
		}
	return 0;
}
	