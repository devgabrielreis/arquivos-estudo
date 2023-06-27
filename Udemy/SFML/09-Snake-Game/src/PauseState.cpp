#include "PauseState.hpp"

namespace snake
{

PauseState::PauseState(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager, State& gamePlayState)
    : State{window, assetManager, stateManager}, mGamePlayState{gamePlayState}
{
    const unsigned short pauseTextCharSize = mWindow.getSize().y / 7;
    const unsigned short continueTextCharSize = pauseTextCharSize / 3;

    mPauseText.setFont(mAssetManager.getFont(AssetManager::Font::Unibody_8_Black));
    mPauseText.setCharacterSize(pauseTextCharSize);
    mPauseText.setString("PAUSED");
    mPauseText.setFillColor(sf::Color(146, 43, 177));
    mPauseText.setPosition(
        (mWindow.getSize().x - mPauseText.getGlobalBounds().width) / 2.f,
        mWindow.getSize().y / 2.7f
    );

    mContinueText.setFont(mAssetManager.getFont(AssetManager::Font::Silkscreen));
    mContinueText.setCharacterSize(continueTextCharSize);
    mContinueText.setString("PRESS ESC TO CONTINUE");
    mContinueText.setFillColor(sf::Color::White);
    mContinueText.setPosition(
        (mWindow.getSize().x - mContinueText.getGlobalBounds().width) / 2.f,
        mPauseText.getPosition().y + pauseTextCharSize + continueTextCharSize
    );

    mAlpha = 255;
    mAlphaModifier = -5;

    mKeypressSound.setBuffer(mAssetManager.getSoundBuffer(AssetManager::SoundBuffer::Keypress));
}

void PauseState::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            mWindow.close();
        }
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            mKeypressSound.play();
            mStateManager.setNextState(&mGamePlayState, false);
        }
    }
}

void PauseState::updade()
{
    mAlpha += mAlphaModifier;

    if(mAlpha > 255)
    {
        mAlpha = 255;
        mAlphaModifier = -mAlphaModifier;
    }
    else if(mAlpha < 0)
    {
        mAlpha = 0;
        mAlphaModifier = -mAlphaModifier;
    }

    mContinueText.setFillColor(sf::Color(255, 255, 255, mAlpha));
}

void PauseState::draw()
{
    mWindow.clear();
    mWindow.draw(mPauseText);
    mWindow.draw(mContinueText);
    mWindow.display();
}

void PauseState::reset()
{
    mAlpha = 255;
    mAlphaModifier = -5;
}

}
