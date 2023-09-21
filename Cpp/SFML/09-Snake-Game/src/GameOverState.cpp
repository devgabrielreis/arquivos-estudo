#include "GameOverState.hpp"

namespace snake
{

GameOverState::GameOverState(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager, unsigned int& score, State &gamePlayState)
    : State{window, assetManager, stateManager}, mGameoverTextCharSize{mWindow.getSize().y / 7}, mMiscTextCharSize{mGameoverTextCharSize / 3}, mScore{score},
      mGamePlayState{gamePlayState}
{
    mGameOverText.setFont(mAssetManager.getFont(AssetManager::Font::Unibody_8_Black));
    mGameOverText.setCharacterSize(mGameoverTextCharSize);
    mGameOverText.setString("GAMEOVER");
    mGameOverText.setFillColor(sf::Color(146, 43, 177));
    mGameOverText.setPosition(
        (mWindow.getSize().x - mGameOverText.getGlobalBounds().width) / 2.f,
        mWindow.getSize().y / 3.f
    );

    mScoreText.setFont(mAssetManager.getFont(AssetManager::Font::Silkscreen));
    mScoreText.setCharacterSize(mMiscTextCharSize);
    mScoreText.setFillColor(sf::Color::White);

    mContinueText.setFont(mAssetManager.getFont(AssetManager::Font::Silkscreen));
    mContinueText.setCharacterSize(mMiscTextCharSize);
    mContinueText.setString("PRESS ENTER TO PLAY AGAIN");
    mContinueText.setFillColor(sf::Color::White);
    mContinueText.setPosition(
        (mWindow.getSize().x - mContinueText.getGlobalBounds().width) / 2.f,
        mGameOverText.getPosition().y + mGameoverTextCharSize + mMiscTextCharSize * 3
    );

    mAlpha = 255;
    mAlphaModifier = -5;

    mKeypressSound.setBuffer(mAssetManager.getSoundBuffer(AssetManager::SoundBuffer::Keypress));
}

void GameOverState::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            mWindow.close();
        }
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
        {
            mKeypressSound.play();
            mStateManager.setNextState(&mGamePlayState, true);
        }
    }
}

void GameOverState::updade()
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

void GameOverState::draw()
{
    mWindow.clear();
    mWindow.draw(mGameOverText);
    mWindow.draw(mScoreText);
    mWindow.draw(mContinueText);
    mWindow.display();
}

void GameOverState::reset()
{
    mScoreText.setString("SNAKE SIZE: " + std::to_string(mScore));
    mScoreText.setPosition(
        (mWindow.getSize().x - mScoreText.getGlobalBounds().width) / 2.f,
        mGameOverText.getPosition().y + mGameoverTextCharSize + mMiscTextCharSize
    );
    mAlpha = 255;
    mAlphaModifier = -5;
}

}
