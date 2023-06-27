#include "State.hpp"

namespace snake
{

State::State(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager)
    : mWindow{window}, mAssetManager{assetManager}, mStateManager{stateManager}
{
}

}
