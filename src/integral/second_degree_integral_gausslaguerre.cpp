#include "integral/second_degree_integral_gausslaguerre.hpp"
#include "visitor/visitor.hpp"

SecondDegreeIntegralGuassLaguerre::SecondDegreeIntegralGuassLaguerre(double xi, double xf, functionWithOneArgument function) : 
    IntegralGauss(xi, xf, function, vector<double>{0.585786438, 3.414213562}, vector<double>{0.853553391,0.146446609}) 
    {};

/**
 * This method is the accept method for the visitor pattern
 * used to get the result of the calculation of a method
 *
 * 
 * @return void - this method does not return any value, just prints the result.
 */
void SecondDegreeIntegralGuassLaguerre::accept(Visitor& visitor) const 
{
    visitor.visit(*this);
};

double SecondDegreeIntegralGuassLaguerre::getXk(int rootIndex)
{
    return this->roots[rootIndex];
};


/**
 * Used by the context class to call the execution of some numerical method 
 * This method does not receive any parameter
 * 
 * @return void - This method does not return any value, just sets the result on the result attribute 
 */
void SecondDegreeIntegralGuassLaguerre::execute()
{
    double sum = 0;
    for(int i = 0; i < roots.size(); ++i)
    {
        sum += this->functionToIntegrate(this->getXk(i)) * this->weights[i];
    }
    this->result = sum;
};