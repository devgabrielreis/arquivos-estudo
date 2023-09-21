#include "StartScreenState.hpp"

namespace snake
{

StartScreenState::StartScreenState(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager, State& gamePlayState)
    : State{window, assetManager, stateManager}, mGamePlayState{gamePlayState}
{
    const unsigned short logoTextCharSize = mWindow.getSize().y / 7;
    const unsigned short miscTextCharSize = logoTextCharSize / 3;

    mLogoText.setFont(mAssetManager.getFont(AssetManager::Font::Unibody_8_Black));
    mLogoText.setCharacterSize(logoTextCharSize);
    mLogoText.setString("SNAKE");
    mLogoText.setFillColor(sf::Color(146, 43, 177));
    mLogoText.setPosition(
        (mWindow.getSize().x - mLogoText.getGlobalBounds().width) / 2.f,
        mWindow.getSize().y / 4
    );

    mControlsText.setFont(mAssetManager.getFont(AssetManager::Font::Silkscreen));
    mControlsText.setCharacterSize(miscTextCharSize);
    mControlsText.setString("WASD / ARROW KEYS -> MOVE SNAKE");
    mControlsText.setFillColor(sf::Color::White);
    mControlsText.setPosition(
        (mWindow.getSize().x - mControlsText.getGlobalBounds().width) / 2.f,
        mLogoText.getPosition().y + logoTextCharSize + miscTextCharSize
    );

    mPauseKeyText.setFont(mAssetManager.getFont(AssetManager::Font::Silkscreen));
    mPauseKeyText.setCharacterSize(miscTextCharSize);
    mPauseKeyText.setString("ESC -> PAUSE GAME");
    mPauseKeyText.setFillColor(sf::Color::White);
    mPauseKeyText.setPosition(
        (mWindow.getSize().x - mPauseKeyText.getGlobalBounds().width) / 2.f,
        mControlsText.getPosition().y + miscTextCharSize * 2
    );

    mStartGameText.setFont(mAssetManager.getFont(AssetManager::Font::Silkscreen));
    mStartGameText.setCharacterSize(miscTextCharSize);
    mStartGameText.setString("PRESS ANY KEY TO START THE GAME");
    mStartGameText.setFillColor(sf::Color(184, 74, 82));
    mStartGameText.setPosition(
        (mWindow.getSize().x - mStartGameText.getGlobalBounds().width) / 2.f,
        mPauseKeyText.getPosition().y + miscTextCharSize * 2
    );

    mAlpha = 255;
    mAlphaModifier = -5;

    mKeypressSound.setBuffer(mAssetManager.getSoundBuffer(AssetManager::SoundBuffer::Keypress));
}

void StartScreenState::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            mWindow.close();
        }
        if(event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
        {
            mKeypressSound.play();
            mStateManager.setNextState(&mGamePlayState, false);
        }
    }
}

void StartScreenState::updade()
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

    mStartGameText.setFillColor(sf::Color(184, 74, 82, mAlpha));
}

void StartScreenState::draw()
{
    mWindow.clear(sf::Color(48, 48, 48));
    mWindow.draw(mLogoText);
    mWindow.draw(mControlsText);
    mWindow.draw(mPauseKeyText);
    mWindow.draw(mStartGameText);
    mWindow.display();
}

void StartScreenState::reset()
{
    mAlpha = 255;
    mAlphaModifier = -5;
}

}
