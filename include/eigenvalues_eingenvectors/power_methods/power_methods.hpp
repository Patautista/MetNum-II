#pragma once
#include "../../numerical_method/numerical_method.hpp"
#include "../../matrix/matrix.hpp"
#include "../../../types/power_method_result_type.hpp"

class PowerMethods : public NumericalMethod {
    public:
        Matrix A;
        Matrix VectorVo;
        double tolerance;
        PowerMethodResult result;

        PowerMethods(Matrix a, Matrix vectorvo, double tolerance);
};