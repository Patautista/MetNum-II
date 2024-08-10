#pragma once
#include <ostream>
#include <iostream>

using namespace std;

class Derivate;
class Integral;
class IntegralGauss;
class PowerMethods;
class HouseHolderMethod;
class JacobiMethod;
class QRMethod;
class IPV;

class Visitor {
    public:
        /**
         * This method is used to show the result of a derivate 
         *
         * @param derivate the derivate class to show thes result
         * @return void - this method does not return any value, just prints the result.
         */
        void visit(const Derivate& derivate);

        /**
         * This method is used to show the result of a integral 
         *
         * @param integral the integral class to show thes result
         * @return void - this method does not return any value, just prints the result.
         */
        void visit(const Integral& integral);

        /**
         * This method is used to show the result of a power method 
         *
         * @param powerMethod the powerMethod class to show thes result
         * @return void - this method does not return any value, just prints the result.
         */
        void visit(const PowerMethods& powerMethod);

         /**
         * This method is used to show the result of a house method calc 
         *
         * @param houseHolder the houseHolder class to show thes result
         * @return void - this method does not return any value, just prints the result.
         */
        void visit(const HouseHolderMethod& houseHolder);

        /**
         * This method is used to show the result of a jacobi method calc 
         *
         * @param jacobi the jacobi class to show thes result
         * @return void - this method does not return any value, just prints the result.
         */
        void visit(const JacobiMethod& jacobi);

        void visit(const QRMethod& qr);

        void visit(const IPV& ipv);

        void visit(const IntegralGauss& integral);

        void teste();
};