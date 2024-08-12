#include "matrix/matrix.hpp"
#include <utility>
using namespace std;

Matrix::Matrix() {}

Matrix::Matrix(int numberOfRows, int numberOfColumns, bool isIdentity)
{
    vector<vector<double>> newMatrice(numberOfRows, vector<double>(numberOfColumns));
    this->numberOfColumns = numberOfColumns;
    this->numberOfRows = numberOfRows;
    this->matrix = newMatrice;
    if (isIdentity)
    {
        for (int i = 0; i < this->numberOfRows; ++i)
        {
            this->matrix[i][i] = 1;
        }
    }
}

void Matrix::printMatrix()
{
    for (int i = 0; i < this->numberOfRows; ++i)
    {
        for (int j = 0; j < this->numberOfColumns; ++j)
        {
            cout << this->matrix[i][j] << "               ";
        }
        cout << "\n";
    }
}

double Matrix::getNumber(int row, int column)
{
    return this->matrix[row][column];
}

void Matrix::setMatrixVector(vector<vector<double>> newMatrice)
{
    this->matrix = newMatrice;
    this->numberOfColumns = newMatrice[0].size();
    this->numberOfRows = newMatrice.size();
}

void Matrix::setValue(double value, int row, int column)
{
    this->matrix[row][column] = value;
}

Matrix Matrix::operator+(Matrix const &otherMatrix)
{
    Matrix result = Matrix(this->numberOfRows, this->numberOfColumns);
    if (otherMatrix.numberOfRows == this->numberOfRows && otherMatrix.numberOfColumns == this->numberOfColumns)
    {
        for (int i = 0; i < this->numberOfRows; ++i)
        {
            for (int j = 0; j < this->numberOfColumns; ++j)
            {
                result.matrix[i][j] = this->matrix[i][j] + otherMatrix.matrix[i][j];
            }
        }
    }
    else
    {
        cout << "The Matrice should have the same number of rows and columns\n";
    }
    return result;
}

Matrix Matrix::operator-(Matrix const &otherMatrix)
{
    Matrix result = Matrix(this->numberOfRows, this->numberOfColumns);
    if (otherMatrix.numberOfRows == this->numberOfRows && otherMatrix.numberOfColumns == this->numberOfColumns)
    {
        for (int i = 0; i < this->numberOfRows; ++i)
        {
            for (int j = 0; j < this->numberOfColumns; ++j)
            {
                result.matrix[i][j] = this->matrix[i][j] - otherMatrix.matrix[i][j];
            }
        }
    }
    else
    {
        cout << "The Matrice should have the same number of rows and columns\n";
    }
    return result;
}

Matrix Matrix::operator*(double escalar)
{
    Matrix result = Matrix(this->numberOfRows, this->numberOfColumns);
    for (int i = 0; i < this->numberOfRows; ++i)
    {
        for (int j = 0; j < this->numberOfColumns; ++j)
        {
            result.matrix[i][j] = this->matrix[i][j] * escalar;
        }
    }
    return result;
}

Matrix Matrix::operator*(Matrix otherMatrix)
{
    Matrix result = Matrix(this->numberOfRows, otherMatrix.numberOfColumns);
    if (this->numberOfColumns == otherMatrix.numberOfRows)
    {
        for (int i = 0; i < this->numberOfRows; ++i)
        {
            for (int j = 0; j < otherMatrix.numberOfColumns; ++j)
            {
                for (int k = 0; k < otherMatrix.numberOfRows; ++k)
                {
                    result.matrix[i][j] += this->matrix[i][k] * otherMatrix.matrix[k][j];
                }
            }
        }
    }
    else
    {
        cout << "The number of columns of the matrice one must be the same number of rows of the matrice two\n";
    }
    return result;
}

double Matrix::scalarProductVector(Matrix otherMatrix)
{
    double result = 0;
    if (this->numberOfColumns == 1 && otherMatrix.numberOfColumns == 1 && this->numberOfRows == otherMatrix.numberOfRows)
    {
        for (int i = 0; i < this->numberOfRows; ++i)
        {
            result += this->matrix[i][0] * otherMatrix.matrix[i][0];
        }
    }
    return result;
}

void Matrix::normalize()
{
    if (this->numberOfColumns == 1)
    {
        double squareSum = 0;
        for (int i = 0; i < this->numberOfRows; ++i)
        {
            squareSum += this->matrix[i][0] * this->matrix[i][0];
        }
        double sqrtOfScalarProduct = sqrt(squareSum);
        for (int i = 0; i < this->numberOfRows; ++i)
        {
            this->matrix[i][0] *= (1 / sqrtOfScalarProduct);
        }
    }
}

