#pragma once

#include "State.hpp"

namespace snake
{

class GameOverState final : public State
{
    public:
        GameOverState(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager, unsigned int& score, State &gamePlayState);
        void processEvents() override;
        void updade() override;
        void draw() override;
        void reset() override;

    private:
        const unsigned int mGameoverTextCharSize;
        const unsigned int mMiscTextCharSize;

        unsigned int& mScore;

        sf::Text mGameOverText;
        sf::Text mScoreText;
        sf::Text mContinueText;

        sf::Sound mKeypressSound;

        short int mAlpha;
        short int mAlphaModifier;

        State &mGamePlayState;
};

}
