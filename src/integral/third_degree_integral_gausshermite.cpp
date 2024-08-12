#include "integral/third_degree_integral_gausshermite.hpp"
#include "visitor/visitor.hpp"

ThirdDegreeIntegralGuassHermite::ThirdDegreeIntegralGuassHermite(double xi, double xf, functionWithOneArgument function) : 
    IntegralGauss(xi, xf, function, vector<double>{-1.224744871, 0, 1.224744871}, vector<double>{0.295408975, 1.181635901, 0.295408975}) 
    {};

/**
 * This method is the accept method for the visitor pattern
 * used to get the result of the calculation of a method
 *
 * 
 * @return void - this method does not return any value, just prints the result.
 */
void ThirdDegreeIntegralGuassHermite::accept(Visitor& visitor) const 
{
    visitor.visit(*this);
};

double ThirdDegreeIntegralGuassHermite::getXk(int rootIndex)
{
    return this->roots[rootIndex];
};


/**
 * Used by the context class to call the execution of some numerical method 
 * This method does not receive any parameter
 * 
 * @return void - This method does not return any value, just sets the result on the result attribute 
 */
void ThirdDegreeIntegralGuassHermite::execute()
{
    double sum = 0;
    for(int i = 0; i < roots.size(); ++i)
    {
        sum += this->functionToIntegrate(this->getXk(i)) * this->weights[i];
    }
    this->result = sum;
};