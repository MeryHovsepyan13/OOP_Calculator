#ifndef COMMANDREGISTRY_HPP
#define COMMANDREGISTRY_HPP

#include <string>
#include <vector>

class CommandRegistry {
public:
    CommandRegistry();
    bool isValidCommand(const std::string& commandName);

private:
    std::vector<std::string> ValidCommands;
};

#endif 
