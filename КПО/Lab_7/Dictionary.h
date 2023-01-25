#pragma once

#include <iostream>
#include <windows.h>
#include <cstring>
#include <iomanip>
#include <string>

#define DICTNAMEMAXSIZE 20		// максимальный размер имени словаря
#define DICTMAXSIZE 100		   //  максимальная емкость словаря
#define ENTRYNAMEMAXSIZE 30   //   максимальная длина имени в словаре
#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышен размер максимальной емкости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентефикатора"

namespace Dictionary {
	struct Entry { // элемент словаря
		int id;  // уникальный идентификатор
		char name[ENTRYNAMEMAXSIZE] = {};  // символьная информация
	};
	struct Instance {  // экземпляр словаря
		char name[DICTNAMEMAXSIZE] = {};  // наименование словаря
		int maxsize;  // максимальная емкость словаря
		int size = 0;  // текущий размер словаря < DICTNAMEMAXSIZE
		Entry* dictionary;  // массив элементов словаря
	};
	Instance Create(const char dictname[DICTNAMEMAXSIZE], int size); // создать словарь
	void AddEntry(Instance& inst, Entry& ed);  // добавить элемент словаря
	void DelEntry(Instance& inst, int id);  // удалить элемент словаря
	void UpdEntry(Instance& inst, int id, Entry new_ed);  // изменить элемент словаря 
	Entry GetEntry(Instance inst, int id);  // получить элемент словаря
	void Print(Instance d);  // печать словаря
	void Delete(Instance& d);  // удалить словарь
}



