#include "Varparm.h"

using namespace std;

void main() {
	cout << "ivarparm: " << Varparm::ivarparm(-4, 1, 2, 3, 4) << "\n";
	cout << "svarparm: " << Varparm::svarparm(4, 1, 2, 3, 4) << "\n";

	cout << "fvarparm: " << Varparm::fvarparm(4.0, 1.0, 2.0, 3.0, 4.0, FLT_MAX) << "\n";
	cout << "dvarparm: " << Varparm::dvarparm(4.0, 1.0, 2.0, 3.0, 4.0, DBL_MAX) << "\n";

}