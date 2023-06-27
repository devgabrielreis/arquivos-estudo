#pragma once

#include <string>
#include <map>

class ArgumentParser
{
    public:
        void registerFlag(const std::string& flag);

        void registerOption(const std::string& option);

        bool isFlagRegistered(const std::string& flag) const;

        bool isOptionRegistered(const std::string& option) const;

        bool getFlag(const std::string& flag) const;

        // std::string getOptionAs(const std::string& option) const;
        // float getOptionAs(const std::string& option) const;
        // int getOptionAs(const std::string& option) const;
        template<typename T>
        T getOptionAs(const std::string& option) const;

        void parse(int argc, char const *argv[]);

    private:
        std::map<std::string, bool> m_flags;
        std::map<std::string, std::string> m_options;

        const std::string& getOption(const std::string& option) const;

        float getOptionAsFloat(const std::string& option) const;

        int getOptionAsInt(const std::string& option) const;
};
