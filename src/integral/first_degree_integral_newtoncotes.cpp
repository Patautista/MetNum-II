#include "integral/first_degree_integral_newtoncotes.hpp"
#include "visitor/visitor.hpp"


FirstDegreeIntegralNewtonCotes::FirstDegreeIntegralNewtonCotes(double xi, double deltax, functionWithOneArgument function, int numberOfPartitions) : Integral(xi, deltax, function, numberOfPartitions){};

FirstDegreeIntegralNewtonCotes::FirstDegreeIntegralNewtonCotes(double xi, double deltax, functionWithOneArgument function, double tolerance) : Integral(xi, deltax, function, tolerance){};

void FirstDegreeIntegralNewtonCotes::accept(Visitor& visitor) const {
    visitor.visit(*this);
};



double FirstDegreeIntegralNewtonCotes::calculateIntegralByPartitions()
{
    double newDelta_x = this->deltaX / this->numberOfPartitions;
    double h = newDelta_x;
    auto NewtonCotes_firstDegree_formula = [this, h, newDelta_x](int partition)
    {
        double xi = (this->Xi + partition * newDelta_x);
        return (h / 2) * (this->functionToIntegrate(xi) + this->functionToIntegrate(xi + h));
    };
    return this->calculate_integral_by_numberOfPartitions(NewtonCotes_firstDegree_formula, numberOfPartitions);
};

double FirstDegreeIntegralNewtonCotes::calculateIntegralByError()
{
    double newDelta_x = 0;
    double h = newDelta_x;
    auto NewtonCotes_firstDegree_formula = [this, &h, &newDelta_x](int partition)
    {
        h = newDelta_x;
        double xi = (this->Xi + partition * newDelta_x);
        return (h / 2) * (this->functionToIntegrate(xi) + this->functionToIntegrate(xi + h));
    };
    return this->calculate_integral_by_error(NewtonCotes_firstDegree_formula, tolerance, this->deltaX, newDelta_x);
};

void FirstDegreeIntegralNewtonCotes::execute()
{
    if(this->numberOfPartitions != -1) {
        this->result = this->calculateIntegralByPartitions();
    }else {
        this->result = this->calculateIntegralByError();
    }
};
