#include "integral/first_degree_integral_open_newtoncotes.hpp"
#include "visitor/visitor.hpp"

FirstDegreeIntegralOpenNewtonCotes::FirstDegreeIntegralOpenNewtonCotes(double xi, double deltax, functionWithOneArgument function, int numberOfPartitions) : Integral(xi, deltax, function, numberOfPartitions){};

FirstDegreeIntegralOpenNewtonCotes::FirstDegreeIntegralOpenNewtonCotes(double xi, double deltax, functionWithOneArgument function, double tolerance) : Integral(xi, deltax, function, tolerance){};

void FirstDegreeIntegralOpenNewtonCotes::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

double FirstDegreeIntegralOpenNewtonCotes::calculateIntegralByPartitions()
{
    double newDelta_x = this->deltaX / this->numberOfPartitions;
    double h = newDelta_x / 3;
    auto NewtonCotes_firstDegree_formula = [this, h, newDelta_x](int partition)
    {
        double xi = (this->Xi + partition * newDelta_x);
        return (3 * h / 2) * (this->functionToIntegrate(xi + h) + this->functionToIntegrate(xi + 2 * h));
    };
    return this->calculate_integral_by_numberOfPartitions(NewtonCotes_firstDegree_formula, numberOfPartitions);
};

double FirstDegreeIntegralOpenNewtonCotes::calculateIntegralByError()
{
    double newDelta_x = 0;
    double h = newDelta_x / 3;
    auto NewtonCotes_firstDegree_formula = [this, &h, &newDelta_x](int partition)
    {
        h = newDelta_x / 3;
        double xi = (this->Xi + partition * newDelta_x);
        return (3 * h / 2) * (this->functionToIntegrate(xi + h) + this->functionToIntegrate(xi + 2 * h));
    };
    return this->calculate_integral_by_error(NewtonCotes_firstDegree_formula, tolerance, this->deltaX, newDelta_x);
};

void FirstDegreeIntegralOpenNewtonCotes::execute()
{
    if(this->numberOfPartitions != -1) {
        this->result = this->calculateIntegralByPartitions();
    }else {
        this->result = this->calculateIntegralByError();
    }
};