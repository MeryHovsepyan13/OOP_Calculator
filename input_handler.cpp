#include "input_handler.hpp"
#include <iostream>
#include <sstream>

std::tuple<std::string, double, double> InputHandler::parse_input(const std::string& input_line) {
    std::istringstream iss(input_line);
    std::string operation;
    double operand1, operand2;
    iss >> operation;

    if (operation == "SQRT" || operation == "NOT") {
        iss >> operand1;
        return std::make_tuple(operation, operand1, 0.0);
    } else {
        iss >> operand1 >> operand2;
        return std::make_tuple(operation, operand1, operand2);
    }
}