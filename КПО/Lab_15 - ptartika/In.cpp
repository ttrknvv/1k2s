#include "stdafx.h"
#include "In.h"
#include "Error.h"

using namespace std;

namespace In
{
	IN getin(wchar_t infile[])// описываем функцию
	{
		IN in;//создаём переменную структуры
		in.size = 0; in.lines = 0; in.ignor = 0;//Везде отсчёт от 0
		int col = 0;

		unsigned char* text = new unsigned char[IN_MAX_LEN_TEXT];

		ifstream fin(infile);//открываем файл с модом на чтение
		if (fin.fail()) throw ERROR_THROW(110);//если файл не открылся

		while (in.size < IN_MAX_LEN_TEXT)//пока не достигнем константы(не должен быть больше 1 мб)
		{
			char c; fin.get(c);//считываем символ из файла
			unsigned char x = c;

			if (fin.eof())//если конец файла
			{
				text[in.size] = '\0';//в конец добавляем \0
				in.lines;
				break;
			}
			if (in.code[x] == in.T)//проверяем есть ли символ в таблице
			{
				text[in.size] = x;//добавляем символ в наш текст
				in.size++;//размер текста тогда увеличивается
				col++;//и счётчик увеличивается
			}
			else if (in.code[x] == in.I)// проверяем на замену
			{
				in.ignor++;
			}
			else if (in.code[x] == in.F)// если в иаблице сиволу соответствует IN:F,то генерируем ошибку
			{
				throw ERROR_THROW_IN(111, in.lines, col);//генерация ошибки
			}
			else
			{
				text[in.size] = in.code[x];
				in.size++;
				col++;
			}
			if (x == IN_CODE_ENDL)//если мы встретили \n,то добавляем строчку
			{
				in.lines++;
				col = 0;//позиция в строчке
			}
		}
		in.text = text;
		return in;
	}
}