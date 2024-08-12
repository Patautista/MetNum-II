#include "integral/integral.hpp"
#include "visitor/visitor.hpp"
#include <math.h>
#include <limits>
using namespace std;

Integral::Integral(double xi, double deltax, functionWithOneArgument function, int numberOfPartitions)
{
    this->Xi = xi;
    this->deltaX = deltax;
    this->functionToIntegrate = function;
    this->numberOfPartitions = numberOfPartitions;
    this->tolerance = -1;
};

Integral::Integral(double xi, double deltax, functionWithOneArgument function, double tolerance)
{
    this->Xi = xi;
    this->deltaX = deltax;
    this->functionToIntegrate = function;
    this->tolerance = tolerance;
    this->numberOfPartitions = -1;
};


double Integral::calculate_integral_by_numberOfPartitions(std::function<double(int)>  integralFormula, int numberOfPartitions)
{
    double result = 0;
    for (int partition = 0; partition < this->numberOfPartitions; ++partition)
    {
        result += integralFormula(partition);
    }
    return result;
};


double Integral::calculate_integral_by_error(std::function<double(int)> integralFormula, double tolerance, double delta_x, double &newDelta_x)
{
    double numberOfPartitions = 1;
    double result, pastResult = 0;
    double error = numeric_limits<double>::max();
    while (error >= tolerance)
    {
        newDelta_x = delta_x / numberOfPartitions;
        result = this->calculate_integral_by_numberOfPartitions(integralFormula, numberOfPartitions);
        error = fabs((result - pastResult) / result);
        pastResult = result;
        numberOfPartitions *= 2;
    }
    return result;
};

