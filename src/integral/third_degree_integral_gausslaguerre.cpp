#include "integral/third_degree_integral_gausslaguerre.hpp"
#include "visitor/visitor.hpp"

ThirdDegreeIntegralGuassLaguerre::ThirdDegreeIntegralGuassLaguerre(double xi, double xf, functionWithOneArgument function) : 
    IntegralGauss(xi, xf, function, vector<double>{0.4157745568, 2.2942803603, 6.2899450829}, vector<double>{0.7110930099, 0.7110930099, 0.0103892565}) 
    {};

/**
 * This method is the accept method for the visitor pattern
 * used to get the result of the calculation of a method
 *
 * 
 * @return void - this method does not return any value, just prints the result.
 */
void ThirdDegreeIntegralGuassLaguerre::accept(Visitor& visitor) const 
{
    visitor.visit(*this);
};

double ThirdDegreeIntegralGuassLaguerre::getXk(int rootIndex)
{
    return this->roots[rootIndex];
};


/**
 * Used by the context class to call the execution of some numerical method 
 * This method does not receive any parameter
 * 
 * @return void - This method does not return any value, just sets the result on the result attribute 
 */
void ThirdDegreeIntegralGuassLaguerre::execute()
{
    double sum = 0;
    for(int i = 0; i < roots.size(); ++i)
    {
        sum += this->functionToIntegrate(this->getXk(i)) * this->weights[i];
    }
    this->result = sum;
};