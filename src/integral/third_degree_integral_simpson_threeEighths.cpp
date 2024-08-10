#include "integral/third_degree_integral_simpson_threeEighths.hpp"
#include "visitor/visitor.hpp"

ThirdDegreeIntegralSimpsonThreeEighths::ThirdDegreeIntegralSimpsonThreeEighths(double xi, double deltax, functionWithOneArgument function, int numberOfPartitions) : Integral(xi, deltax, function, numberOfPartitions){};

ThirdDegreeIntegralSimpsonThreeEighths::ThirdDegreeIntegralSimpsonThreeEighths(double xi, double deltax, functionWithOneArgument function, double tolerance) : Integral(xi, deltax, function, tolerance){};

void ThirdDegreeIntegralSimpsonThreeEighths::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

double ThirdDegreeIntegralSimpsonThreeEighths::calculateIntegralByPartitions()
{
    double newDelta_x = this->deltaX / this->numberOfPartitions;
    double h = newDelta_x / 2;
    auto NewtonCotes_simpson_formula = [this, h, newDelta_x](int partition)
    {
        double xi = (Xi + partition * newDelta_x);
        return (h / 3) * (this->functionToIntegrate(this->Xi) + 4 * this->functionToIntegrate(this->Xi + h) + this->functionToIntegrate(this->Xi + 2 * h));
    };
    return this->calculate_integral_by_numberOfPartitions(NewtonCotes_simpson_formula, numberOfPartitions);
};

double ThirdDegreeIntegralSimpsonThreeEighths::calculateIntegralByError()
{
    double newDelta_x = 0;
    double h = newDelta_x / 2;
    auto NewtonCotes_simpson_formula = [this, &h, &newDelta_x](int partition)
    {
        h = newDelta_x / 2;
        double xi = (Xi + partition * newDelta_x);
        return (h / 3) * (this->functionToIntegrate(this->Xi) + 4 * this->functionToIntegrate(this->Xi + h) + this->functionToIntegrate(this->Xi + 2 * h));
    };
    return this->calculate_integral_by_error(NewtonCotes_simpson_formula, tolerance, this->deltaX, newDelta_x);
};

void ThirdDegreeIntegralSimpsonThreeEighths::execute()
{
    if(this->numberOfPartitions != -1) {
        this->result = this->calculateIntegralByPartitions();
    }else {
        this->result = this->calculateIntegralByError();
    }
};
