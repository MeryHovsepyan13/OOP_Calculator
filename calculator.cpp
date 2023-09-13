#include "calculator.hpp"
#include <cmath>
#include <stdexcept> 

double Calculator::add(double operand1, double operand2) {
    return operand1 + operand2;
}

double Calculator::subtract(double operand1, double operand2) {
    return operand1 - operand2;
}

double Calculator::multiply(double operand1, double operand2) {
    return operand1 * operand2;
}

double Calculator::divide(double operand1, double operand2) {
    if (operand2 == 0) {
        throw std::runtime_error("Division by zero is not allowed");
    }
    return operand1 / operand2;
}

double Calculator::pow(double operand1, double operand2) {
    return std::pow(operand1, operand2);
}

double Calculator::mod(double operand1, double operand2) {
    if (operand2 == 0) {
        throw std::invalid_argument("Modulo by zero is not allowed");
    }
    return std::fmod(operand1, operand2);
}

double Calculator::sqrt(double operand) {
    if (operand < 0) {
        throw std::invalid_argument("Square root of a negative number is not allowed");
    }
    return std::sqrt(operand);
}

int Calculator::bitwise_and(int operand1, int operand2) {
    return operand1 & operand2;
}

int Calculator::bitwise_or(int operand1, int operand2) {
    return operand1 | operand2;
}

int Calculator::bitwise_xor(int operand1, int operand2) {
    return operand1 ^ operand2;
}

int Calculator::bitwise_xnor(int operand1, int operand2) {
    return ~(operand1 ^ operand2);
}

int Calculator::bitwise_not(int operand) {
    return ~operand;
}