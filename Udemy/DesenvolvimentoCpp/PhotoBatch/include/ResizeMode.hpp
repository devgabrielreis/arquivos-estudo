#pragma once

#include "Mode.hpp"
#include "ArgumentParser.hpp"

#include <memory>

class ResizeMode : public Mode
{
    public:
        ResizeMode(const std::string& filter, const std::string& folder, int width = -1, int height = -1);

        const std::string& getModeName() const override;

    protected:
        void logParameters() override;

        void runImpl() override;

        void resizeImage(const std::filesystem::path& filepath, int newWidth, int newHeight) const;
    
    private:
        int m_width;
        int m_height;
};

std::unique_ptr<ResizeMode> createResizeMode(const ArgumentParser& argParser);
