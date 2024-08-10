#pragma once
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Matrix
{
private:
    vector<vector<double>> matrix;

public:
    int numberOfRows;
    int numberOfColumns;

    Matrix();

    Matrix(int numberOfRows, int numberOfColumns, bool isIdentity = false);

    /**
     * Print Matrix 
     *
     * this method does not receive any parameter.
     * @return void - this method does not return any value, just prints the matrix.
     */
    void printMatrix();

    /**
     * Returns the value from a specific cell 
     *
     * @param row the number of the row (index starts in zero).
     * @param column the number of the column (index starts in zero)
     * @return double - the value in the cell.
     */
    double getNumber(int row, int column);

    /**
     * Sets a new vector of vector<double> to be the matrix rows and columns
     *
     * @param newMatrixVector a vector of vector<double> to be the matrix rows and columns.
     * @return void - This method does not return any value, just sets the matrix vector.
     */
    void setMatrixVector(vector<vector<double>> newMatrixVector);

    /**
     * Set a new value for a given cell.
     *
     * @param value The new value to store in the cell.
     * @param row The index of cell's row (index starts in zero).
     * @param column The index of cell's column (index starts in zero).
     * @return void - This method does not return any value, just sets the new value in the sell.
     */
    void setValue(double value, int row, int column);

    /**
     * Sums two matrixes 
     *
     * @param otherMatrix A matrix to be add to this one.
     * @return A new Matrix that contains the result of the sum operation
     */
    Matrix operator+(Matrix const &otherMatrix);

    /**
     * Subtraction of two matrixes 
     *
     * @param otherMatrix A matrix to be subtract to this one.
     * @return A new Matrix that contains the result of the subtraction operation
     */
    Matrix operator-(Matrix const &otherMatrix);

    /**
     * Multiplies a matrice by a scalar 
     *
     * @param scalar  A DOUBLE value to multiply the matrix.
     * @return A new Matrix that contains the result of the multiplication
     */
    Matrix operator*(double escalar);

    /**
     * Multiplies two matrixes
     *
     * @param otherMatrix The other matrix to be multiplied with
     * @return A new Matrix that contains the result of the multiplication
     */
    Matrix operator*(Matrix otherMatrix);

    /**
     * Multiplies two vector, that is, two matrixes with n number of rows and 1 column
     *
     * @param otherMatrix The other vector to multiply with
     * @return A Double - the result of the scalar product
     */
    double scalarProductVector(Matrix otherMatrix);

    /**
     * Used in vectors, that is, two matrixes with n number of rows and 1 column
     * this method normalizes the vector 
     *
     * this method does not receive any parameter
     * @return A Double - the result of the scalar product
     */
    void normalize();

    /**
     * A method to multiply a matrix by an escalar
     * but does not return another matrix
     * just alters the value in the matrix cells
     * 
     * @return this method does not return any value
     */
    void multiplyByEscalar(int const &escalar);

    /**
     * Used to calculate the inverse of a matrix
     *
     * this method does not receive any parameter
     * @return A matrix - the inverse of matrix that called the method
     */
    Matrix inverse();

    /**
     * Used to calculate the transpose of a matrix
     *
     * this method does not receive any parameter
     * @return A matrix - the inverse of matrix that called the method
     */
    Matrix transpose();

    /**
     * Used to copy elements from an specific column from another matrix
     *
     * @param otherMatrix the matrix from where to copy the column
     * @param start the cell where to start copy the column
     * @param end the cell where to end the copy of the column
     * @param column the index of the column to copy 
     * @return A matrix - the inverse of matrix that called the method
     */
    void copyElementsFromColumn(Matrix otherMatrix, int start, int end, int column);

    /**
     *  Used to calculate the norm of a vector, that is, a matrix with n number of rows and 1 column
     *
     * this method does not receive any parameter
     * @return a double - the norm of the vector
     */
    double vectorNorm();

    /**
     *  Used to copy the elements from the main diagonal of a matrix
     *
     * this method does not receive any parameter
     * @return A vector, that is, a matrix with n number of rows and 1 column, with the elements of the matrix's main diagonal
     */
    Matrix getMainDiagonal();

    /**
     *  Used to calculate the LU decomposition of the matrix that called this method
     *
     * this method does not receive any parameter
     * @return A std::pair with the matrix L and U resulted from the LU decomposition
     */
    pair<Matrix, Matrix> LU_decomposition();

    Matrix solveLU(pair<Matrix, Matrix> LU, Matrix b);
};