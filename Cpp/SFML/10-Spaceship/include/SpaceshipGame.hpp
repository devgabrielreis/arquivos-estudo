#pragma once

#include "GamePlayState.hpp"
#include "StartScreenState.hpp"

namespace space
{

class SpaceshipGame
{
    public:
        SpaceshipGame(unsigned int width, unsigned int height);
        void run();
    
    private:
        sf::RenderWindow mWindow;
        AssetManager mAssetManager;
        StateManager mStateManager;

        int mPoints;

        GamePlayState mGamePlayState;
        StartScreenState mStartScreenState;
};

}
