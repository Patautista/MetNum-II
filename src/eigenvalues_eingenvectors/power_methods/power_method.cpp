#include "eigenvalues_eingenvectors/power_methods/power_method.hpp"
#include "visitor/visitor.hpp"

PowerMethod::PowerMethod(Matrix a, Matrix vectorvo, double tolerance) : PowerMethods(a, vectorvo, tolerance) {};

void PowerMethod::accept(Visitor& visitor) const {
    visitor.visit(*this);
};
        

void PowerMethod::execute() {
    double newEigenValue = 0;
    double oldEigenValue = 0;
    Matrix Vk_new = this->VectorVo;
    Matrix Vk_old = Matrix(this->VectorVo.numberOfRows, this->VectorVo.numberOfColumns);
    bool stillNotReachTolerance = true;
    double error = 0;
    while (stillNotReachTolerance)
    {

        oldEigenValue = newEigenValue;
        Vk_old = Vk_new;
        Vk_old.normalize();
        Vk_new = A * Vk_old;
        newEigenValue = Vk_old.scalarProductVector(Vk_new);
        error = abs(((newEigenValue - oldEigenValue) / newEigenValue));
        if (error <= tolerance)
        {
            stillNotReachTolerance = false;
        }
    }
    this->result = PowerMethodResult(newEigenValue, Vk_old);
};