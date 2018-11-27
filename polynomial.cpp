/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"
//ADD implementation of the member functions for class Polynomial




Polynomial::Polynomial(int d, double a[])
{
	deg = d;
	v = new double[deg+1];
	for (int i = 0; i <= deg ;i++) 
		v[i]=a[i];

}

Polynomial::Polynomial(const double d)
{
	deg = 0;
	v = new double[1];
	v[0] = d;
}

Polynomial::Polynomial(const Polynomial & P)
{
	deg = P.deg;
	v = new double[deg + 1];
	for (int i = 0; i <= deg; i++) 
		v[i] = P.v[i];
}

Expression * Polynomial::clone() const
{
	return new Polynomial(*this);
}

Polynomial::~Polynomial()
{
	delete[] v;
	deg = NULL;
}

const Polynomial & Polynomial::operator=(const Polynomial & p)
{
	if (this != &p) {
		Polynomial tmp(p);
		std::swap(deg, tmp.deg);
		std::swap(v, tmp.v);
	}
	return *this;
}

Polynomial const Polynomial::operator+(const Polynomial & p) const
{
	Polynomial newP;
	newP.deg = deg > p.deg ? deg : p.deg ;
	newP.v = new double[newP.deg + 1];
	for (int i = 0; i <= newP.deg; i++) {
		newP.v[i] = 0;
		if (i <= deg)
			newP.v[i] += v[i];
		if (i <= p.deg)
			newP.v[i] += p.v[i];
		
	}
	return newP;
}

double & Polynomial::operator[](const int n) const
{
	return v[n];
}

double Polynomial::operator()(double x) const
{
	double ret=v[0];
	for (int i = 1; i <= deg; i++)
		if (!(abs(v[i]) < EPSILON)) 
			ret += v[i] * pow(x,i);
	
	return ret;
}

void Polynomial::display(std::ostream & os) const
{
	os << std::fixed << std::setprecision(2);
	for (int i = 0; i <= deg; i++)
		if (!(abs(v[i]) < EPSILON))
			if(i==0)
				os << v[i];
			else 
				os << " + " << v[i] << "*x^" << i ;

		
}

Polynomial operator+(double n, const Polynomial & p)
{
	Polynomial newP(p);
	newP[0] += n;

	return newP;
}
