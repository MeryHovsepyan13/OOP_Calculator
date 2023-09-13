#include "help_handler.hpp"

void HelpHandler::display_help() {
    std::cout << "Available operations:" << std::endl;
    std::cout << "ADD -ops <operands> : Addition" << std::endl;
    std::cout << "SUB -ops <operands> : Subtraction" << std::endl;
    std::cout << "MUL -ops <operands> : Multiplication" << std::endl;
    std::cout << "DIV -ops <operands> : Division" << std::endl;
    std::cout << "POW -ops <operands> : Exponentiation" << std::endl;
    std::cout << "MOD -ops <operands> : Modulo" << std::endl;
    std::cout << "SQRT -op <operand> : Square Root" << std::endl;
    std::cout << "NOT -op <operand> : Bitwise NOT" << std::endl;
    std::cout << "AND -ops <operands> : Bitwise AND" << std::endl;
    std::cout << "OR -ops <operands> : Bitwise OR" << std::endl;
    std::cout << "XOR -ops <operands> : Bitwise XOR" << std::endl;
}
