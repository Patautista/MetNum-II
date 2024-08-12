#pragma once
#include <memory>
#include "../numerical_method/numerical_method.hpp"
using namespace std;

class Context {
    public:
        unique_ptr<NumericalMethod> nmInstance_;   

        void set_strategy(std::unique_ptr<NumericalMethod> &&strategy);

        void callExecute();
};