#pragma once
#include "../include/matrix/matrix.hpp"

class JacobiScanResult
{
public:
    Matrix A;
    Matrix J;

    JacobiScanResult() {}
    JacobiScanResult(Matrix a, Matrix j) : A{a}, J{j} {};
};