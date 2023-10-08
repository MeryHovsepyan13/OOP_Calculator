#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <iostream>
#include <vector>
#include <map>

#include "CommandRegistry.hpp"
#include "Validator.hpp"

class Controller {
public:
    void run();

public:
    void handleAdd(const std::string& input);
    void handleDisplay();
    void handleRemove(const std::string& input);
    void handleSave(const std::string& input);
    void handleQuit();
    void handleChange(const std::string& input);
    void handleLoad();

private:
    CommandRegistry registry;
    std::string userInput;
    std::map<int, std::string> addedItemsMap;
    CommandValidator commandValidator;
};

#endif 
