#pragma once
#include "../include/matrix/matrix.hpp"

class JacobiMethodResult
{
public:
    Matrix eigenValues;
    Matrix P;

    JacobiMethodResult() {}
    JacobiMethodResult(Matrix eigenvalue, Matrix P) : eigenValues{eigenvalue}, P{P} {}
};