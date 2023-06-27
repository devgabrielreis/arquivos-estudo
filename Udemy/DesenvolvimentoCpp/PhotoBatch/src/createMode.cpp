#include "createMode.hpp"
#include "RenameMode.hpp"
#include "ConvertMode.hpp"
#include "ResizeMode.hpp"
#include "ScaleMode.hpp"
#include "utils.hpp"

std::unique_ptr<Mode> createMode(const ArgumentParser& argParser)
{
    const bool renameMode = argParser.getFlag(args::flags::rename);
    const bool convertMode = argParser.getFlag(args::flags::convert);
    const bool resizeMode = argParser.getFlag(args::flags::resize);
    const bool scaleMode = argParser.getFlag(args::flags::scale);

    if (!(renameMode ^ convertMode ^ resizeMode ^ scaleMode))
    {
        throw std::invalid_argument("Somente um modo pode estar ativo");
    }

    validateBaseMode(argParser);

    if (resizeMode)
    {
        return createResizeMode(argParser);
    }
    else if (scaleMode)
    {
        return createScaleMode(argParser);
    }
    else if (renameMode)
    {
        return createRenameMode(argParser);
    }
    else if (convertMode)
    {
        return createConvertMode(argParser);
    }

    return nullptr;
}