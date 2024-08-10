#pragma once
#include "./integral.hpp"

class SecondDegreeIntegralOpenMilneRule : public Integral {
    public:
        /**
         * Constructor for the integral class to use the integration by number of partitions
         *
         * @param xi the start point xi
         * @param deltax the distance between the xi and the xf, that is, the integration interval
         * @param function the function to integrate
         * @param numberOfPartitions the number of partitions in the integration interval
         */
        SecondDegreeIntegralOpenMilneRule(double xi, double deltax, functionWithOneArgument function, int numberOfPartitions);

        /**
         * Constructor for the integral class to use the integration by error tolerance
         *
         * @param xi the start point xi
         * @param deltax the distance between the xi and the xf, that is, the integration interval
         * @param function the function to integrate
         * @param tolerance the tolerance of the error
         */
        SecondDegreeIntegralOpenMilneRule(double xi, double deltax, functionWithOneArgument function, double tolerance);

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
        

        double calculateIntegralByError() override;
        double calculateIntegralByPartitions() override;
};