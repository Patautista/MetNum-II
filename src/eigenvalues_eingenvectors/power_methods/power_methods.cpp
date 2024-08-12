#include "eigenvalues_eingenvectors/power_methods/power_methods.hpp"

PowerMethods::PowerMethods(Matrix a, Matrix vectorvo, double tolerance) : A{a}, VectorVo{vectorvo}, tolerance{tolerance} {}