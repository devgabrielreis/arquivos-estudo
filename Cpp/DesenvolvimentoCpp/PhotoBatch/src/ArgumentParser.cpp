#include "ArgumentParser.hpp"
#include "utils.hpp"

void ArgumentParser::registerFlag(const std::string& flag)
{
    if (!flag.empty())
    {
        m_flags[flag] = false;
    }
}

void ArgumentParser::registerOption(const std::string& option)
{
    if (!option.empty())
    {
        m_options[option] = "";
    }
}

bool ArgumentParser::isFlagRegistered(const std::string& flag) const
{
    if (!flag.empty())
    {
        return m_flags.count(flag) == 1;
    }

    return false;
}

bool ArgumentParser::isOptionRegistered(const std::string& option) const
{
    if (!option.empty())
    {
        return m_options.count(option) == 1;
    }

    return false;
}


bool ArgumentParser::getFlag(const std::string& flag) const
{
    if (!flag.empty())
    {
        auto flagIt = m_flags.find(flag);
        
        if (flagIt != std::end(m_flags))
        {
            return flagIt->second;
        }
    }

    return false;
}

template<>
std::string ArgumentParser::getOptionAs(const std::string& option) const
{
    return getOption(option);
}

template<>
float ArgumentParser::getOptionAs(const std::string& option) const
{
    return getOptionAsFloat(option);
}

template<>
int ArgumentParser::getOptionAs(const std::string& option) const
{
    return getOptionAsInt(option);
}

const std::string& ArgumentParser::getOption(const std::string& option) const
{
    if (!option.empty())
    {
        auto optionIt = m_options.find(option);

        if (optionIt != std::end(m_options))
        {
            return optionIt->second;
        }
    }

    static std::string emptyOption = "";
    return emptyOption;
}

float ArgumentParser::getOptionAsFloat(const std::string& option) const
{
    const std::string& optionValue = getOption(option);

    if (!optionValue.empty())
    {
        return std::stof(optionValue);
    }

    return -1;
}

int ArgumentParser::getOptionAsInt(const std::string& option) const
{
    const std::string& optionValue = getOption(option);

    if (!optionValue.empty())
    {
        return std::stoi(optionValue);
    }

    return -1;
}

void ArgumentParser::parse(int argc, char const *argv[])
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            std::string arg = utils::toLower(argv[i]);

            if (arg.length() >= 3)
            {
                if (arg[0] == '-' && arg[1] == '-')
                {
                    arg = arg.substr(2);

                    if (arg.find_first_of('=') != std::string::npos)
                    {
                        const size_t equalSignPos = arg.find('=');

                        if (equalSignPos != std::string::npos)
                        {
                            std::string optionName = arg.substr(0, equalSignPos);
                            std::string optionValue = arg.substr(equalSignPos + 1);

                            auto optionIt = m_options.find(optionName);

                            if (optionIt != std::end(m_options))
                            {
                                optionIt->second = optionValue;
                            }
                        }
                    }
                    else
                    {
                        auto flagIt = m_flags.find(arg);

                        if (flagIt != std::end(m_flags))
                        {
                            flagIt->second = true;
                        }
                    }
                }
            }
        }
    }
}
