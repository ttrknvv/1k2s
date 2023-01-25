#include "Varparm.h"

int Varparm::ivarparm(int n, ...) { // ������������ �������� ���� ����������, ������� �� �������(int)
	int composition = 1;
	int* pointer = &n;
	while (n--) {
		composition = composition  * *(++pointer);
	}
	return composition;
}

int Varparm::svarparm(short n, ...) { // ������������ �������� ����������, ������� �� �������(int).
	int max = SHRT_MIN;
	int* pointer = (int*)&n;
	while (n--) {
		if (max < *(++pointer)) { 
			max = *(pointer); 
		}
	}
	return max;
}

double Varparm::fvarparm(float first, ...) { //  ����� �������� ���� ����������, ������� � ������� �� �������������(double)
	double summ = first;
	double* pointer = (double*)(&first+1);
	while (*(pointer) != (double)(FLT_MAX)) {
		summ += *(pointer);
		pointer++;
	}
	return summ;
}

double Varparm::dvarparm(double first, ...) { //  ����� �������� ���� ����������, ������� � ������� �� �������������(double)
	double summ = 0;
	double* pointer = (&first);
	while (*(pointer) != (DBL_MAX)) {
		summ += *(pointer);
		pointer++;
	}
	return summ;
}