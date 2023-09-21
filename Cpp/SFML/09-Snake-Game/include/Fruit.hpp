#pragma once

#include <SFML/System/Vector2.hpp>

namespace snake
{

class Fruit
{
    public:
        Fruit(unsigned short int cols, unsigned short int lines);
        const sf::Vector2i& getPosition();
        void respawn();

    private:
        const unsigned short int mCols;
        const unsigned short int mLines;

        sf::Vector2i mPosition;
};

}
