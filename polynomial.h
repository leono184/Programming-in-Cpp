/*************************
* Class Polynomial       *
* TNG033: Lab 2          *
**************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>


#include "expression.h"


class Polynomial : public Expression
{
public:
	Polynomial() {};
	Polynomial(int d, double a[]);
	Polynomial(const double d);
	Polynomial(const Polynomial& P);
	Expression *clone() const;

	~Polynomial();

	const Polynomial& operator=(const Polynomial& p);
	Polynomial const operator+(const Polynomial& p) const;
	friend Polynomial operator+(double n, const Polynomial& p);

	double& operator[](const int n) const;
	double operator()(double x) const;


protected:
	double *v;
	int deg;
	void display(std::ostream& os) const;
};


#endif
