#pragma once

class Calculator {
public:
    double add(double operand1, double operand2);
    double subtract(double operand1, double operand2);
    double multiply(double operand1, double operand2);
    double divide(double operand1, double operand2);
    double pow(double operand1, double operand2);
    double mod(double operand1, double operand2);
    double sqrt(double operand);
    int bitwise_and(int operand1, int operand2);
    int bitwise_or(int operand1, int operand2);
    int bitwise_xor(int operand1, int operand2);
    int bitwise_xnor(int operand1, int operand2);
    int bitwise_not(int operand);
};