#pragma once
#include <string>
#include <vector>
#include <tuple>

class InputProcessor {
public:
    InputProcessor();
    std::tuple<std::string, std::vector<double>> processInput(const std::string& input_line);

private:
    std::vector<std::string> splitString(const std::string& input, char delimiter);
};
