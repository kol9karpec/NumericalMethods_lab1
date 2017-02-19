#pragma once

#include <iostream>
#include <cmath>
#include <cstring>

#define MAX_N 10

using namespace std;

class TPolinom
{
private:
	int n;
	double * coefs;
public:
	TPolinom();
	TPolinom(int n,double * coefs);
	TPolinom(const TPolinom &);

	int getN() { return this->n; }
	double * getCoefs() { return this->coefs; }

	TPolinom derivative(int order);
	double res(double x);
	char * print();

	static TPolinom divide(TPolinom a, TPolinom b, 
							TPolinom& result);

	double bisection(double a, double b, double e, int& steps);
	double chords(double a, double b, double e, int& steps);
	double newtons(double a, double e, int& steps);


	


	~TPolinom();
};

