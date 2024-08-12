#include "eigenvalues_eingenvectors/QR/qr_method_.hpp"
#include "visitor/visitor.hpp"

QRMethod::QRMethod(Matrix a, double tolerance) : A{a}, tolerance{tolerance} {};

void QRMethod::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

double QRMethod::sumofsquaresoftermsbelowthediagonal(Matrix A){
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

Matrix QRMethod::JacobiMatrixBasedOnElement_ij_OfOldQRMatrix(Matrix A, int i, int j)
{
    double teta = 0;
    double tolerance = pow(10, -6);
    Matrix Jij = Matrix(A.numberOfRows, A.numberOfColumns, true);
    if (abs(A.getNumber(i, j)) <= tolerance)
    {
        return Jij;
    }
    else if (abs(A.getNumber(j, j)) <= tolerance)
    {
        if (A.getNumber(i, j) < 0)
        {
            teta = M_PI / 2;
        }
        else
        {
            teta = -M_PI / 2;
        }
    }
    else
    {
        teta = atan(-(A.getNumber(i, j) / A.getNumber(j, j)));
    }

    Jij.setValue(cos(teta), i, i);
    Jij.setValue(cos(teta), j, j);
    Jij.setValue(sin(teta), i, j);
    Jij.setValue(-sin(teta), j, i);
   

    return Jij;
};

QRdecompositionResult QRMethod::qrDecomposition(Matrix A) {
    Matrix QT = Matrix(A.numberOfRows, A.numberOfColumns, true);
    Matrix R_old = A;
    Matrix R_new = Matrix();
    Matrix Jij = Matrix();
    for (int j = 0; j < A.numberOfColumns; ++j)
    {
        for (int i = (j + 1); i < A.numberOfRows; ++i)
        {
            Jij = JacobiMatrixBasedOnElement_ij_OfOldQRMatrix(R_old, i, j);
            R_new = Jij * R_old;
            R_old = R_new;
            QT = Jij * QT;
        }
    }
    return QRdecompositionResult(QT.transpose(), R_new);
};

void QRMethod::execute() {
    Matrix P = Matrix(A.numberOfRows, A.numberOfColumns, true);
    Matrix A_new = Matrix();
    double val = 100;
    vector<double> lamb = vector<double>(A.numberOfColumns);
    Matrix A_old = A;
    while (val > tolerance)
    {
        QRdecompositionResult Q_R = qrDecomposition(A_old);
        A_new = Q_R.R * Q_R.Q;
        A_old = A_new;
        P = P * Q_R.Q;
        val = sumofsquaresoftermsbelowthediagonal(A_new);
    }

    this->result = QRMethodResult(A_new.getMainDiagonal(), P, A_new);
};