#include "AddExecutor.hpp"
#include "ChangeExecutor.hpp"
#include "Controller.hpp"
#include "DisplayExecutor.hpp"
#include "LoadExecutor.hpp"
#include "Parser.hpp"
#include "QuitExecutor.hpp"
#include "RemoveExecutor.hpp"
#include "SaveExecutor.hpp"
#include "ShapeRegistry.hpp"

void Controller::handleAdd(const std::string& input) {
    Parser parser(input, registry);
    parser.parse();

    std::vector<std::string> arguments = parser.getArguments();

    if (arguments.size() >= 2) {
        std::string shape = arguments[0];
        std::unordered_set<std::string> attributes(arguments.begin() + 1, arguments.end());

        ShapeRegistry shapeRegistry; 

        if (shapeRegistry.isValidShape(shape) && commandValidator.validateShapeAttributes(shape, attributes)) {
            AddExecutor addExecutor(parser.getRestOfTheLine());
            addExecutor.execute(addedItemsMap);
        }
    }
    else {
        std::cerr << "Invalid arguments for Add command." << std::endl;
    }
}

void Controller::handleDisplay() {
    DisplayExecutor displayExecutor(addedItemsMap);
    displayExecutor.execute();
}

void Controller::handleRemove(const std::string& input) {
    Parser parser(input, registry);
    parser.parse();

    if (parser.getArguments().size() == 1) {
        int indexToRemove;
        try {
            indexToRemove = std::stoi(parser.getArguments()[0]);
            RemoveExecutor removeExecutor(indexToRemove);
            removeExecutor.removeFromMap(addedItemsMap); 
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Invalid index for Remove command." << std::endl;
        }
    }
    else {
        std::cerr << "Invalid arguments for Remove command." << std::endl;
    }
}


void Controller::handleSave(const std::string& input) {
    std::string filePath = input;
    filePath = filePath.substr(filePath.find_first_not_of(" "), filePath.find_last_not_of(" ") + 1);

    SaveExecutor saveExecutor(filePath, addedItemsMap);
    saveExecutor.execute();
}

void Controller::handleQuit() {
    QuitExecutor quitExecutor;
    quitExecutor.execute();
}

void Controller::handleChange(const std::string& input) {
    Parser parser(input, registry);
    parser.parse();

    if (parser.getArguments().size() >= 2) {
        int indexToChange;
        try {
            indexToChange = std::stoi(parser.getArguments()[0]);
            std::string newArguments = parser.getRestOfTheLine();
            ChangeExecutor changeExecutor(indexToChange, newArguments);
            changeExecutor.execute(addedItemsMap);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Invalid index for Change command." << std::endl;
        }
    }
    else {
        std::cerr << "Invalid arguments for Change command." << std::endl;
    }
}

void Controller::handleLoad() {
    LoadExecutor loadExecutor(addedItemsMap);
    loadExecutor.execute();
}

void Controller::run() {
    while (true) {
        std::cout << "Enter a command: ";
        std::getline(std::cin, userInput);

        Parser parser(userInput, registry);
        parser.parse();

        if (parser.isValidCommand()) {
            std::cout << "Valid command: " << parser.getCommand() << std::endl;

            if (parser.getCommand() == "Add") {
                handleAdd(parser.getRestOfTheLine());
            }
            else if (parser.getCommand() == "Display") {
                handleDisplay();
            }
            else if (parser.getCommand() == "Quit") {
                handleQuit();
            }
            else if (parser.getCommand() == "Remove") {
                handleRemove(parser.getRestOfTheLine());
            }
            else if (parser.getCommand() == "Save") {
                handleSave(parser.getRestOfTheLine());
            }
            else if (parser.getCommand() == "Change") {
                handleChange(parser.getRestOfTheLine());
            }
            else if (parser.getCommand() == "Load") {
                handleLoad();
            }
            else {
                std::cerr << "Invalid command." << std::endl;
            }
        }
    }
}
