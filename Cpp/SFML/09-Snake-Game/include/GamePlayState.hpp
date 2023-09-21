#pragma once

#include "Snake.hpp"
#include "State.hpp"

namespace snake
{

class GamePlayState final : public State
{
    public:
        GamePlayState(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager, const unsigned short int cols, const unsigned short int lines, const unsigned short int squareSize, unsigned int& score, State& pauseState, State& gameOverState);
        void processEvents() override;
        void updade() override;
        void draw() override;
        void reset() override;
    
    private:
        const unsigned short int mCols;
        const unsigned short int mLines;
        const unsigned short int mSquareSize;

        unsigned int& mScore;

        sf::Sprite mBackgroundSprite;
        sf::Sprite mFruitSprite;
        sf::Sprite mSnakeSprite;

        sf::Sound mDeathSound;
        sf::Sound mFruitEatenSound;
        sf::Sound mKeypressSound;

        Fruit mFruit;
        Snake mSnake;
        sf::Clock mClock;
        float mDelayToSnakeMove;

        sf::Text mPointsText;

        State& mPauseState;
        State& mGameOverState;
};

}
