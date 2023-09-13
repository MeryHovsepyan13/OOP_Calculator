#pragma once
#include "calculator.hpp"
#include <string>
#include <vector>

class CalculatorHandler {
public:
    CalculatorHandler(Calculator& calc);
    double performCalculation(const std::string& operation, const std::vector<double>& operands);

private:
    Calculator& calculator;
};
