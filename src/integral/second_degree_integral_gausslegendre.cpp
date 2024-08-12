#include "integral/second_degree_integral_gausslegendre.hpp"
#include "visitor/visitor.hpp"

SecondDegreeIntegralGuassLegendre::SecondDegreeIntegralGuassLegendre(double xi, double xf, functionWithOneArgument function) : 
    IntegralGauss(xi, xf, function, vector<double>{-0.577350269, 0.577350269}, vector<double>{1,1}) 
    {};

/**
 * This method is the accept method for the visitor pattern
 * used to get the result of the calculation of a method
 *
 * 
 * @return void - this method does not return any value, just prints the result.
 */
void SecondDegreeIntegralGuassLegendre::accept(Visitor& visitor) const 
{
    visitor.visit(*this);
};

double SecondDegreeIntegralGuassLegendre::getXk(int rootIndex)
{
    return (this->Xi + this->Xf) / 2 + ((this->Xf - this->Xi) / 2 ) * this->roots[rootIndex];
};


/**
 * Used by the context class to call the execution of some numerical method 
 * This method does not receive any parameter
 * 
 * @return void - This method does not return any value, just sets the result on the result attribute 
 */
void SecondDegreeIntegralGuassLegendre::execute()
{
    double sum = 0;
    for(int i = 0; i < roots.size(); ++i)
    {
        sum += this->functionToIntegrate(this->getXk(i)) * this->weights[i];
    }
    sum *= (this->Xf - this->Xi) / 2;
    this->result = sum;
};