#include "Mode.hpp"
#include "ArgumentParser.hpp"
#include "RenameMode.hpp"
#include "ConvertMode.hpp"
#include "ResizeMode.hpp"
#include "ScaleMode.hpp"
#include "utils.hpp"

#include <iostream>
#include <filesystem>
#include <array>
#include <chrono>

Mode::Mode(const std::string& filter, const std::string& folder)
    : m_Filter{ filter }, m_Folder{ folder }
{
}

const std::string& Mode::getFolder() const
{
    return m_Folder;
}

const std::string& Mode::getFilter() const
{
    return m_Filter;
}

void Mode::run()
{
    using ClockT = std::chrono::high_resolution_clock;

    ClockT::time_point startTime = ClockT::now();

    logParameters();

    runImpl();

    ClockT::time_point endTime = ClockT::now();

    ClockT::duration elapsedTime = endTime - startTime;
    std::chrono::milliseconds elapsedTimeMs = std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime);

    std::cout << "Operação finalizada em " << elapsedTimeMs.count() << "ms" << std::endl;
}

std::vector<std::filesystem::path> Mode::getFiles(const std::filesystem::path& extension) const
{
    std::vector<std::filesystem::path> files;
    int numSkippedFiles = 0;

    for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(getFolder()))
    {
        const bool isFile = std::filesystem::is_regular_file(entry.path());
        const bool matchFilter = getFilter().empty() || (entry.path().string().find(getFilter()) != std::string::npos);
        const bool matchExtension = extension.empty() || (entry.path().extension() == extension);

        if (isFile && matchFilter && matchExtension)
        {
            files.push_back(entry.path());
        }
        else
        {
            numSkippedFiles++;
        }
    }

    std::cout << getModeName() << "Número de arquivos encontrados: " << files.size() << std::endl;
    std::cout << getModeName() << "Número de arquivos ignorados  : " << numSkippedFiles << std::endl;

    return files;
}

void validateBaseMode(const ArgumentParser& argParser)
{
    const std::string folder = argParser.getOptionAs<std::string>(args::opts::folder);

    if (folder.empty())
    {
        throw std::invalid_argument("A pasta não pode estar em branco");
    }

    if (!std::filesystem::is_directory(folder))
    {
        throw std::invalid_argument("A pasta informada não existe");
    }

    const std::string filter = argParser.getOptionAs<std::string>(args::opts::filter);

    if (!filter.empty() && utils::hasInvalidCharacters(filter))
    {
        throw std::invalid_argument("O filtro não pode conter " + utils::getInvalidCharacters());
    }
}
