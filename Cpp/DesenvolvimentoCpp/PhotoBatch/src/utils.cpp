#include <algorithm>

#include "utils.hpp"

namespace utils
{
    std::string toLower(std::string str)
    {
        std::transform(
            std::begin(str),
            std::end(str),
            std::begin(str),
            [](unsigned char c) { return std::tolower(c); }
        );

        return str;
    }

    const std::string& getInvalidCharacters()
    {
        static const std::string invalidCharacters = "\\/?\"<>|:";
        return invalidCharacters;
    }

    bool hasInvalidCharacters(const std::string& str)
    {
        bool hasInvalidChars = str.find_first_of(getInvalidCharacters()) != std::string::npos;
        return hasInvalidChars;
    }
}
