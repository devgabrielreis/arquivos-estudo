#pragma once

#include "State.hpp"

namespace snake
{

class PauseState final : public State
{
    public:
        PauseState(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager, State& gamePlayState);
        void processEvents() override;
        void updade() override;
        void draw() override;
        void reset() override;

    private:
        sf::Text mPauseText;
        sf::Text mContinueText;

        sf::Sound mKeypressSound;

        short int mAlpha;
        short int mAlphaModifier;

        State &mGamePlayState;
};

}
