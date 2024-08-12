#pragma once
#include "../numerical_method/numerical_method.hpp"
#include "../../types/functions.hpp"
#include <vector>
using namespace std;

class IntegralGauss : public NumericalMethod {
    public:
        double Xi;
        double Xf;
        double result;
        functionWithOneArgument functionToIntegrate;
        vector<double> roots;
        vector<double> weights;

        /**
         * Constructor for the integral class to use the integration by number of partitions
         *
         * @param xi the start point xi
         * @param deltax the distance between the xi and the xf, that is, the integration interval
         * @param function the function to integrate
         */
        IntegralGauss(double xi, double xf, functionWithOneArgument function, vector<double> root, vector<double> weight);

        /**
         * This method is the accept method for the visitor pattern
         * used to get the result of the calculation of a method
         *
         * 
         * @return void - this method does not return any value, just prints the result.
         */
        void accept(Visitor& visitor) const override;

        virtual double getXk(int rootIndex) = 0;
};