#pragma once
#include "./integral_gauss.hpp"


class ThirdDegreeIntegralGuassChebyShev : public IntegralGauss {
    public:
        //vector<double> roots = {-0.577350269, 0.577350269};
        //vector<double> weights = {1,1};

        /**
         * Constructor for the integral class to use the integration by number of partitions
         *
         * @param xi the start point xi
         * @param deltax the distance between the xi and the xf, that is, the integration interval
         * @param function the function to integrate
         */
        ThirdDegreeIntegralGuassChebyShev(double xi, double xf, functionWithOneArgument function);

        /**
         * This method is the accept method for the visitor pattern
         * used to get the result of the calculation of a method
         *
         * 
         * @return void - this method does not return any value, just prints the result.
         */
        void accept(Visitor& visitor) const override;

         /**
         * Used by the context class to call the execution of some numerical method 
         * This method does not receive any parameter
         * 
         * @return void - This method does not return any value, just sets the result on the result attribute 
         */
        void execute() override;

        double getXk(int rootIndex) override;

};