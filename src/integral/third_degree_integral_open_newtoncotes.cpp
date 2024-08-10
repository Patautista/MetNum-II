#include "integral/third_degree_integral_open_newtoncotes.hpp"
#include "visitor/visitor.hpp"

ThirdDegreeIntegralOpenNewtonCotes::ThirdDegreeIntegralOpenNewtonCotes(double xi, double deltax, functionWithOneArgument function, int numberOfPartitions) : Integral(xi, deltax, function, numberOfPartitions){};

ThirdDegreeIntegralOpenNewtonCotes::ThirdDegreeIntegralOpenNewtonCotes(double xi, double deltax, functionWithOneArgument function, double tolerance) : Integral(xi, deltax, function, tolerance){};

void ThirdDegreeIntegralOpenNewtonCotes::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

double ThirdDegreeIntegralOpenNewtonCotes::calculateIntegralByPartitions()
{
    double newDelta_x = this->deltaX / this->numberOfPartitions;
    double h = newDelta_x / 5;
    auto NewtonCotes_third_degree_open_formula = [this, h, newDelta_x](int partition)
    {
        double xi = (this->Xi + partition * newDelta_x);
        return (5 * h / 24) * (11 * this->functionToIntegrate(xi + h) + this->functionToIntegrate(xi + 2 * h) + this->functionToIntegrate(xi + 3 * h) + 11 * this->functionToIntegrate(xi + 4 * h));
    };
    return this->calculate_integral_by_numberOfPartitions(NewtonCotes_third_degree_open_formula, numberOfPartitions);
};

double ThirdDegreeIntegralOpenNewtonCotes::calculateIntegralByError()
{
   double newDelta_x = 0;
    double h = newDelta_x / 5;
    auto NewtonCotes_third_degree_open_formula = [this, &h, &newDelta_x](int partition)
    {
        h = newDelta_x / 5;
        double xi = (this->Xi + partition * newDelta_x);
        return (5 * h / 24) * (11 * this->functionToIntegrate(xi + h) + this->functionToIntegrate(xi + 2 * h) + this->functionToIntegrate(xi + 3 * h) + 11 * this->functionToIntegrate(xi + 4 * h));
    };
    return this->calculate_integral_by_error(NewtonCotes_third_degree_open_formula, tolerance, this->deltaX, newDelta_x);
};

void ThirdDegreeIntegralOpenNewtonCotes::execute()
{
    if(this->numberOfPartitions != -1) {
        this->result = this->calculateIntegralByPartitions();
    }else {
        this->result = this->calculateIntegralByError();
    }
};
