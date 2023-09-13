#pragma once
#include <tuple>
#include <string>

class InputHandler {
public:
    static std::tuple<std::string, double, double> parse_input(const std::string& input_line);
};