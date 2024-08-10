#pragma once

class Visitor;

// this class is doing the job of class strategy in the strategy pattern
class NumericalMethod {
    public:
       /**
         * Destructor for the class NumericalMethod
         *
         * this method does not receive any parameter.
         */
        virtual ~NumericalMethod() = default;

        /**
         * This method is the accept method for the visitor pattern
         * used to get the result of the calculation of a method
         *
         * @param visitor the numerical method visitor, responsible to show the result of the method
         * @return void - this method does not return any value, just prints the result.
         */
        virtual void accept(Visitor& visitor) const = 0;
        
        /**
         * Used by the context class to call the execution of some numerical method 
         * This method does not receive any parameter
         * 
         * @return void - This method does not return any value, just sets the result on the result attribute 
         */
        virtual void execute() = 0;
};