#pragma once
#define ERROR_THROW(id) Error::geterror(id); // throw ERROR_THROW(id)
#define ERROR_THROW_IN(id, l, c) Error::gererrorin(id, l, c); // throw ERROR_THROW(id, ������, �������)
#define ERROR_ENTRY(id, m) {id, m, {-1, -1}} // ������� ������� ������
#define ERROR_MAXSIZE_MESSAGE 200 // ������������ ����� ��������� �� ������
#define ERROR_ENTRY_NODEF(id) ERROR_ENTRY(-id, "�������������� ������")  // 1 �������������� ��������� ������� ������ 
// ERROR_ENTRY_NODEF10(id) - 10 �������������� ��������� ������� ������
#define ERROR_ENTRY_NODEF10(id) ERROR_ENTRY_NODEF(id + 0), ERROR_ENTRY_NODEF(id + 10), ERROR_ENTRY_NODEF(id + 20), \
								ERROR_ENTRY_NODEF(id + 30), ERROR_ENTRY_NODEF(id + 40), ERROR_ENTRY_NODEF(id + 50), \
								ERROR_ENTRY_NODEF(id + 60), ERROR_ENTRY_NODEF(id + 70), ERROR_ENTRY_NODEF(id + 80), \
								ERROR_ENTRY_NODEF(id + 90)
// ERROR_ENTRY_NODEF100(id) - 100 �������������� ��������� ������� ������
#define ERROR_ENTRY_NODEF100(id) ERROR_ENTRY_NODEF10(id + 0), ERROR_ENTRY_NODEF10(id + 10), ERROR_ENTRY_NODEF10(id + 20), \
								ERROR_ENTRY_NODEF10(id + 30), ERROR_ENTRY_NODEF10(id + 40), ERROR_ENTRY_NODEF10(id + 50), \
								ERROR_ENTRY_NODEF10(id + 60), ERROR_ENTRY_NODEF10(id + 70), ERROR_ENTRY_NODEF10(id + 80), \
								ERROR_ENTRY_NODEF10(id + 90)
#define ERROR_MAX_ENTRY 1000 // ���������� ��������� � ������� ������

namespace Error {
	struct ERROR { // ��� ���������� ��� throw ERROR_THROW | ERROR_THROW_IN � catch(ERROR)
		int id;										// ��� ������
		char message[ERROR_MAXSIZE_MESSAGE];		// ��������� �� ������
		struct IN {									// ���������� ��� ������ ��� ��������� ������� ������
			short line;								// ����� ������ (0, 1, 2, ...)
			short col;								// ����� ������� � ������ (0, 1, 2, ...)
		} inext;
	};
	ERROR geterror(int id);							// ������������ ERROR ��� ERROR_THROW
	ERROR gererrorin(int id, int line, int col);	// ������������ ERROR ��� ERROR_THROW_IN
}