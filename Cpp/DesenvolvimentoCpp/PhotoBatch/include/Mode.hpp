#pragma once

#include <string>
#include <memory>
#include <filesystem>
#include <vector>

#include "ArgumentParser.hpp"

class Mode
{
    public:
        Mode(const std::string& filter, const std::string& folder);

        const std::string& getFolder() const;

        const std::string& getFilter() const;

        virtual const std::string& getModeName() const = 0;

        void run();

    protected:
        virtual void logParameters() = 0;

        virtual void runImpl() = 0;

        std::vector<std::filesystem::path> getFiles(const std::filesystem::path& extension = "") const;

    private:
        std::string m_Filter;
        std::string m_Folder;

};

void validateBaseMode(const ArgumentParser& argParser);

namespace args
{
    namespace flags
    {
        static constexpr const char* rename = "rename";
        static constexpr const char* convert = "convert";
        static constexpr const char* resize = "resize";
        static constexpr const char* scale = "scale";
    }

    namespace opts
    {
        static constexpr const char* folder = "folder";
        static constexpr const char* filter = "filter";
        static constexpr const char* width = "width";
        static constexpr const char* height = "height";
        static constexpr const char* amount = "amount";
        static constexpr const char* prefix = "prefix";
        static constexpr const char* startNumber = "startnumber";
        static constexpr const char* from = "from";
        static constexpr const char* to = "to";
    }
}
