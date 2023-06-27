#pragma once

#include <SFML/System/Vector2.hpp>

#include "Fruit.hpp"

#include <deque>

namespace snake
{

class Snake
{
    public:
        enum class Direction
        {
            Up,
            Down,
            Right,
            Left
        };

        enum class MoveOutcome
        {
            Nothing,
            FruitEaten,
            Crashed
        };

        Snake(const unsigned short int cols, const unsigned short int lines, Fruit& fruit, bool wrapScreen, const unsigned short int startSize);
        void setDirection(Direction direction);
        MoveOutcome move();
        std::size_t getSnakeSize();
        const std::deque<sf::Vector2i>& getSnakeCoords();
        void reset();

    private:
        bool checkCollision();

        const unsigned short int mCols;
        const unsigned short int mLines;
        const unsigned short int mStartSize;

        Fruit& mFruit;

        Direction mLastMove;
        Direction mNextMove;
        bool mWrapScreen;

        std::deque<sf::Vector2i> mSnake;
};

}
