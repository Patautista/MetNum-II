#include "../../include/context_class/context.hpp"



void Context::set_strategy(std::unique_ptr<NumericalMethod> &&strategy)
{
    nmInstance_ = std::move(strategy);
}

void Context::callExecute() 
{
    this->nmInstance_->execute();
}