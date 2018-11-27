/*************************
* Class Logarithm        *
* TNG033: Lab 2          *
**************************/


#ifndef LOGARITHM_H
#define LOGARITHM_H

#include "expression.h"


class Logarithm : public Expression
{

    //ADD CODE
public:
	Logarithm();
	Logarithm(const Logarithm &L);
	~Logarithm();

	Expression *clone() const;	
	Logarithm(const Expression &E, double c1, double c2, int b);

	double operator()(double x) const;

	const Logarithm& operator=(const Logarithm &inL);
	
protected:
	Expression *E;
	int b;
	double c2;
	double c1;
	void display(std::ostream& os) const;
};

#endif
