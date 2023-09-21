#include "SpaceshipGame.hpp"

#include <iostream>
#include <memory>

int main()
{
    try
    {
        std::unique_ptr<space::SpaceshipGame> game = std::make_unique<space::SpaceshipGame>(1280, 720);
        game->run();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
