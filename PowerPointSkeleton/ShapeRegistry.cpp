#include "ShapeRegistry.hpp"

ShapeRegistry::ShapeRegistry() :
    ValidShapes{ "rectangle", "line", "circle", "trapezoid", "ellipse" } {}

bool ShapeRegistry::isValidShape(const std::string& shapeName) {
    for (const auto& cmd : ValidShapes) {
        if (shapeName == cmd) {
            return true;
        }
    }
    return false;
}
