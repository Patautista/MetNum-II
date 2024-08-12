#include "eigenvalues_eingenvectors/power_methods/shifted_power_method.hpp"
#include "visitor/visitor.hpp"
#include "eigenvalues_eingenvectors/power_methods/inverse_power_method.hpp"

ShiftedPowerMethod::ShiftedPowerMethod(Matrix a, Matrix vectorvo, double tolerance, double shift) : PowerMethods(a, vectorvo, tolerance), shift{shift} {};

void ShiftedPowerMethod::accept(Visitor& visitor) const {
    visitor.visit(*this);
};
        

void ShiftedPowerMethod::execute() {
    Matrix identityMatrix = Matrix(this->A.numberOfRows, this->A.numberOfColumns, true);
    identityMatrix = identityMatrix * this->shift;
    Matrix A_hat = A - identityMatrix;
    InversePowerMethod invsPW = InversePowerMethod(A_hat, this->VectorVo, tolerance);
    invsPW.execute();
    PowerMethodResult result = invsPW.result;
    result.eigenValue = result.eigenValue + this->shift;
    //return EigenValue_Result((result.eigenValue + displacement), result.eigenVector);
    this->result = result;
};