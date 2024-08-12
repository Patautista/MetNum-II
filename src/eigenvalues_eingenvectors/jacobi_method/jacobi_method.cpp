#include "eigenvalues_eingenvectors/jacobi/jacobi_method.hpp"
#include "visitor/visitor.hpp"

JacobiMethod::JacobiMethod(Matrix a, double tolerance) : A{a}, tolerance{tolerance} {};

void JacobiMethod::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

Matrix JacobiMethod::JacobiMatrixBasedOnElement_ij_OfOldMatrix(Matrix A, int i, int j){
    double teta = 0;
    double tolerance = pow(10, -6);
    Matrix Jij = Matrix(A.numberOfRows, A.numberOfColumns, true);
    if (abs(A.getNumber(i, j)) <= tolerance)
    {
        return Jij;
    }
    else if (abs((A.getNumber(i, i)) - (A.getNumber(j, j))) <= tolerance)
    {
        teta = M_PI / 4;
    }
    else
    {
        teta = (0.5 * (atan((-2 * A.getNumber(i, j)) / (A.getNumber(i, i) - A.getNumber(j, j)))));
    }

    Jij.setValue(cos(teta), i, i);
    Jij.setValue(cos(teta), j, j);
    Jij.setValue(sin(teta), i, j);
    Jij.setValue(-sin(teta), j, i);

    return Jij;
};

JacobiScanResult JacobiMethod::jacobiScan(Matrix A){
    Matrix J = Matrix(A.numberOfRows, A.numberOfColumns, true);
    Matrix A_old = A;
    Matrix A_new = Matrix();
    Matrix Jij = Matrix();
    for (int i = 0; i < A.numberOfColumns; ++i)
    {
        for (int j = i + 1; j < A.numberOfRows; ++j)
        {
            Jij = JacobiMatrixBasedOnElement_ij_OfOldMatrix(A_old, i, j);
            A_new = (Jij).transpose() * A_old * Jij;
            
            A_old = A_new;
            J = J * Jij;
        }
    }
    return JacobiScanResult(A_new, J);
};

double JacobiMethod::sumofsquaresoftermsbelowthediagonal(Matrix A){
    double sum = 0;
    for (int j = 0; j < A.numberOfColumns; ++j)
    {
        for (int i = j + 1; i < A.numberOfRows; ++i)
        {
            sum += pow(A.getNumber(i, j), 2);
        }
    }
    return sum;
};

void JacobiMethod::execute(){
    Matrix P = Matrix(A.numberOfRows, A.numberOfColumns, true);
    double val = 100;
    vector<double> lamb = vector<double>(A.numberOfColumns);
    Matrix A_old = A;

    JacobiScanResult A_new_Jij = JacobiScanResult();
    while (val > tolerance)
    {
        A_new_Jij = jacobiScan(A_old);
        A_old = A_new_Jij.A;
        P = P * A_new_Jij.J;
        val = sumofsquaresoftermsbelowthediagonal(A_new_Jij.A);
    }
    this->result = JacobiMethodResult(A_new_Jij.A.getMainDiagonal(), P);
};

