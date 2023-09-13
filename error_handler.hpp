#pragma once
#include <stdexcept>

class ErrorHandler {
public:
    static void handle_error(const std::string& message);
    static void handle_zero_division();
    static void handle_modulo_zero();
};