void Matrix::multiplyByEscalar(int const &escalar)
{
    for (int i = 0; i < this->numberOfRows; ++i)
    {
        for (int j = 0; j < this->numberOfColumns; ++j)
        {
            this->matrix[i][j] * escalar;
        }
    }
}

Matrix Matrix::inverse()
{
    vector<double> identiyMatrixLine = vector<double>(this->numberOfColumns, 0);
    Matrix copyOfClassMatrix = *(this);
    for (int i = 0; i < this->numberOfRows; ++i)
    {
        fill(identiyMatrixLine.begin(), identiyMatrixLine.end(), 0);
        identiyMatrixLine[i] = 1;
        copyOfClassMatrix.matrix[i].insert(copyOfClassMatrix.matrix[i].end(), identiyMatrixLine.begin(), identiyMatrixLine.end());
    }
    copyOfClassMatrix.numberOfColumns *= 2;
    for (int i = 0; i < numberOfRows; ++i)
    {
        double diag = copyOfClassMatrix.matrix[i][i];
        for (int j = 0; j < copyOfClassMatrix.numberOfColumns; ++j)
        {
            copyOfClassMatrix.matrix[i][j] /= diag;
        }

        for (int k = 0; k < numberOfRows; ++k)
        {
            if (k != i)
            {
                double factor = copyOfClassMatrix.matrix[k][i];
                for (int j = 0; j < copyOfClassMatrix.numberOfColumns; ++j)
                {
                    copyOfClassMatrix.matrix[k][j] -= factor * copyOfClassMatrix.matrix[i][j];
                }
            }
        }
    }

    Matrix inverseMatrix(numberOfRows, numberOfRows);
    for (int i = 0; i < numberOfRows; ++i)
    {
        for (int j = 0; j < numberOfRows; ++j)
        {
            inverseMatrix.matrix[i][j] = copyOfClassMatrix.matrix[i][j + numberOfRows];
        }
    }

    return inverseMatrix;
}

Matrix Matrix::transpose()
{
    Matrix result = Matrix(this->numberOfColumns, this->numberOfRows);
    for (int i = 0; i < this->numberOfRows; ++i)
    {
        for (int j = 0; j < this->numberOfColumns; ++j)
        {
            result.matrix[j][i] = this->matrix[i][j];
        }
    }
    return result;
}

void Matrix::copyElementsFromColumn(Matrix otherMatrice, int start, int end, int column)
{
    if (this->numberOfColumns == 1)
    {
        for (int i = start; i < end; ++i)
        {
            this->matrix[i][0] = otherMatrice.matrix[i][column];
        }
    }
}

double Matrix::vectorNorm()
{
    double result = 0;
    if (this->numberOfColumns == 1)
    {
        for (int i = 0; i < this->numberOfRows; ++i)
        {
            result += pow(this->matrix[i][0], 2);
        }
    }
    return sqrt(result);
}

Matrix Matrix::getMainDiagonal()
{
    Matrix vector = Matrix(this->numberOfRows, 1);
    for (int i = 0; i < this->numberOfRows; ++i)
    {
        vector.setValue(this->matrix[i][i], i, 0);
    }
    return vector;
}

pair<Matrix, Matrix> Matrix::LU_decomposition()
{
    Matrix U = *(this);
    Matrix L = Matrix(this->numberOfRows, this->numberOfColumns, true);
    double pivot = 0;
    double numberToZero = 0;
    double factor = 0;
    for (int i = 0; i < U.numberOfColumns - 1; ++i)
    {
        pivot = U.matrix[i][i];
        for (int j = i + 1; j < U.numberOfRows; ++j)
        {
            // numberToZero = U.matrix[j][i];
            factor = U.matrix[j][i] / pivot;
            for (int k = i; k < U.numberOfColumns; ++k)
            {
                U.matrix[j][k] -= factor * U.matrix[i][k];
            }
            L.matrix[j][i] = factor;
        }
    }

    return make_pair(L, U);
}

Matrix Matrix::solveLU(pair<Matrix, Matrix> LU, Matrix b)
{
    Matrix L = LU.first;
    Matrix U = LU.second;
    int n = b.numberOfRows;
    Matrix y(n, 1);
    Matrix x(n, 1);

    for (int i = 0; i < n; ++i)
    {
        double sum = 0;
        for (int j = 0; j < i; ++j)
        {
            sum += L.getNumber(i, j) * y.getNumber(j, 0);
        }
        y.setValue(b.getNumber(i, 0) - sum, i, 0);
    }

    for (int i = n - 1; i >= 0; --i)
    {
        double sum = 0;
        for (int j = i + 1; j < n; ++j)
        {
            sum += U.getNumber(i, j) * x.getNumber(j, 0);
        }
        x.setValue((y.getNumber(i, 0) - sum) / U.getNumber(i, i), i, 0);
    }

    return x;
};