#pragma once
#include "../numerical_method/numerical_method.hpp"
#include "../../types/functions.hpp"
#include <functional>

class Integral : public NumericalMethod {
    public:
        double deltaX;
        double Xi;
        int numberOfPartitions;
        double tolerance;
        double result;
        functionWithOneArgument functionToIntegrate;
     
 
        /**
         * Constructor for the integral class to use the integration by number of partitions
         *
         * @param xi the start point xi
         * @param deltax the distance between the xi and the xf, that is, the integration interval
         * @param function the function to integrate
         * @param numberOfPartitions the number of partitions in the integration interval
         */
        Integral(double xi, double deltax, functionWithOneArgument function, int numberOfPartitions);

        /**
         * Constructor for the integral class to use the integration by error tolerance
         *
         * @param xi the start point xi
         * @param deltax the distance between the xi and the xf, that is, the integration interval
         * @param function the function to integrate
         * @param tolerance the tolerance of the error
         */
        Integral(double xi, double deltax, functionWithOneArgument function, double tolerance);

        /**
         * A method used internally by integral class to calculate the result by number of partitions
         */
        
        double calculate_integral_by_numberOfPartitions(std::function<double(int)> integralFormula, int numberOfPartitions);

        /**
         * A method used internally by integral class to calculate the result by number of error tolerance
         */
        double calculate_integral_by_error(std::function<double(int)> integralFormula, double tolerance, double delta_x, double &newDelta_x);

        virtual double calculateIntegralByError() = 0;
        virtual double calculateIntegralByPartitions() = 0;

        
};