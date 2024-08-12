#include "IPV/adams_bashforth_method_second_order.hpp"
#include "IPV/range_kutta_method_second_order.hpp"
#include "visitor/visitor.hpp"

AdamsBashForthSecondOrder::AdamsBashForthSecondOrder(double so, double deltat, functionWithOneArgument function, int numbeofstates) : IPV(so, deltat, function, numbeofstates) {};


void AdamsBashForthSecondOrder::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

void AdamsBashForthSecondOrder::execute() {
    vector<double> states = {So};
    double Si, Si_bar = 0;
    RangeKuttaSecondOrderMethod range = RangeKuttaSecondOrderMethod(this->So, this->deltaT, this->functionOfState, 1);
    range.execute();
    double S_one = range.result.back();
    states.push_back(S_one);

    for (int i = 2; i <= this->numbeOfStates; ++i)
    {
        Si_bar = states[i - 1] + (deltaT / 2) * (3 * this->functionOfState(states[i - 1]) - this->functionOfState(states[i - 2]));
        Si = states[i - 1] + deltaT * (0.5 * this->functionOfState(states[i - 1]) + 0.5 * this->functionOfState(Si_bar));
        states.push_back(Si);
    }
    this->result = states;
};