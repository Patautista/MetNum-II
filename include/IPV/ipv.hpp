#pragma once
#include "../../types/functions.hpp"
#include "../numerical_method/numerical_method.hpp"
#include <vector>
using namespace std;

class IPV : public NumericalMethod {
    public:
        double So; 
        double deltaT;
        int numbeOfStates;
        functionWithOneArgument functionOfState;
        vector<double> result;

        IPV(double so, double deltat, functionWithOneArgument function, int numbeofstates);

        void updateValues(double so, double deltat, functionWithOneArgument function, int numbeofstates);
};