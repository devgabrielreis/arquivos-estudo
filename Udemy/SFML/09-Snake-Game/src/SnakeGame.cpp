#include "SnakeGame.hpp"

namespace snake
{

SnakeGame::SnakeGame(const unsigned short int cols, const unsigned short int lines, const unsigned short int squareSize)
    : mCols{cols}, mLines{lines}, mSquareSize{squareSize},
      mWindow{sf::VideoMode(mCols * mSquareSize, mLines * mSquareSize), "Snake", sf::Style::Titlebar | sf::Style::Close},
      mStartScreenState{mWindow, mAssetManager, mStateManager, mGamePlayState},
      mPauseState{mWindow, mAssetManager, mStateManager, mGamePlayState},
      mGameOverState{mWindow, mAssetManager, mStateManager, mScore, mGamePlayState},
      mGamePlayState{mWindow, mAssetManager, mStateManager, mCols, mLines, mSquareSize, mScore, mPauseState, mGameOverState}
{
    mWindow.setFramerateLimit(60);
    mWindow.setPosition(sf::Vector2i(10, 10));

    mStateManager.setNextState(&mStartScreenState, false);
}

void SnakeGame::run()
{
    while(mWindow.isOpen())
    {
        mStateManager.loadNextState();
        mStateManager.getCurrentState()->processEvents();
        mStateManager.getCurrentState()->updade();
        mStateManager.getCurrentState()->draw();
    }
}

}
