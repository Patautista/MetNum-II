#include "integral/second_degree_integral_simpson_onethird.hpp"
#include "visitor/visitor.hpp"

SecondDegreeIntegralSimpsonOnethird::SecondDegreeIntegralSimpsonOnethird(double xi, double deltax, functionWithOneArgument function, int numberOfPartitions) : Integral(xi, deltax, function, numberOfPartitions){};

SecondDegreeIntegralSimpsonOnethird::SecondDegreeIntegralSimpsonOnethird(double xi, double deltax, functionWithOneArgument function, double tolerance) : Integral(xi, deltax, function, tolerance){};

void SecondDegreeIntegralSimpsonOnethird::accept(Visitor& visitor) const {
    visitor.visit(*this);
};



double SecondDegreeIntegralSimpsonOnethird::calculateIntegralByPartitions()
{
    double newDelta_x = this->deltaX / this->numberOfPartitions;
    double h = newDelta_x / 2;
    auto NewtonCotes_simpson_formula = [this, h, newDelta_x](int partition)
    {
        double xi = (this->Xi + partition * newDelta_x);
        return (h / 3) * (this->functionToIntegrate(xi) + 4 * this->functionToIntegrate(xi + h) + this->functionToIntegrate(xi + 2 * h));
    };
    return this->calculate_integral_by_numberOfPartitions(NewtonCotes_simpson_formula, numberOfPartitions);
};

double SecondDegreeIntegralSimpsonOnethird::calculateIntegralByError()
{
    double newDelta_x = 0;
    double h = newDelta_x / 2;
    auto NewtonCotes_simpson_formula = [this, &h, &newDelta_x](int partition)
    {
        h = newDelta_x / 2;
        double xi = (this->Xi + partition * newDelta_x);
        return (h / 3) * (this->functionToIntegrate(xi) + 4 * this->functionToIntegrate(xi + h) + this->functionToIntegrate(xi + 2 * h));
    };
    return this->calculate_integral_by_error(NewtonCotes_simpson_formula, tolerance, this->deltaX, newDelta_x);
};

void SecondDegreeIntegralSimpsonOnethird::execute()
{
    if(this->numberOfPartitions != -1) {
        this->result = this->calculateIntegralByPartitions();
    }else {
        this->result = this->calculateIntegralByError();
    }
};
