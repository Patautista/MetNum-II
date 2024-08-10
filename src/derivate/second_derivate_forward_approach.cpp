#include "derivate/second_derivate_forward_approach.hpp"
#include "visitor/visitor.hpp"
#include <math.h>
using namespace std;

SecondDerivateForwardApproach::SecondDerivateForwardApproach(double xi, double deltax, functionWithOneArgument function) : Derivate(xi,deltax, function) {};

void SecondDerivateForwardApproach::execute() 
{
    this->result = (1/pow(this->deltaX, 2)) * (this->functionToDerive(this->Xi + 2 * deltaX) - 2 * this->functionToDerive(this->Xi + deltaX) - this->functionToDerive(this->Xi));
}

void SecondDerivateForwardApproach::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}