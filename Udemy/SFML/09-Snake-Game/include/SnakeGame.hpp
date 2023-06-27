#pragma once

#include "GameOverState.hpp"
#include "GamePlayState.hpp"
#include "PauseState.hpp"
#include "StartScreenState.hpp"

namespace snake
{

class SnakeGame
{
    public:
        SnakeGame(const unsigned short int cols, const unsigned short int lines, const unsigned short int squareSize);
        void run();
    
    private:
        const unsigned short int mCols;
        const unsigned short int mLines;
        const unsigned short int mSquareSize;

        unsigned int mScore;

        sf::RenderWindow mWindow;
        AssetManager mAssetManager;
        StateManager mStateManager;

        StartScreenState mStartScreenState;
        PauseState mPauseState;
        GameOverState mGameOverState;
        GamePlayState mGamePlayState;
};

}
