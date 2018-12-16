/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"


//ADD implementation of the member functions for class Expression

std::ostream & operator<<(std::ostream & os, const Expression & E)
{
	E.display(os);
	return os;
}

bool Expression::isRoot(double v) const
{
	return (fabs(operator()(v)) < EPSILON);
}
