#include "integral/second_degree_integral_open_milnerule.hpp"
#include "visitor/visitor.hpp"

SecondDegreeIntegralOpenMilneRule::SecondDegreeIntegralOpenMilneRule(double xi, double deltax, functionWithOneArgument function, int numberOfPartitions) : Integral(xi, deltax, function, numberOfPartitions){};

SecondDegreeIntegralOpenMilneRule::SecondDegreeIntegralOpenMilneRule(double xi, double deltax, functionWithOneArgument function, double tolerance) : Integral(xi, deltax, function, tolerance){};

void SecondDegreeIntegralOpenMilneRule::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

double SecondDegreeIntegralOpenMilneRule::calculateIntegralByPartitions()
{
    double newDelta_x = this->deltaX / this->numberOfPartitions;
    double h = newDelta_x / 4;
    auto NewtonCotes_milne_rule_formula = [this, h, newDelta_x](int partition)
    {
        double xi = (this->Xi + partition * newDelta_x);
        return (4 * h / 3) * (2 * this->functionToIntegrate(xi + h) - this->functionToIntegrate(xi + 2 * h) + 2 * this->functionToIntegrate(xi + 3 * h));
    };
    return this->calculate_integral_by_numberOfPartitions(NewtonCotes_milne_rule_formula, numberOfPartitions);
};

double SecondDegreeIntegralOpenMilneRule::calculateIntegralByError()
{
    double newDelta_x = 0;
    double h = newDelta_x / 4;
    auto NewtonCotes_milne_rule_formula = [this, &h, &newDelta_x](int partition)
    {
        h = newDelta_x / 4;
        double xi = (this->Xi + partition * newDelta_x);
        return (4 * h / 3) * (2 * this->functionToIntegrate(xi + h) - this->functionToIntegrate(xi + 2 * h) + 2 * this->functionToIntegrate(xi + 3 * h));
    };
    return this->calculate_integral_by_error(NewtonCotes_milne_rule_formula, tolerance, this->deltaX, newDelta_x);
};

void SecondDegreeIntegralOpenMilneRule::execute()
{
    if(this->numberOfPartitions != -1) {
        this->result = this->calculateIntegralByPartitions();
    }else {
        this->result = this->calculateIntegralByError();
    }
};
