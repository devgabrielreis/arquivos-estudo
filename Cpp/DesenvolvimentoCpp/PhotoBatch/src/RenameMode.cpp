#include "RenameMode.hpp"
#include "utils.hpp"

#include <iostream>
#include <filesystem>
#include <vector>

RenameMode::RenameMode(const std::string& filter, const std::string& folder, const std::string& prefix, int startNumber)
    : Mode { filter, folder } , m_prefix{ prefix }, m_startNumber{ startNumber }
{
}

const std::string& RenameMode::getModeName() const
{
    static const std::string renameModeName = "[Renomear]: ";
    return renameModeName;
}

void RenameMode::logParameters()
{
    std::cout << getModeName() << "Modo           : Renomear" << std::endl;
    std::cout << getModeName() << "Pasta          : " << getFolder() << std::endl;
    std::cout << getModeName() << "Filtro         : " << getFilter() << std::endl;
    std::cout << getModeName() << "Prefixo        : " << m_prefix << std::endl;
    std::cout << getModeName() << "Numero inicial : " << m_startNumber << std::endl;
}

void RenameMode::runImpl()
{
    int currentNumber = m_startNumber;
    for (const std::filesystem::path& filepath : getFiles())
    {
        const std::filesystem::path extension = filepath.extension();
        const std::string newFileName = m_prefix + std::to_string(currentNumber) + extension.string();

        std::filesystem::path newFilepath = filepath;
        newFilepath.replace_filename(newFileName);

        try
        {
            if (std::filesystem::exists(newFilepath))
            {
                throw std::invalid_argument("\"" + newFilepath.string() + "\" já existe");
            }
            std::filesystem::rename(filepath, newFilepath);

            std::cout << getModeName() << filepath << " -> " << newFilepath << std::endl;
        }
        catch (const std::exception& exception)
        {
            std::cout << getModeName() << "Erro ao renomear \"" << filepath << "\": " << exception.what() << std::endl;
        }

        currentNumber++;
    }
}

std::unique_ptr<RenameMode> createRenameMode(const ArgumentParser& argParser)
{
    int startNumber = -1;

    try
    {
        startNumber = argParser.getOptionAs<int>(args::opts::startNumber);
    }
    catch (const std::invalid_argument&)
    {
        throw std::invalid_argument("O valor informado para StartNumber não é um número válido");
    }

    if (startNumber < 0)
    {
        throw std::invalid_argument("StartNumber deve ser igual ou maior do que zero");
    }

    std::string prefix = argParser.getOptionAs<std::string>(args::opts::prefix);

    if (prefix.empty() || utils::hasInvalidCharacters(prefix))
    {
        throw std::invalid_argument("Prefix não pode estar vazio ou conter os caracteres " + utils::getInvalidCharacters());
    }

    const std::string folder = argParser.getOptionAs<std::string>(args::opts::folder);
    const std::string filter = argParser.getOptionAs<std::string>(args::opts::filter);

    return std::make_unique<RenameMode>(filter, folder, prefix, startNumber);
}
