#include "derivate/second_derivate_central_approach.hpp"
#include "visitor/visitor.hpp"
#include "derivate/first_derivate_central_approach.hpp"


SecondDerivateCentralApproach::SecondDerivateCentralApproach(double xi, double deltax, functionWithOneArgument function) : Derivate(xi,deltax, function) {};

void SecondDerivateCentralApproach::execute() 
{
    //(Central_first_derivate_e1(function, Xi + delta_x, delta_x) - Central_first_derivate_e1(function, Xi - delta_x, delta_x));
    FirstDerivateCentralApproach derivate_pointXi_p_Delta = FirstDerivateCentralApproach(this->Xi + this->deltaX, this->deltaX, this->functionToDerive);
    FirstDerivateCentralApproach derivate_pointXi_m_Delta = FirstDerivateCentralApproach(this->Xi - this->deltaX, this->deltaX, this->functionToDerive);
    derivate_pointXi_p_Delta.execute();
    derivate_pointXi_m_Delta.execute();
    this->result = derivate_pointXi_p_Delta.result - derivate_pointXi_m_Delta.result;
}

void SecondDerivateCentralApproach::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}