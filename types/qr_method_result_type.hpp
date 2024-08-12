#pragma once
#include "../include/matrix/matrix.hpp"


class QRMethodResult
{
public:
    Matrix eigenValues;
    Matrix P;
    Matrix A;

    QRMethodResult() {}
    QRMethodResult(Matrix eigenvalue, Matrix P, Matrix a) : eigenValues{eigenvalue}, P{P}, A{a} {}
};