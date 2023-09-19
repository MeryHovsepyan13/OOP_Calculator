#include "calculator.hpp"
#include "calculator_handler.hpp"
#include "input_processor.hpp"
#include "help_handler.hpp"
#include "error_handler.hpp"
#include "input_handler.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>

int main() {
    Calculator calculator;
    CalculatorHandler calculatorHandler(calculator);
    InputProcessor inputProcessor;
    std::unordered_map<std::string, std::vector<double>> calculations; 
    std::deque<std::string> executionOrder; 

    while (true) {
        std::string input_line;
        std::cout << "Enter an arithmetic operation or 'HELP' for a list of operations, 'RUN' to execute, or 'STOP' to quit: ";
        std::getline(std::cin, input_line);

        if (input_line == "STOP") {
            break;
        } else if (input_line == "HELP") {
            HelpHandler::display_help();
            continue;
        } else if (input_line == "RUN") {
            for (const std::string& operation : executionOrder) {
                try {
                    double result = calculatorHandler.performCalculation(operation, calculations[operation]);
                    std::cout << "Result for '" << operation << "': " << result << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            }
            calculations.clear(); 
            executionOrder.clear(); 
            continue;
        }

        if (input_line.find("CREATE") == 0) {
            std::string createInput = input_line.substr(7); 
            try {
                std::string operation;
                std::vector<double> operands;

                std::tie(operation, operands) = inputProcessor.processInput(createInput);
                
                calculations[operation] = operands;
                executionOrder.push_back(operation);
                std::cout << "Calculation '" << operation << "' created and added to the queue." << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error creating calculation: " << e.what() << std::endl;
            }
        } else {
            std::cerr << "Invalid input. Please use 'CREATE' to define calculations or 'RUN' to execute." << std::endl;
        }
    }

    return 0;
}
