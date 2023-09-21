#include "ResizeMode.hpp"

// #define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
// #define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include <stb_image_resize.h>

#include <iostream>
#include <vector>

ResizeMode::ResizeMode(const std::string& filter, const std::string& folder, int width, int height)
    : Mode{ filter, folder }, m_width{ width }, m_height{ height }
{
}

const std::string& ResizeMode::getModeName() const
{
    static const std::string resizeModeName = "[Redimensionar]: ";
    return resizeModeName;
}

void ResizeMode::resizeImage(const std::filesystem::path& filepath, int newWidth, int newHeight) const
{
    int inputWidth = 0;
    int inputHeight = 0;
    int inputNumComp = 0;
    const int numCompReq = 4;

    if (unsigned char* inputData = stbi_load(filepath.string().c_str(), &inputWidth, &inputHeight, &inputNumComp, numCompReq))
    {
        const int numOutputPixels = newWidth * newHeight * numCompReq;
        std::vector<std::uint8_t> outputData(numOutputPixels, 0);

        const int resizeResult = stbir_resize_uint8(inputData, inputWidth, inputHeight, 0,
                                                    outputData.data(), newWidth, newHeight, 0,
                                                    numCompReq);

        if (resizeResult == 1)
        {
            int writeResult = 1;
            const std::filesystem::path extension = filepath.extension();

            if (extension == ".jpg")
            {
                writeResult = stbi_write_jpg(filepath.string().c_str(), newWidth, newHeight, numCompReq, outputData.data(), 50);
            }
            else if (extension == ".png")
            {
                writeResult = stbi_write_png(filepath.string().c_str(), newWidth, newHeight, numCompReq, outputData.data(), 0);
            }
            else
            {
                std::cout << getModeName() << "Formato não suportado " << filepath << std::endl;
            }

            if (writeResult == 0)
            {
                std::cout << getModeName() << "Erro ao escrever " << filepath << std::endl;
            }
        }
        else
        {
            std::cout << getModeName() << "Erro ao redimensionar " << filepath << std::endl;
        }

        stbi_image_free(inputData);
    }
    else
    {
        std::cout << getModeName() << "Erro ao carregar " << filepath << std::endl;
    }
}

void ResizeMode::logParameters()
{
    std::cout << getModeName() << "Modo    : Redimensionar" << std::endl;
    std::cout << getModeName() << "Pasta   : " << getFolder() << std::endl;
    std::cout << getModeName() << "Filtro  : " << getFilter() << std::endl;
    std::cout << getModeName() << "Largura : " << m_width << std::endl;
    std::cout << getModeName() << "Altura  : " << m_height << std::endl;
}

void ResizeMode::runImpl()
{
    if (m_width > 0 && m_height > 0)
    {
        for (const std::filesystem::path& filepath : getFiles())
        {
            std::cout << getModeName() << "Redimensionando " << filepath << std::endl;
            resizeImage(filepath, m_width, m_height);
        }
    }
}

std::unique_ptr<ResizeMode> createResizeMode(const ArgumentParser& argParser)
{
    int width = 0;
    int height = 0;

    try
    {
        width = argParser.getOptionAs<int>(args::opts::width);
        height = argParser.getOptionAs<int>(args::opts::height);
    }
    catch (const std::invalid_argument&)
    {
        throw std::invalid_argument("O valor informado para Width ou Height não é um número válido");
    }

    if (width <= 0 || height <= 0)
    {
        throw std::invalid_argument("Width e Height devem ser maiores que zero");
    }

    const std::string folder = argParser.getOptionAs<std::string>(args::opts::folder);
    const std::string filter = argParser.getOptionAs<std::string>(args::opts::filter);

    if (filter.empty())
    {
        throw std::invalid_argument("O Filter não pode estar vazio no modo Resize");
    }

    return std::make_unique<ResizeMode>(filter, folder, width, height);
}