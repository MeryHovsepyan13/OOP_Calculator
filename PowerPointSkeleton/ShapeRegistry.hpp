#ifndef SHAPEREGISTRY_HPP
#define SHAPEREGISTRY_HPP

#include <string>
#include <vector>

using ShapeType = std::string;

class ShapeRegistry {
public:
    ShapeRegistry();
    bool isValidShape(const std::string& shapeName);

private:
    std::vector<ShapeType> ValidShapes;
};



#endif 
