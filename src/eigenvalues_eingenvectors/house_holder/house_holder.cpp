#include "eigenvalues_eingenvectors/house_holder/house_holder.hpp"
#include "visitor/visitor.hpp"

HouseHolderMethod::HouseHolderMethod(Matrix a) : A{a} {};

void HouseHolderMethod::accept(Visitor& visitor) const 
{
    visitor.visit(*this);
};

Matrix HouseHolderMethod::houseHolderMatrixBasedOnColumnIfromPreviousMatrix(Matrix A, int i)
{
    double Lw = 0;
    Matrix W_vector = Matrix(A.numberOfRows, 1);
    Matrix W_prime_vector = Matrix(A.numberOfRows, 1);
    W_vector.copyElementsFromColumn(A, i + 1, A.numberOfRows, i);
    Lw = W_vector.vectorNorm();
    W_prime_vector.setValue(Lw, i + 1, 0);
    Matrix N = W_vector - W_prime_vector;
    N.normalize();
    Matrix TwoTimesNtimesN = (N * (N.transpose())) * 2;
    Matrix I = Matrix(TwoTimesNtimesN.numberOfRows, TwoTimesNtimesN.numberOfColumns, true);
    return I - TwoTimesNtimesN;
};

void HouseHolderMethod::execute() 
{
    Matrix H = Matrix(A.numberOfRows, A.numberOfColumns, true);
    Matrix Ai_one = A;
    Matrix Hi = Matrix();
    Matrix Ai = Matrix();
    for (int i = 0; i < A.numberOfColumns - 2; ++i)
    {
        Hi = this->houseHolderMatrixBasedOnColumnIfromPreviousMatrix(A, i);
        Ai = (Hi.transpose()) * Ai_one * Hi;
        Ai_one = Ai;
        H = H * Hi;
    }
    //Matrix A_hat = Ai;
    this->result = HouseHolderMethodResult(Ai, H);
};