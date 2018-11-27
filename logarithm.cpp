/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"

//ADD implementation of the member functions for class Logarithm

Logarithm::Logarithm()
{
	c1 = 0;
	c2 = 1;
	b = 2;
	double tmp[2] = {0,1};
	E =  new Polynomial(1,tmp);
}

Logarithm::Logarithm(const Logarithm & L)
{
	c1 = L.c1;
	c2 = L.c2;
	b = L.b;
	E = L.E->clone();
}

Expression *Logarithm::clone() const
{
	return new Logarithm(*this);
}

Logarithm::Logarithm(const Expression & expression, double constant1, double constant2, int log)
{
	c1 = constant1;
	c2 = constant2;
	b = log;
	E = expression.clone();	
}

double Logarithm::operator()(double x) const
{
	double ret = 0;
	ret = c1 + c2*(log(E->operator()(x))/log(b));
	return ret;
}

Logarithm::~Logarithm()
{
	c1 = NULL;
	c2 = NULL;
	b = NULL;
	delete E;
}

const Logarithm & Logarithm::operator=(const Logarithm & inL)
{
	if (this != &inL) {
		Logarithm tmp(inL);
		std::swap(c1,tmp.c1);
		std::swap(c2, tmp.c2);
		std::swap(b, tmp.b);
		std::swap(E, tmp.E);
	}
	return *this;
}

void Logarithm::display(std::ostream & os) const
{
	os << std::fixed << std::setprecision(2);
	os << c1 << " + " << c2 << "*log_" << b << "(" << *E << ")";
	
}

