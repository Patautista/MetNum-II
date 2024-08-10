#pragma once
#include "../include/matrix/matrix.hpp"

class PowerMethodResult
{
public:
    double eigenValue;
    Matrix eigenVector;
 
    PowerMethodResult() {}
    PowerMethodResult(double eingenvalue, Matrix eigenvector) : eigenValue{eingenvalue}, eigenVector{eigenvector} {}
};