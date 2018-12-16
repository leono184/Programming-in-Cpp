/*************************
* Class Expression       *
* TNG033: Lab 2          *
**************************/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <math.h>  
#include <iomanip>  
const double EPSILON = 1.0e-5;



class Expression {
public:

	Expression() {};

	virtual ~Expression() {};
	virtual Expression* clone() const = 0;

	virtual double operator()(double v) const = 0;
	bool isRoot(double v) const;
	friend std::ostream& operator<<(std::ostream& os, const Expression& E);
	
protected:
	virtual void display(std::ostream& os) const {  };
	
};


#endif
