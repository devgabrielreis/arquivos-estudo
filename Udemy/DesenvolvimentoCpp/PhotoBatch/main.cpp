#include <iostream>
#include <memory>
#include <exception>

#include "ArgumentParser.hpp"
#include "Mode.hpp"
#include "createMode.hpp"

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "pt_BR");
    setlocale(LC_NUMERIC, "en_US");

    ArgumentParser argParser;

    argParser.registerFlag(args::flags::rename);
    argParser.registerFlag(args::flags::convert);
    argParser.registerFlag(args::flags::resize);
    argParser.registerFlag(args::flags::scale);

    argParser.registerOption(args::opts::folder);
    argParser.registerOption(args::opts::filter);
    argParser.registerOption(args::opts::width);
    argParser.registerOption(args::opts::height);
    argParser.registerOption(args::opts::amount);
    argParser.registerOption(args::opts::prefix);
    argParser.registerOption(args::opts::startNumber);
    argParser.registerOption(args::opts::from);
    argParser.registerOption(args::opts::to);

    argParser.parse(argc, argv);
    
    try
    {
        std::unique_ptr<Mode> photoBatchMode = createMode(argParser);

        if (photoBatchMode != nullptr)
        {
            photoBatchMode->run();
        }
    }
    catch (const std::exception& exception)
    {
        std::cerr << exception.what() << std::endl;
    }

    return 0;
}
