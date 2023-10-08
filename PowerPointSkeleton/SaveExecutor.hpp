#ifndef SAVEEXECUTOR_HPP
#define SAVEEXECUTOR_HPP

#include <string>
#include <map>

class SaveExecutor {
public:
    SaveExecutor(const std::string& filePath, const std::map<int, std::string>& itemsMap);

    void execute();

private:
    std::string filePath;
    const std::map<int, std::string>& itemsMap;
};

#endif 
