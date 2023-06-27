#include "SpaceshipGame.hpp"

namespace space
{

SpaceshipGame::SpaceshipGame(unsigned int width, unsigned int height)
    : mWindow{sf::VideoMode(width, height), "Spaceship", sf::Style::Titlebar | sf::Style::Close},
      mGamePlayState{mWindow, mAssetManager, mStateManager, mPoints},
      mStartScreenState{mWindow, mAssetManager, mStateManager, mGamePlayState}
{
    mWindow.setFramerateLimit(60);
    mWindow.setPosition(sf::Vector2i(10, 10));
    mWindow.setKeyRepeatEnabled(false);

    mStateManager.setNextState(&mStartScreenState, false);
}

void SpaceshipGame::run()
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
