#include "Snake.hpp"

namespace snake
{

Snake::Snake(const unsigned short int cols, const unsigned short int lines, Fruit& fruit, bool wrapScreen, const unsigned short int startSize)
    : mCols{cols}, mLines{lines}, mStartSize{startSize}, mFruit{fruit}, mLastMove{Snake::Direction::Right}, mNextMove{mLastMove}, mWrapScreen{wrapScreen}, mSnake{}
{
    for(int i = mStartSize; i > 0; i--)
    {
        mSnake.push_back(sf::Vector2i(i, 2));
    }
}

void Snake::setDirection(Direction direction)
{
    switch(direction)
    {
        case Direction::Up:
            if(mLastMove != Direction::Down)
            {
                mNextMove = direction;
            }
            break;
        case Direction::Down:
            if(mLastMove != Direction::Up)
            {
                mNextMove = direction;
            }
            break;
        case Direction::Right:
            if(mLastMove != Direction::Left)
            {
                mNextMove = direction;
            }
            break;
        case Direction::Left:
            if(mLastMove != Direction::Right)
            {
                mNextMove = direction;
            }
            break;
    }
}

Snake::MoveOutcome Snake::move()
{
    sf::Vector2i headDisplacement(0, 0);

    switch(mNextMove)
    {
        case Direction::Up:
            headDisplacement.y = -1;
            break;
        case Direction::Down:
            headDisplacement.y = 1;
            break;
        case Direction::Right:
            headDisplacement.x = 1;
            break;
        case Direction::Left:
            headDisplacement.x = -1;
            break;
    }

    mLastMove = mNextMove;

    if(mSnake[0] + headDisplacement == mFruit.getPosition())
    {
        mSnake.push_front(mFruit.getPosition());
        mFruit.respawn();

        return MoveOutcome::FruitEaten;
    }
    else
    {
        for(int i = mSnake.size() - 1; i > 0; i--)
        {
            mSnake[i].x = mSnake[i - 1].x;
            mSnake[i].y = mSnake[i - 1].y;
        }

        mSnake[0] += headDisplacement;

        if(mWrapScreen)
        {
            if(mSnake[0].x > mCols - 1)
            {
                mSnake[0].x = 0;
            }
            else if(mSnake[0].x < 0)
            {
                mSnake[0].x = mCols - 1;
            }
            else if(mSnake[0].y > mLines - 1)
            {
                mSnake[0].y = 0;
            }
            else if(mSnake[0].y < 0)
            {
                mSnake[0].y = mLines - 1;
            }
        }
    }

    if(this->checkCollision())
    {
        return MoveOutcome::Crashed;
    }

    return MoveOutcome::Nothing;
}

std::size_t Snake::getSnakeSize()
{
    return mSnake.size();
}

const std::deque<sf::Vector2i>& Snake::getSnakeCoords()
{
    return mSnake;
}

bool Snake::checkCollision()
{
    if(mSnake[0].x < 0 ||
       mSnake[0].y < 0 ||
       mSnake[0].x > mCols - 1 ||
       mSnake[0].y > mLines - 1)
    {
        return true;
    }

    for(unsigned long long i = 1; i < mSnake.size(); i++)
    {
        if(mSnake[0].x == mSnake[i].x && mSnake[0].y == mSnake[i].y)
        {
            return true;
        }
    }

    return false;
}

void Snake::reset()
{
    mSnake.clear();
    for(int i = mStartSize; i > 0; i--)
    {
        mSnake.push_back(sf::Vector2i(i, 2));
    }
    mLastMove = Snake::Direction::Right;
    mNextMove = mLastMove;
}

}
