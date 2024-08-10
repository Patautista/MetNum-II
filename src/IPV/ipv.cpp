#include "IPV/ipv.hpp"

IPV::IPV(double so, double deltat, functionWithOneArgument function, int numbeofstates) : So{so}, deltaT{deltat}, functionOfState{function}, numbeOfStates{numbeofstates} {};

void IPV::updateValues(double so, double deltat, functionWithOneArgument function, int numbeofstates)
{
    this->So = so;
    this->deltaT = deltat;
    this->functionOfState = function;
    this->numbeOfStates = numbeofstates;
};
