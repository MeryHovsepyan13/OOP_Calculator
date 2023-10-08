#include "SaveExecutor.hpp"
#include <iostream>
#include <fstream>


SaveExecutor::SaveExecutor(const std::string& filePath, const std::map<int, std::string>& itemsMap)
    : filePath(filePath), itemsMap(itemsMap) {}

void SaveExecutor::execute() {
    std::ofstream outputFile(filePath);

    if (!outputFile.is_open()) {
        std::cerr << "Unable to open file for saving." << std::endl;
        return;
    }

    for (const auto& entry : itemsMap) {
        outputFile << entry.first << " " << entry.second << std::endl;
    }

    std::cout << "Content saved to file: " << filePath << std::endl;

    outputFile.close();
}
