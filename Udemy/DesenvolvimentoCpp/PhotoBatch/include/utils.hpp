#pragma once

#include <string>

namespace utils
{
    std::string toLower(std::string str);

    const std::string& getInvalidCharacters();

    bool hasInvalidCharacters(const std::string& str);
}
