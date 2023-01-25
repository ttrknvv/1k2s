#pragma once

//#define TEST_DICTIONARY			// Проект - Свойства проекта - С/С++ - Препроцессор - Определения препроцессора
//#define TEST_CREATE_01
//#define TEST_CREATE_02
//#define TEST_ADDENTRY_03
//#define TEST_ADDENTRY_04
//#define TEST_GETENTRY_05
//#define TEST_DELENTRY_06
//#define TEST_UPDENTRY_07
//#define TEST_UPDENTRY_08 

#if ((defined(TEST_DICTIONARY) + defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08)) > 1)
#error Превышенно количество тестирующих макросов!	
#endif

