#include "SnakeGame.hpp"

#include <iostream>
#include <memory>

int main()
{
    try
    {
        std::unique_ptr<snake::SnakeGame> game = std::make_unique<snake::SnakeGame>(20, 13, 32);
        game->run();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
