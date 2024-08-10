#pragma once
#include "../include/matrix/matrix.hpp"

class QRdecompositionResult
{
public:
    Matrix Q;
    Matrix R;

    QRdecompositionResult() {}
    QRdecompositionResult(Matrix q, Matrix r) : Q{q}, R{r} {};
};