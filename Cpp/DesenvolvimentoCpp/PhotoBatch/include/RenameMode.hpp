#pragma once

#include "Mode.hpp"
#include "ArgumentParser.hpp"

#include <memory>

class RenameMode final : public Mode
{
    public:
        RenameMode(const std::string& filter, const std::string& folder, const std::string& prefix, int startNumber);

        const std::string& getModeName() const override;

    protected:
        void logParameters() override;

        void runImpl() override;

    private:
        std::string m_prefix;
        int m_startNumber;
};

std::unique_ptr<RenameMode> createRenameMode(const ArgumentParser& argParser);
