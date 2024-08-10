#pragma once
#include "../numerical_method/numerical_method.hpp"
#include "../../types/functions.hpp"

class Derivate : public NumericalMethod {
    public:
        double deltaX;
        double Xi;
        double result;
        functionWithOneArgument functionToDerive;

        Derivate(double xi, double deltax, functionWithOneArgument function);

        void setXi(double xi);
};