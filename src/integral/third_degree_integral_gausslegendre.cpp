#include "integral/third_degree_integral_gausslegendre.hpp"
#include "visitor/visitor.hpp"

ThirdDegreeIntegralGuassLegendre::ThirdDegreeIntegralGuassLegendre(double xi, double xf, functionWithOneArgument function) : 
    IntegralGauss(xi, xf, function, vector<double>{-0.774596669, 0, 0.774596669}, vector<double>{5.0/9.0, 8.0/9.0, 5.0/9.0}) 
    {};

/**
 * This method is the accept method for the visitor pattern
 * used to get the result of the calculation of a method
 *
 * 
 * @return void - this method does not return any value, just prints the result.
 */
void ThirdDegreeIntegralGuassLegendre::accept(Visitor& visitor) const 
{
    visitor.visit(*this);
};

double ThirdDegreeIntegralGuassLegendre::getXk(int rootIndex)
{
    return (this->Xi + this->Xf) / 2 + ((this->Xf - this->Xi) / 2 ) * this->roots[rootIndex];
};


/**
 * Used by the context class to call the execution of some numerical method 
 * This method does not receive any parameter
 * 
 * @return void - This method does not return any value, just sets the result on the result attribute 
 */
void ThirdDegreeIntegralGuassLegendre::execute()
{
    double sum = 0;
    for(int i = 0; i < roots.size(); ++i)
    {
        sum += this->functionToIntegrate(this->getXk(i)) * this->weights[i];
    }
    sum *= (this->Xf - this->Xi) / 2;
    this->result = sum;
};