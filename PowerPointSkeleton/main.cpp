#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <unordered_set>
#include <vector>

#include "AddExecutor.hpp"
#include "ChangeExecutor.hpp"
#include "CommandRegistry.hpp"
#include "Validator.hpp"
#include "Controller.hpp"
#include "DisplayExecutor.hpp"
#include "InputHandler.hpp"
#include "LoadExecutor.hpp"
#include "Parser.hpp"
#include "QuitExecutor.hpp"
#include "RemoveExecutor.hpp"
#include "SaveExecutor.hpp"
#include "ShapeRegistry.hpp"
#include "Tokenizer.hpp"




int main() {
    Controller obj;
    obj.run();
    return 0;
}
