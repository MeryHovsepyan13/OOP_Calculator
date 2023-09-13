#include "input_processor.hpp"
#include <sstream>
#include <stdexcept>

InputProcessor::InputProcessor() {}

std::vector<std::string> InputProcessor::splitString(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(input);
    std::string token;

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

std::tuple<std::string, std::vector<double>> InputProcessor::processInput(const std::string& input_line) {
    std::vector<std::string> tokens = splitString(input_line, ' ');

    if (tokens.empty()) {
        throw std::invalid_argument("Invalid input format.");
    }

    std::string operation = tokens[0];

    if (tokens.size() < 2) {
        throw std::invalid_argument("Insufficient operands.");
    }

    std::vector<double> operands;
    bool isOpKeyword = false;

    if (operation == "SQRT" || operation == "NOT") {
        if (tokens.size() != 3 || tokens[1] != "-op") {
            throw std::invalid_argument("Invalid input format for " + operation + " operation.");
        }
        isOpKeyword = true;
    } else if (operation == "ADD" || operation == "SUB" || operation == "MUL" ||
               operation == "DIV" || operation == "POW" || operation == "MOD" ||
               operation == "AND" || operation == "OR" || operation == "XOR") {
        if (tokens[1] != "-ops") {
            throw std::invalid_argument("Invalid input format for " + operation + " operation. Use '-ops'.");
        }
    } else {
        throw std::invalid_argument("Unsupported operation: " + operation);
    }

    for (size_t i = 2; i < tokens.size(); ++i) {
        double operand;
        try {
            operand = std::stod(tokens[i]);
        } catch (const std::exception& e) {
            throw std::invalid_argument("Invalid operand: " + tokens[i]);
        }

        operands.push_back(operand);
    }

    if ((!isOpKeyword && operands.empty()) || (isOpKeyword && operands.size() != 1)) {
        throw std::invalid_argument("Invalid input format for " + operation + " operation.");
    }

    return std::make_tuple(operation, operands);
}
