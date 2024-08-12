#include "IPV/range_kutta_method_fourth_order.hpp"
#include "IPV/euler_method_explict.hpp"
#include "visitor/visitor.hpp"

RangeKuttaFourthOrderMethod::RangeKuttaFourthOrderMethod(double so, double deltat, functionWithOneArgument function, int numbeofstates) : IPV(so, deltat, function, numbeofstates) {};


void RangeKuttaFourthOrderMethod::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

// THIS METHOD IS NOT IMPLEMENTED FOR RANGE KUTTA FOURTH ORDER
void RangeKuttaFourthOrderMethod::execute() {
    vector<double> states = {So};
    double Si_bar = 0;
    double Si = 0;
    EulerMethodExplict euler = EulerMethodExplict(So, deltaT, this->functionOfState, 1);
    for (int i = 1; i <= this->numbeOfStates; ++i)
    {
        euler.updateValues(states[i - 1], deltaT, this->functionOfState, 1);
        euler.execute();
        Si_bar = euler.result.back(); //EulerMethods::explicitEulerMethod(states[i - 1], deltaT, function, 1).back();
        Si = states[i - 1] + deltaT * (0.5 * this->functionOfState(states[i - 1]) + 0.5 * this->functionOfState(Si_bar));
        states.push_back(Si);
    }
    this->result = states;
};