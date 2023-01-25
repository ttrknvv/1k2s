#include <iostream>
#include <iomanip>

int summ(int a, int b);

using namespace std;

int main() {
	int X, Y, Z;
	float S;
	/////////////////////////////////////////////////////////////
	bool variableOfTrue = true; // 0x01
	bool variableOfFalse = false; // 0x00
	/////////////////////////////////////////////////////////////
	char surname_eng = 'A'; // 65
	wchar_t surname_engw = L'A'; // 00 65
	char surname_rus = 'Т'; // 
	wchar_t surname_rusw = L'Т'; // 
	/////////////////////////////////////////////////////////////
	X = 9 + 13;
	Y = 10 + 13;
	Z = 11 + 13;
	S = 1.0 + float(13);
	/////////////////////////////////////////////////////////////
	short variableOfXPulse = X; // 0x16
	short variableOfXMinus = -X; // 0xFFEA
	short biggest_sh = 0x7FFF; //  32767
	short smallest_sh = 0x8000; //  -32768
	unsigned short biggest_unssh = 0xFFFF; // 65535
	unsigned short smallest_unssh = 0x0; // 0
	/////////////////////////////////////////////////////////////
	int variableOfYPulse = Y; // 0x17
	int variableOfYMinus = -Y; // 0xFFFFFFE9
	int ibiggest = 0x7FFFFFFF; // 2 147 483 647
	int ismallest = 0x80000000; // -2 147 483 648
	unsigned int iunbiggest = 0xFFFFFFFF; // 4 294 967 295
	unsigned int iunsmallest = 0x0; // 0
	/////////////////////////////////////////////////////////////
	long variableOfZPulse = Z; // 0X18
	long variableOfZMinus = -Z; // FFFFFFE8
	long lbiggest = 0x7FFFFFFF; // 2 147 483 647
	long lsmallest = 0x80000000; // -2 147 483 648
	unsigned long biggest_unsl = 0xFFFFFFFF; // 4 294 967 295
	unsigned long smallest_unsl = 0x0; // 0
	/////////////////////////////////////////////////////////////
	float variableOfSPulse = S; // 4160
	float variableOfSMinus = -S; // С160
	/////////////////////////////////////////////////////////////
	float beskonechn = S / 0;
	float minbeskonechn = -S / 0;
	float neopr = sqrt(-S);
	/////////////////////////////////////////////////////////////
	double variiabledoubl = 23.756;
	char* pch = &surname_eng;
	wchar_t* pwch = &surname_engw;
	short* psh = &variableOfXPulse;
	int* pin = &variableOfYPulse;
	float* pf = &variableOfSPulse;
	double* pd = &variiabledoubl;
	/////////////////////////////////////////////////////////////
	pin += 3;
	pf += 3;
	pch += 3;
	pwch += 3;
	pd += 3;
	/////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////
	int a = 10;
	int b = 20;
	int (*foo)(int, int);
	foo = &summ;
	cout << foo(a, b) << endl;
	return 0;
}
int summ(int a, int b) {
	return a + b;
}