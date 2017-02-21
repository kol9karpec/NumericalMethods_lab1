#include "TPolinom.h"



TPolinom::TPolinom()
{
	this->n = 0;
	this->coefs = new double[MAX_N];
}

TPolinom::TPolinom(int n, double * coefs)
{
	this->coefs = new double[MAX_N];
	for (int i = 0; i <= n; i++)
		this->coefs[i] = coefs[i];
	this->n = n;
}

TPolinom::TPolinom(const TPolinom & polinom)
{
	this->coefs = new double[MAX_N];
	for (int i = 0; i <= polinom.n; i++)
		this->coefs[i] = polinom.coefs[i];
	this->n = polinom.n;
}

TPolinom TPolinom::derivative(int order)
{
	if (order > this->n) return TPolinom();
	else
	{
		double * newCoefs = new double[this->n + 1];
		for (int i = 0; i <= this->n; i++)
			newCoefs[i] = this->coefs[i];
		int newN = this->n;
		for (int i = 0; i < order; i++)
		{
			for (int j = 0; j < newN; j++)
			{
				newCoefs[j] = (j + 1)*newCoefs[j + 1];
				if (j == newN - 1) newCoefs[j + 1] = 0;
			}
			newN--;
		}
		TPolinom result(newN,newCoefs);
		result.print();
		return result;
	}
}

double TPolinom::res(double x)
{
	double result = 0;
	for (int i = 0; i <= this->n; i++)
		result += this->coefs[i] * pow(x, i);
	return result;
}

char * TPolinom::print()
{
	string result;
	for (int i = this->n; i >= 0; i--)
	{
		char * buff = new char[256];
		result.append(_itoa(this->coefs[i],buff,10));
		if (i > 0)
		{
			result.append("x^");
			result.append(_itoa(i,buff,10));
			result.append(" + ");
		}		
		delete(buff);
	}
	char * res = new char[result.size() + 1];
	strcpy(res,result.data());
	return res;
}

TPolinom TPolinom::divide(TPolinom a, TPolinom b, TPolinom & result)
{

	return TPolinom();
}

double TPolinom::bisection(double a, double b, double e, int & steps, ofstream& out)
{
	steps = 0;
	if (this->res(a) == 0) return a;
	else if (this->res(b) == 0) return b;
	else
	{	
		double c;
		while (abs(b - a) > e)
		{
			c = a + ((b-a) / 2);
			if ((this->res(a))*(this->res(c)) < 0) b = c;
			else a = c;
			steps++;
			out << "Iteration " << steps << ":\t";
			out << setprecision(-(int)(log10(e/10)));
			out << "x: [" << a << " ; " << b << "]\t";
			out << "f(x): [" << this->res(a) << " ; " << this->res(b) << "]" << endl;
		}
		return c;
	}
}

double TPolinom::chords(double a, double b, double e, int & steps, ofstream& out)
{
	steps = 0;
	if (this->res(a) == 0) return a;
	else if (this->res(b) == 0) return b;
	else
	{
		
		while ((abs(b - a) > e ))
		{				
			double x1 = a - (b - a)*(this->res(a)) / (this->res(b) - this->res(a));
			if (this->res(x1)*this->res(a) < 0) a = x1;
			else b = x1;
			steps++;
			out << "Iteration " << steps << ":\t";
			out << setprecision(-(int)(log10(e/10)));
			out << "x: [" << a << " ; " << b << "]\t";
			out << "f(x): [" << this->res(a) << " ; " << this->res(b) << "]" << endl;
		}
		return a;
	}
}

double TPolinom::newtons(double a, double e, int & steps, ofstream& out)
{
	steps = 0;
	double x1 = a - this->res(a) / this->derivative(1).res(a);
	double x0 = a;
	while (abs(x0 - x1) > e) {
		x0 = x1;
		x1 = x1 - this->res(x1) / this->derivative(1).res(x1);
		steps++;
		out << "Iteration " << steps << ":\t";
		out << setprecision(-(int)(log10(e/10)));
		out << "x: "<< x1<<"\t";
		out << "f(x): " << this->res(x1) << endl;
	}
	return x1;
}

TPolinom::~TPolinom()
{
	delete(this->coefs);
	this->coefs = nullptr;
}
