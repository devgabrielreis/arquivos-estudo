#include "ScaleMode.hpp"

// #define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <iostream>

ScaleMode::ScaleMode(const std::string& filter, const std::string& folder, float scaleFactor)
    : ResizeMode{ filter, folder }, m_scaleFactor{ scaleFactor }
{
}

const std::string& ScaleMode::getModeName() const
{
    static const std::string ScaleModeName = "[Escalar]: ";
    return ScaleModeName;
}

void ScaleMode::logParameters()
{
    std::cout << getModeName() << "Modo   : Escalar" << std::endl;
    std::cout << getModeName() << "Pasta  : " << getFolder() << std::endl;
    std::cout << getModeName() << "Filtro : " << getFilter() << std::endl;
    std::cout << getModeName() << "Fator  : " << m_scaleFactor << std::endl;
}

void ScaleMode::runImpl()
{
    for (const std::filesystem::path& filepath : getFiles())
    {
        std::cout << getModeName() << "Escalando " << filepath << std::endl;

        int width = 0;
        int height = 0;
        int numComp = 0;

        stbi_info(filepath.string().c_str(), &width, &height, &numComp);

        const int newWidth = static_cast<int>(width * m_scaleFactor);
        const int newHeight = static_cast<int>(height * m_scaleFactor);

        resizeImage(filepath, newWidth, newHeight);
    }
}

std::unique_ptr<ScaleMode> createScaleMode(const ArgumentParser& argParser)
{
    float amount = 0.0f;

    try
    {
        amount = argParser.getOptionAs<float>(args::opts::amount);
    }
    catch (const std::invalid_argument&)
    {
        throw std::invalid_argument("O valor informado para Amount não é um número válido");
    }

    if (amount <= 0.0f)
    {
        throw std::invalid_argument("Amount deve ser maior do que zero");
    }

    const std::string folder = argParser.getOptionAs<std::string>(args::opts::folder);
    const std::string filter = argParser.getOptionAs<std::string>(args::opts::filter);

    if (filter.empty())
    {
        throw std::invalid_argument("O Filter não pode estar vazio no modo Scale");
    }

    return std::make_unique<ScaleMode>(filter, folder, amount);
}
