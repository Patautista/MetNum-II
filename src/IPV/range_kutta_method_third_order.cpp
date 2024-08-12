#include "IPV/range_kutta_method_third_order.hpp"
#include "IPV/euler_method_explict.hpp"
#include "visitor/visitor.hpp"

RangeKuttaThirdOrderMethod::RangeKuttaThirdOrderMethod(double so, double deltat, functionWithOneArgument function, int numbeofstates) : IPV(so, deltat, function, numbeofstates) {};


void RangeKuttaThirdOrderMethod::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

void RangeKuttaThirdOrderMethod::execute() {
   vector<double> states = {So};
    double Si_bar, Si_bar_half, Si = 0;
    EulerMethodExplict euler_bar_half = EulerMethodExplict(So, deltaT, this->functionOfState, 1);
    EulerMethodExplict euler_bar = EulerMethodExplict(So, deltaT, this->functionOfState, 1);
    for (int i = 1; i <= this->numbeOfStates; ++i)
    {
        euler_bar_half.updateValues(states[i - 1], deltaT / 2, this->functionOfState, 1);
        euler_bar_half.execute();
        Si_bar_half = euler_bar_half.result.back();//EulerMethods::explicitEulerMethod(states[i - 1], deltaT / 2, function, 1).back();

        euler_bar.updateValues(states[i - 1], deltaT, this->functionOfState, 1);
        euler_bar.execute();
        Si_bar = euler_bar.result.back();//EulerMethods::explicitEulerMethod(states[i - 1], deltaT, function, 1).back();
        Si = states[i - 1] + deltaT * ((1.0 / 6.0) * this->functionOfState(states[i - 1]) + (2.0 / 3.0) * this->functionOfState(Si_bar_half) + (1.0 / 6.0) * this->functionOfState(Si_bar));
        states.push_back(Si);
    }
    this->result = states;
};