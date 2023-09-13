#include "error_handler.hpp"

void ErrorHandler::handle_error(const std::string& message) {
    throw std::runtime_error(message);
}

void ErrorHandler::handle_zero_division() {
    throw std::runtime_error("Division by zero is not allowed");
}

void ErrorHandler::handle_modulo_zero() {
    throw std::invalid_argument("Modulo by zero is not allowed");
}