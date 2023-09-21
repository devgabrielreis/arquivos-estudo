#pragma once

#include "Mode.hpp"
#include "ArgumentParser.hpp"

#include <memory>

class ConvertMode final : public Mode
{
    public:
        enum class Format
        {
            JPG,
            PNG
        };

        ConvertMode(const std::string& filter, const std::string& folder, Format fromFormat, Format toFormat);

        const std::string& getModeName() const override;

    protected:
        void logParameters() override;

        void runImpl() override;

    private:
        Format m_fromFormat;
        Format m_toFormat;
};

std::unique_ptr<ConvertMode> createConvertMode(const ArgumentParser& argParser);
