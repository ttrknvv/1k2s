#include "Varparm.h"

int Varparm::ivarparm(int n, ...) { // произведение значений всех параметров, начиная со второго(int)
	int composition = 1;
	int* pointer = &n;
	while (n--) {
		composition = composition  * *(++pointer);
	}
	return composition;
}

int Varparm::svarparm(short n, ...) { // максимальное значение параметров, начиная со второго(int).
	int max = SHRT_MIN;
	int* pointer = (int*)&n;
	while (n--) {
		if (max < *(++pointer)) { 
			max = *(pointer); 
		}
	}
	return max;
}

double Varparm::fvarparm(float first, ...) { //  сумма значений всех параметров, начиная с первого по предпоследний(double)
	double summ = first;
	double* pointer = (double*)(&first+1);
	while (*(pointer) != (double)(FLT_MAX)) {
		summ += *(pointer);
		pointer++;
	}
	return summ;
}

double Varparm::dvarparm(double first, ...) { //  сумма значений всех параметров, начиная с первого по предпоследний(double)
	double summ = 0;
	double* pointer = (&first);
	while (*(pointer) != (DBL_MAX)) {
		summ += *(pointer);
		pointer++;
	}
	return summ;
}