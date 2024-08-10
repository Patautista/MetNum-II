#include "derivate/third_derivate_newton_approach.hpp"
#include "visitor/visitor.hpp"
#include <math.h>
using namespace std;

ThirdDerivateNewtonApproach::ThirdDerivateNewtonApproach(double xi, double deltax, functionWithOneArgument function) : Derivate(xi,deltax, function) {};


void ThirdDerivateNewtonApproach::execute() 
{
    this->result = (1/pow(this->deltaX, 3)) * (-2.5*this->functionToDerive(this->Xi) + 9*this->functionToDerive(this->Xi + this->deltaX) - 12*this->functionToDerive(this->Xi + 2*this->deltaX) + 7*this->functionToDerive(this->Xi + 3*this->deltaX) - 1.5*this->functionToDerive(this->Xi + 4*this->deltaX));
}

void ThirdDerivateNewtonApproach::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}