#pragma once

#include "AssetManager.hpp"
#include "StateManager.hpp"

namespace space
{

class State
{
    public:
        State(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager);
        virtual void processEvents() = 0;
        virtual void updade() = 0;
        virtual void draw() = 0;
        virtual void reset() = 0;

    protected:
        sf::RenderWindow& mWindow;
        AssetManager& mAssetManager;
        StateManager& mStateManager;
};

}
