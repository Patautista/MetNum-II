#include "IPV/euler_method_implict.hpp"
#include "derivate/first_derivate_forward_approach.hpp"
#include "visitor/visitor.hpp"

EulerMethodImplict::EulerMethodImplict(double so, double deltat, functionWithOneArgument function, int numbeofstates) : IPV(so, deltat, function, numbeofstates) {};


void EulerMethodImplict::accept(Visitor& visitor) const {
    visitor.visit(*this);
};


double EulerMethodImplict::newtonRaphsonMethod(double Xinitial, double tolerance, std::function<double(double)> function)
{
    double Xn = Xinitial;
    FirstDerivateForwardApproach derivate = FirstDerivateForwardApproach(Xn, 0.0001, this->functionOfState);
    derivate.execute();
    //double functionDerivate = derivate.result;
    double Xnp1 = Xn - function(Xn) / derivate.result;//Derivate::Forward_first_derivate_e1(function, Xn, 0.0001);
    while (abs(function(Xnp1)) > tolerance)
    {
        Xn = Xnp1;
        derivate.setXi(Xn);
        derivate.execute();
        Xnp1 = Xn - function(Xn) / derivate.result;   // / Derivate::Forward_first_derivate_e1(function, Xn, 0.0001);
    }
    return Xnp1;
};


void EulerMethodImplict::execute() {
    vector<double> states = {So};
    double Si = 0;
    int iteration = 1;
    auto functionToFindRoot = [&Si, this, &states, &iteration](double x)
    {
        return states[iteration - 1] + this->deltaT * this->functionOfState(x) - x;
    };
    while (iteration <= this->numbeOfStates)
    {
        Si = this->newtonRaphsonMethod(1.0, 0.0001, functionToFindRoot);
        states.push_back(Si);
        iteration += 1;
    }
    this->result = states;
};