#include "calculator.hpp"
#include "calculator_handler.hpp"
#include "input_processor.hpp"
#include "help_handler.hpp"
#include "error_handler.hpp"
#include "input_handler.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
    Calculator calculator;
    CalculatorHandler calculatorHandler(calculator);
    InputProcessor inputProcessor;

    while (true) {
        std::string input_line;
        std::cout << "Enter an arithmetic operation and operands (e.g., MUL -ops 3 5), or type 'HELP' for a list of operations, or 'STOP' to quit: ";
        std::getline(std::cin, input_line);

        if (input_line == "STOP") {
            break;
        } else if (input_line == "HELP") {
            HelpHandler::display_help();
            continue;
        }

        try {
            std::string operation;
            std::vector<double> operands;

            std::tie(operation, operands) = inputProcessor.processInput(input_line);

            double result = calculatorHandler.performCalculation(operation, operands);

            std::cout << "Result: " << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
