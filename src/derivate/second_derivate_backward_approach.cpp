#include "derivate/second_derivate_backward_approach.hpp"
#include "visitor/visitor.hpp"
#include <math.h>
using namespace std;

SecondDerivateBackwardApproach::SecondDerivateBackwardApproach(double xi, double deltax, functionWithOneArgument function) : Derivate(xi,deltax, function) {};

void SecondDerivateBackwardApproach::execute() 
{
    this->result = (1/pow(this->deltaX, 2)) * (this->functionToDerive(this->Xi) - 2*this->functionToDerive(this->Xi - this->deltaX) - this->functionToDerive(this->Xi - 2*this->deltaX));
}

void SecondDerivateBackwardApproach::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}