#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

#include "CommandRegistry.hpp"

class Parser {
public:
    Parser(const std::string& input, CommandRegistry& registry);

    std::string getCommand() const;
    std::vector<std::string> getArguments() const;
    std::string getRestOfTheLine() const;
    bool isValidCommand() const;

    void parse();

private:
    std::string input;
    CommandRegistry& registry;
    std::string command;  
    std::vector<std::string> arguments;  
    std::string restOfTheLine;  
    bool validCommand;  
};

#endif 
