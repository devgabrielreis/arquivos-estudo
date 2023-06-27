#pragma once

#include "State.hpp"

namespace space
{

class StartScreenState final : public State
{
    public:
        StartScreenState(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager, State& gamePlayState);
        void processEvents() override;
        void updade() override;
        void draw() override;
        void reset() override;

    private:
        sf::Text mLogoText;
        sf::Text mMoveControlsText;
        sf::Text mShootKeyText;
        sf::Text mPauseKeyText;
        sf::Text mStartGameText;

        sf::Sprite mBackgroundSprite;

        short int mAlpha;
        short int mAlphaModifier;

        State& mGamePlayState;
};

}
