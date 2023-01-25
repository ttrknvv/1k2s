#include "stdafx.h"
#include <iostream>
#include <locale>
#include <cwchar>
#include <Windows.h>

#include "Error.h"	// обрботка ошибок
#include "In.h"		// обработка параметров
#include "Log.h"	// работа с протоколом
#include "Parm.h"	// ввод исходного файла

int _tmain(int argc, _TCHAR* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "------- тест Error::geterror ------\n\n";
	try { throw ERROR_THROW(100); }
	catch (Error::ERROR e) {
		std::cout << "Ошибка " << e.id << ": " << e.message << ", строка " << e.inext.line << ", позиция "
			<< e.inext.col << std::endl << std::endl;
	}
	system("pause");
	return 0;

}