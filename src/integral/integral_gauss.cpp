#include "integral/integral_gauss.hpp"
#include "visitor/visitor.hpp"

IntegralGauss::IntegralGauss(double xi, double xf, functionWithOneArgument function, vector<double> root, vector<double> weight)
    : Xi{xi}, Xf{xf}, functionToIntegrate{function}, roots{root}, weights{weight} 
    {};


void IntegralGauss::accept(Visitor& visitor) const 
{
    visitor.visit(*this);
};