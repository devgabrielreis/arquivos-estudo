#include "State.hpp"

namespace space
{

State::State(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager)
    : mWindow{window}, mAssetManager{assetManager}, mStateManager{stateManager}
{
}

}
