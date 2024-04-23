#include <cmath>
#include <iostream>

// Function pointer type that accepts a double and returns a double
using Function = double (*)(double);
using NewtonCotesMethod = double (*)(double, double, Function);

// Function to be integrated
double f(double x) {
    return x * 2 + 3;
}

// Function to be integrated
double g(double x) {
    return pow(x, 2) + 6 * x - 1;
}

double nc_trapezium_method(double a, double b, Function f) {
    return std::abs((a - b)) / 2 * (f(a) + f(b));
}

double nc_simpson_method(double a, double b, Function f) {
    double h = abs((a - b)) / 2;
    return h / 3 * (f(a) + 4 * f(a + h) + f(b));
}

double nc_simpson2_method(double a, double b, Function f) {
    double h = abs((a - b)) / 2;
    return h / 3 * (f(a) + 4 * f(a + h) + f(b));
}

// Updated newton_cotes to accept a function pointer and correctly implement trapezoidal rule
double newton_cotes(double a, double b, int n_partitions, Function func, NewtonCotesMethod method) {
    double integral = 0;
    double partition_size = (b - a) / n_partitions;
    for (int i = 0; i < n_partitions; i++) {
        double x_start = a + i * partition_size;
        double x_end = x_start + partition_size;
        integral += method(x_start, x_end, func);
    }
    return integral;
}

// Example usage
int main() {
    double a = 0;  // Start of interval
    double b = 5; // End of interval
    int n_partitions = 1; // Number of partitions

    // Call newton_cotes with the function 'f' as an argument
    double result = newton_cotes(a, b, n_partitions, f, nc_simpson_method);
    std::cout << "The integral of the function is: " << result << std::endl;
    result = newton_cotes(a, b, n_partitions, g, nc_simpson_method);
    std::cout << "The integral of the function is: " << result << std::endl;
    return 0;
}
