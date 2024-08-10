#include "eigenvalues_eingenvectors/power_methods/inverse_power_method_LU.hpp"
#include "visitor/visitor.hpp"


InversePowerMethodWithLU::InversePowerMethodWithLU(Matrix a, Matrix vectorvo, double tolerance) : PowerMethods(a, vectorvo, tolerance) {};

void InversePowerMethodWithLU::accept(Visitor& visitor) const {
    visitor.visit(*this);
};
        

void InversePowerMethodWithLU::execute() {
    pair<Matrix, Matrix> A_LUdecomposition = A.LU_decomposition();
    double EigenValue_new = 0;
    double EigenValue_old = 0;
    double error = 0;
    bool stillNotReachTolerance = true;
    Matrix Vk_new = this->VectorVo;
    Matrix Vk_old = Matrix(this->VectorVo.numberOfRows, this->VectorVo.numberOfColumns);
    while (stillNotReachTolerance)
    {
        EigenValue_old = EigenValue_new;
        Vk_old = Vk_new;
        Vk_old.normalize();
        Vk_new = A.solveLU(A_LUdecomposition, Vk_old);
        EigenValue_new = Vk_old.scalarProductVector(Vk_new);
        error = abs(((EigenValue_new - EigenValue_old) / EigenValue_new));
        if (error <= tolerance)
        {
            stillNotReachTolerance = false;
        }
    }
    this->result =  PowerMethodResult(1 / EigenValue_new, Vk_old);
};