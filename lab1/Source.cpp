#include <iostream>
#include <cmath>
#include <iomanip>
#include "TPolinom.h"

using namespace std;

double polinom(double x) {
	int result = 0;
	result += 2 * pow(x, 5);
	result += (-3) * pow(x, 4);
	result += 0 * pow(x, 3);
	result += 7 * pow(x, 2);
	result += 0 * pow(x, 1);
	result += (-12);
	return result;
}

int main(unsigned int argc, const char * argv[]) {
	double a, b;
	cin >> a >> b;

	double coefs[] = { -12,0,7,0,-3,2 };
	TPolinom my(5, coefs);
	

	for (double i = a; i <= b; i+=0.1) {
		cout << setprecision(4);
		cout << i << "\t" << (my.res(i) >= 0 ? "+" : "-") << endl;
	}

	cout << my.print() << endl;
	cout << my.derivative(1).print() << endl;





	return 0;
}