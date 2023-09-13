#include "calculator_handler.hpp"
#include <stdexcept>

CalculatorHandler::CalculatorHandler(Calculator& calc) : calculator(calc) {}

double CalculatorHandler::performCalculation(const std::string& operation, const std::vector<double>& operands) {
    if (operation == "ADD") {
        double result = 0.0;
        for (double operand : operands) {
            result += operand;
        }
        return result;
    } else if (operation == "SUB") {
        if (operands.size() < 2) {
            throw std::invalid_argument("SUB operation requires at least two operands.");
        }
        double result = operands[0];
        for (size_t i = 1; i < operands.size(); ++i) {
            result -= operands[i];
        }
        return result;
    } else if (operation == "MUL") {
        double result = 1.0;
        for (double operand : operands) {
            result *= operand;
        }
        return result;
    } else if (operation == "DIV") {
        if (operands.size() < 2) {
            throw std::invalid_argument("DIV operation requires at least two operands.");
        }
        double result = operands[0];
        for (size_t i = 1; i < operands.size(); ++i) {
            if (operands[i] == 0) {
                throw std::runtime_error("Division by zero is not allowed");
            }
            result /= operands[i];
        }
        return result;
    } else if (operation == "POW") {
        if (operands.size() != 2) {
            throw std::invalid_argument("POW operation requires exactly two operands.");
        }
        return calculator.pow(operands[0], operands[1]);
    } else if (operation == "MOD") {
        if (operands.size() < 2) {
            throw std::invalid_argument("MOD operation requires at least two operands.");
        }
        double result = operands[0];
        for (size_t i = 1; i < operands.size(); ++i) {
            if (operands[i] == 0) {
                throw std::invalid_argument("Modulo by zero is not allowed");
            }
            result = calculator.mod(result, operands[i]);
        }
        return result;
    } else if (operation == "SQRT") {
        if (operands.size() != 1) {
            throw std::invalid_argument("SQRT operation requires exactly one operand.");
        }
        return calculator.sqrt(operands[0]);
    } else if (operation == "NOT") {
        if (operands.size() != 1) {
            throw std::invalid_argument("NOT operation requires exactly one operand.");
        }
        int intOperand = static_cast<int>(operands[0]);
        return calculator.bitwise_not(intOperand);
    } else if (operation == "AND") {
        double result = operands[0];
        for (size_t i = 1; i < operands.size(); ++i) {
            result = static_cast<double>(calculator.bitwise_and(static_cast<int>(result), static_cast<int>(operands[i])));
        }
        return result;
    } else if (operation == "OR") {
        double result = operands[0];
        for (size_t i = 1; i < operands.size(); ++i) {
            result = static_cast<double>(calculator.bitwise_or(static_cast<int>(result), static_cast<int>(operands[i])));
        }
        return result;
    } else if (operation == "XOR") {
        double result = operands[0];
        for (size_t i = 1; i < operands.size(); ++i) {
            result = static_cast<double>(calculator.bitwise_xor(static_cast<int>(result), static_cast<int>(operands[i])));
        }
        return result;
    } else {
        throw std::invalid_argument("Unsupported operation");
    }
}
