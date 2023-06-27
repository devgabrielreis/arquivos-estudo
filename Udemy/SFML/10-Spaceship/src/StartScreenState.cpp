#include "StartScreenState.hpp"

namespace space
{

StartScreenState::StartScreenState(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager, State& gamePlayState)
    : State{window, assetManager, stateManager}, mGamePlayState{gamePlayState}
{
    const unsigned short logoTextCharSize = mWindow.getSize().y / 7;
    const unsigned short miscTextCharSize = logoTextCharSize / 3;

    mLogoText.setFont(mAssetManager.getFont(AssetManager::Font::SPACE));
    mLogoText.setCharacterSize(logoTextCharSize);
    mLogoText.setString("Spaceship");
    mLogoText.setFillColor(sf::Color::White);
    mLogoText.setPosition(
        (mWindow.getSize().x - mLogoText.getGlobalBounds().width) / 2.f,
        (mWindow.getSize().y - logoTextCharSize - (miscTextCharSize * 8)) / 2.f
    );

    mMoveControlsText.setFont(mAssetManager.getFont(AssetManager::Font::digital));
    mMoveControlsText.setCharacterSize(miscTextCharSize);
    mMoveControlsText.setString("WASD / Arrow keys -> Move spaceship");
    mMoveControlsText.setFillColor(sf::Color::White);
    mMoveControlsText.setPosition(
        (mWindow.getSize().x - mMoveControlsText.getGlobalBounds().width) / 2.f,
        mLogoText.getPosition().y + logoTextCharSize + miscTextCharSize
    );

    mShootKeyText.setFont(mAssetManager.getFont(AssetManager::Font::digital));
    mShootKeyText.setCharacterSize(miscTextCharSize);
    mShootKeyText.setString("Space -> Shoot");
    mShootKeyText.setFillColor(sf::Color::White);
    mShootKeyText.setPosition(
        (mWindow.getSize().x - mShootKeyText.getGlobalBounds().width) / 2.f,
        mMoveControlsText.getPosition().y + miscTextCharSize * 2
    );

    mPauseKeyText.setFont(mAssetManager.getFont(AssetManager::Font::digital));
    mPauseKeyText.setCharacterSize(miscTextCharSize);
    mPauseKeyText.setString("Esc -> Pause");
    mPauseKeyText.setFillColor(sf::Color::White);
    mPauseKeyText.setPosition(
        (mWindow.getSize().x - mPauseKeyText.getGlobalBounds().width) / 2.f,
        mShootKeyText.getPosition().y + miscTextCharSize * 2
    );

    mStartGameText.setFont(mAssetManager.getFont(AssetManager::Font::digital));
    mStartGameText.setCharacterSize(miscTextCharSize);
    mStartGameText.setString("Press any key to start the game");
    mStartGameText.setFillColor(sf::Color::White);
    mStartGameText.setPosition(
        (mWindow.getSize().x - mStartGameText.getGlobalBounds().width) / 2.f,
        mPauseKeyText.getPosition().y + miscTextCharSize * 2
    );

    mAlpha = 255;
    mAlphaModifier = -5;

    mBackgroundSprite.setTexture(mAssetManager.getTexture(AssetManager::Texture::bg));
    mBackgroundSprite.setScale(
        1.f / (mBackgroundSprite.getGlobalBounds().width / static_cast<float>(mWindow.getSize().x)),
        1.f / (mBackgroundSprite.getGlobalBounds().height / static_cast<float>(mWindow.getSize().y))
    );
    mBackgroundSprite.setPosition(0.f, 0.f);
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

    mStartGameText.setFillColor(sf::Color(255, 255, 255, mAlpha));
}

void StartScreenState::draw()
{
    mWindow.clear();
    mWindow.draw(mBackgroundSprite);
    mWindow.draw(mLogoText);
    mWindow.draw(mMoveControlsText);
    mWindow.draw(mShootKeyText);
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
