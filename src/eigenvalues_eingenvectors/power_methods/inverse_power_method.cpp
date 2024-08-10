#include "eigenvalues_eingenvectors/power_methods/inverse_power_method.hpp"
#include "eigenvalues_eingenvectors/power_methods/power_method.hpp"
#include "visitor/visitor.hpp"

InversePowerMethod::InversePowerMethod(Matrix a, Matrix vectorvo, double tolerance) : PowerMethods(a, vectorvo, tolerance) {};

void InversePowerMethod::accept(Visitor& visitor) const {
    visitor.visit(*this);
};
        

void InversePowerMethod::execute() {
    Matrix A_inverse = A.inverse();
    PowerMethod pwMethod = PowerMethod(A_inverse, this->VectorVo, tolerance);
    pwMethod.execute();
    PowerMethodResult result = pwMethod.result;
    result.eigenValue = 1 / result.eigenValue;
    //this->result =  PowerMethodResult((1 / result.eigenValue), result.eigenVector);
    this->result = result;
};