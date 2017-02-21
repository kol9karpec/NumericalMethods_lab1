#include <iostream>
#include <fstream>
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
	char * filename = new char[10];

	if (argc > 1) strcpy(filename,argv[1]);
	else strcpy(filename, "input.txt");

	ifstream in(filename);
	ofstream out("out.txt");

	int order;
	in >> order;

	double * coefs = new double[order+1];

	for (int i = order; i >= 0; i--)
		in >> coefs[i];

	int nRoots;
	in >> nRoots;

	double ** intervals = new double*[nRoots];
	for (int i = 0; i < nRoots; i++) {
		intervals[i] = new double[2];
		in >> intervals[i][0] >> intervals[i][1];
	}

	double eps;
	in >> eps;
	eps /= 10;

	TPolinom polinom(order,coefs);
	cout << polinom.print() <<" = 0"<< endl;

	for (int i = 0; i < nRoots; i++)
	{
		int steps;
		cout << endl;
		out << endl;
		cout << "Interval: " << setprecision(3);
		out << "Interval: " << setprecision(3);
		cout << "[" << intervals[i][0] << ";" << intervals[i][1] << "]" << endl;
		out << "[" << intervals[i][0] << ";" << intervals[i][1] << "]" << endl;
		cout << "Bisection: " << setprecision(-(int)log10(eps));
		out << "Bisection: " << setprecision(-(int)log10(eps)) << endl;
		double res = polinom.bisection(intervals[i][0], intervals[i][1], eps, steps,out);
		cout << "Result: " << res <<"\t";
		out << "Result: " << res << "\t";
		cout << " Interations: " << steps << endl;
		out << " Interations: " << steps << endl;

		cout << "Chords: " << setprecision(-(int)log10(eps));
		out << "Chords: " << setprecision(-(int)log10(eps)) << endl;
		res = polinom.chords(intervals[i][0], intervals[i][1], eps, steps, out);
		cout << "Result: " << res << "\t";
		out << "Result: " << res << "\t";
		cout << " Interations: " << steps << endl;
		out << " Interations: " << steps << endl;

		cout << "Newtons: " << setprecision(-(int)log10(eps));
		out << "Newtons: " << setprecision(-(int)log10(eps)) << endl;
		res = polinom.newtons(intervals[i][1], eps, steps, out);
		cout << "Result: " << res << "\t";
		out << "Result: " << res << "\t";
		cout << " Interations: " << steps << endl;
		out << " Interations: " << steps << endl;
		cout << "-----------------------------------" << endl;
		out << "-----------------------------------" << endl;
		cout << endl;
		out << endl;		
	}


	/*double coefs[] = { -12,0,7,0,-3,2 };
	double coefs2[] = {0,14,0,-12,10};
	double coefs3[] = { 12,-42/50,-21/5,36/50 };
	double coefs4[] = { 6950/9,1775/18,-5075/18};
	double coefs5[] = { 0.25,-1.19 };
	
	TPolinom my0(5, coefs);
	TPolinom my1(4, coefs2);
	TPolinom my2(3, coefs3);
	TPolinom my3(2, coefs4);
	TPolinom my4(1, coefs5);
	
	double a = -3, b = 7;
	double interval = 0.5;
	for (double i = a; i <= b; i+= interval) {
		cout << setprecision(2);
		cout << i << "  ";
	}
	cout << endl;

	for (double i = a; i <= b; i += interval) {
		cout << (my0.res(i) >= 0 ? "+" : "-") << "    ";
	}
	cout << endl;
	for (double i = a; i <= b; i += interval) {
		cout << (my1.res(i) >= 0 ? "+" : "-") << "    ";
	}
	cout << endl;
	for (double i = a; i <= b; i += interval) {
		cout << (my2.res(i) >= 0 ? "+" : "-") << "    ";
	}
	cout << endl;
	for (double i = a; i <= b; i += interval) {
		cout << (my3.res(i) >= 0 ? "+" : "-") << "    ";
	}
	cout << endl;
	for (double i = a; i <= b; i += interval) {
		cout << (my4.res(i) >= 0 ? "+" : "-") << "    ";
	}
	cout << endl;*/
	return 0;
}