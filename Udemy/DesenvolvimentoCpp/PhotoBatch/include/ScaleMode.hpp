#pragma once

#include "ResizeMode.hpp"
#include "ArgumentParser.hpp"

#include <memory>

class ScaleMode final : public ResizeMode
{
    public:
        ScaleMode(const std::string& filter, const std::string& folder, float scaleFactor);

        const std::string& getModeName() const override;
    
    protected:
        void logParameters() override;

        void runImpl() override;

    private:
        float m_scaleFactor;
};

std::unique_ptr<ScaleMode> createScaleMode(const ArgumentParser& argParser);
