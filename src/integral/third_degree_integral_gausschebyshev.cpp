#include "integral/third_degree_integral_gausschebyshev.hpp"
#include "visitor/visitor.hpp"

ThirdDegreeIntegralGuassChebyShev::ThirdDegreeIntegralGuassChebyShev(double xi, double xf, functionWithOneArgument function) : 
    IntegralGauss(xi, xf, function, vector<double>{-0.866025404, 0, 0.866025404}, vector<double>{1.047197551, 1.047197551, 1.047197551}) 
    {};

/**
 * This method is the accept method for the visitor pattern
 * used to get the result of the calculation of a method
 *
 * 
 * @return void - this method does not return any value, just prints the result.
 */
void ThirdDegreeIntegralGuassChebyShev::accept(Visitor& visitor) const 
{
    visitor.visit(*this);
};

double ThirdDegreeIntegralGuassChebyShev::getXk(int rootIndex)
{
    return this->roots[rootIndex];
};


/**
 * Used by the context class to call the execution of some numerical method 
 * This method does not receive any parameter
 * 
 * @return void - This method does not return any value, just sets the result on the result attribute 
 */
void ThirdDegreeIntegralGuassChebyShev::execute()
{
    double sum = 0;
    for(int i = 0; i < roots.size(); ++i)
    {
        sum += this->functionToIntegrate(this->getXk(i)) * this->weights[i];
    }
    this->result = sum;
};