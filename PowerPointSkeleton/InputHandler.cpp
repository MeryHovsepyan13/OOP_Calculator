#include "InputHandler.hpp"

std::istream& InputHandler::readInput(std::istream& input, std::string& line) {
    std::getline(input, line);
    return input;
}
