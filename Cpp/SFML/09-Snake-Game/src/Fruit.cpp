#include "Fruit.hpp"

#include <cstdlib>
#include <ctime>

namespace snake
{

Fruit::Fruit(const unsigned short int cols, const unsigned short int lines)
    : mCols{cols}, mLines{lines}
{
    std::srand(std::time(nullptr));
    this->respawn();
}

const sf::Vector2i& Fruit::getPosition()
{
    return mPosition;
}

void Fruit::respawn()
{
    mPosition.x = std::rand() % mCols;
    mPosition.y = std::rand() % mLines;
}

}
