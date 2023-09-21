#include "ConvertMode.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <iostream>

std::string toString(ConvertMode::Format format)
{
    switch(format)
    {
        case ConvertMode::Format::JPG:
            return "jpg";
        case ConvertMode::Format::PNG:
            return "png";
        default:
            break;
    }

    return "invalid format";
}

std::ostream& operator<< (std::ostream& out, ConvertMode::Format format)
{
    out << toString(format);

    return out;
}

ConvertMode::ConvertMode(const std::string& filter, const std::string& folder, Format fromFormat, Format toFormat)
    : Mode{ filter, folder }, m_fromFormat{ fromFormat }, m_toFormat{ toFormat }
{
}

const std::string& ConvertMode::getModeName() const
{
    static const std::string convertModeName = "[Converter]: ";
    return convertModeName;
}

void ConvertMode::logParameters()
{
    std::cout << getModeName() << "Modo    : Converter" << std::endl;
    std::cout << getModeName() << "Pasta   : " << getFolder() << std::endl;
    std::cout << getModeName() << "Filtro  : " << getFilter() << std::endl;
    std::cout << getModeName() << "Origem  : " << m_fromFormat << std::endl;
    std::cout << getModeName() << "Destino : " << m_toFormat << std::endl;
}

void ConvertMode::runImpl()
{
    const std::filesystem::path fromExtension = '.' + toString(m_fromFormat);

    for(const std::filesystem::path& filepath : getFiles(fromExtension))
    {
        std::cout << getModeName() << "Convertendo " << filepath << std::endl;

        int width = 0;
        int height = 0;
        int numComp = 0;
        const int numReqComp = 3;

        if (unsigned char* data = stbi_load(filepath.string().c_str(), &width, &height, &numComp, numReqComp))
        {
            std::filesystem::path destFilepath = filepath;
            destFilepath.replace_extension(toString(m_toFormat));

            int writeResult = 0;
            switch (m_toFormat)
            {
                case Format::PNG:
                    writeResult = stbi_write_png(destFilepath.string().c_str(), width, height, numComp, data, 0);
                    break;
                case Format::JPG:
                    writeResult = stbi_write_jpg(destFilepath.string().c_str(), width, height, numComp, data, 50);
                    break;
                default:
                    break;
            }

            if (writeResult == 0)
            {
                std::cout << getModeName() << "Erro ao converter " << filepath << std::endl;
            }

            stbi_image_free(data);
        }
        else
        {
            std::cout << getModeName() << "Erro ao carregar " << filepath << std::endl;
        }
    }
}

std::unique_ptr<ConvertMode> createConvertMode(const ArgumentParser& argParser)
{
    const std::string from = argParser.getOptionAs<std::string>(args::opts::from);
    const std::string to = argParser.getOptionAs<std::string>(args::opts::to);
    const std::array<std::string, 2> convertOptions = { "jpg", "png" };

    if (from.empty() || to.empty())
    {
        throw std::invalid_argument("To e From não poder estar vazios no modo Convert");
    }

    const bool isFromValid = std::find(std::begin(convertOptions), std::end(convertOptions), from) != std::end(convertOptions);
    const bool isToValid = std::find(std::begin(convertOptions), std::end(convertOptions), to) != std::end(convertOptions);

    if (!isFromValid || !isToValid)
    {
        throw std::invalid_argument("From e To devem ser jpg ou png");
    }

    if (from == to)
    {
        throw std::invalid_argument("From e To devem ser diferentes");
    }

    const std::map<std::string, ConvertMode::Format> convertFormats = {
        { "jpg", ConvertMode::Format::JPG },
        { "png", ConvertMode::Format::PNG }
    };

    const std::string folder = argParser.getOptionAs<std::string>(args::opts::folder);
    const std::string filter = argParser.getOptionAs<std::string>(args::opts::filter);

    return std::make_unique<ConvertMode>(filter, folder, convertFormats.at(from), convertFormats.at(to));
}
