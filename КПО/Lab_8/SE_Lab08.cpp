#include "Call.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int a = 2, b = 1, c = 6, e = 0;
	cout << "int _cdecl cdevl: " << Call::cdevl(a, b, c) << endl; // ��������� ���������� ����� ����, ������� ���������� ���������� ������ ������, ���� ����������� ���������� ���, ������� �������� ����� ������� EAX.
	cout << "int _stdcall cstd: " << Call::cstd(a, b, c) << endl; // ��������� ���������� ����� ����, ������� ���������� ������ ������, ���� ����������� ���������� ���, ������� ����� ������� EAX.
	cout << "int _fastcall cfst: " << Call::cfst(a, b, c, e); // ��������� ���������� ����� �������� (������ 2 � ����� ��������, ��������� ������ ������ � ����), ���� ����������� ���������� ���, ������� ����� ������� EAX.
	return 0;
}