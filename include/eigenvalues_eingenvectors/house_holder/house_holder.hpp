#pragma once
#include "../../numerical_method/numerical_method.hpp"
#include "../../matrix/matrix.hpp"
#include "../../../types/house_holder_result_type.hpp"

class HouseHolderMethod : public NumericalMethod {
    public:
        Matrix A;  
        HouseHolderMethodResult result;

        HouseHolderMethod(Matrix a);

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

        Matrix houseHolderMatrixBasedOnColumnIfromPreviousMatrix(Matrix A, int i);

};