#pragma once 
#include "../../numerical_method/numerical_method.hpp"
#include "../../matrix/matrix.hpp"
#include "../../../types/jacobi_method_result_type.hpp"
#include "../../../types/jacobi_scan_result_type.hpp"


class JacobiMethod : public NumericalMethod {
    public:
        Matrix A;
        double tolerance;
        JacobiMethodResult result;

        JacobiMethod(Matrix a, double tolerance);

        /**
         * This method is the accept method for the visitor pattern
         * used to get the result of the calculation of a method
         *
         * 
         * @return void - this method does not return any value, just prints the result.
         */
        void accept(Visitor& visitor) const override;
        
        /**
         * Used by the context class to call the execution of some numerical method 
         * This method does not receive any parameter
         * 
         * @return void - This method does not return any value, just sets the result on the result attribute 
         */
        void execute() override;

        JacobiScanResult jacobiScan(Matrix A);

        double sumofsquaresoftermsbelowthediagonal(Matrix A);

        Matrix JacobiMatrixBasedOnElement_ij_OfOldMatrix(Matrix A, int i, int j);
};