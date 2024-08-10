#pragma once
#include "../include/matrix/matrix.hpp"

class HouseHolderMethodResult
{
public:
    Matrix A_hat_matrix;
    Matrix H_matrix;

    HouseHolderMethodResult() {}
    HouseHolderMethodResult(Matrix ahatMatrix, Matrix hmatrix) : A_hat_matrix{ahatMatrix}, H_matrix{hmatrix} {};
};