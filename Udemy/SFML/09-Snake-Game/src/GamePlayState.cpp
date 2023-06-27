#include "GamePlayState.hpp"

namespace snake
{

GamePlayState::GamePlayState(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager, const unsigned short int cols, const unsigned short int lines, const unsigned short int squareSize, unsigned int& score, State& pauseState, State& gameOverState)
    : State{window, assetManager, stateManager}, mCols{cols}, mLines{lines}, mSquareSize{squareSize}, mScore{score},
      mFruit{mCols, mLines}, mSnake{mCols, mLines, mFruit, false, 4}, mPauseState{pauseState}, mGameOverState{gameOverState}
{
    mBackgroundSprite.setTexture(mAssetManager.getTexture(AssetManager::Texture::Background));
    mBackgroundSprite.setScale(
        1.f / (static_cast<float>(mBackgroundSprite.getTexture()->getSize().x) / static_cast<float>(mSquareSize)),
        1.f / (static_cast<float>(mBackgroundSprite.getTexture()->getSize().y) / static_cast<float>(mSquareSize))
    );

    mFruitSprite.setTexture(mAssetManager.getTexture(AssetManager::Texture::Fruit));
    mFruitSprite.setScale(
        1.f / (static_cast<float>(mFruitSprite.getTexture()->getSize().x) / static_cast<float>(mSquareSize)),
        1.f / (static_cast<float>(mFruitSprite.getTexture()->getSize().y) / static_cast<float>(mSquareSize))
    );

    mSnakeSprite.setTexture(mAssetManager.getTexture(AssetManager::Texture::Snake));
    mSnakeSprite.setScale(
        1.f / (static_cast<float>(mSnakeSprite.getTexture()->getSize().x) / static_cast<float>(mSquareSize)),
        1.f / (static_cast<float>(mSnakeSprite.getTexture()->getSize().y) / static_cast<float>(mSquareSize))
    );

    mDelayToSnakeMove = .12f;

    mDeathSound.setBuffer(mAssetManager.getSoundBuffer(AssetManager::SoundBuffer::Death));
    mFruitEatenSound.setBuffer(mAssetManager.getSoundBuffer(AssetManager::SoundBuffer::FruitEaten));
    mKeypressSound.setBuffer(mAssetManager.getSoundBuffer(AssetManager::SoundBuffer::Keypress));

    mPointsText.setFont(mAssetManager.getFont(AssetManager::Font::Silkscreen));
    mPointsText.setCharacterSize(mSquareSize / 2.f);
    mPointsText.setString("Size: " + std::to_string(mSnake.getSnakeSize()));
    mPointsText.setFillColor(sf::Color::White);
    mPointsText.setPosition(10.f, mSquareSize / 4.f);
}

void GamePlayState::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            mWindow.close();
        }
        if(event.type == sf::Event::KeyPressed)
        {
            switch(event.key.code)
            {
                case sf::Keyboard::W:
                    mSnake.setDirection(Snake::Direction::Up);
                    mKeypressSound.play();
                    break;
                case sf::Keyboard::Up:
                    mSnake.setDirection(Snake::Direction::Up);
                    mKeypressSound.play();
                    break;
                case sf::Keyboard::S:
                    mSnake.setDirection(Snake::Direction::Down);
                    mKeypressSound.play();
                    break;
                case sf::Keyboard::Down:
                    mSnake.setDirection(Snake::Direction::Down);
                    mKeypressSound.play();
                    break;
                case sf::Keyboard::A:
                    mSnake.setDirection(Snake::Direction::Left);
                    mKeypressSound.play();
                    break;
                case sf::Keyboard::Left:
                    mSnake.setDirection(Snake::Direction::Left);
                    mKeypressSound.play();
                    break;
                case sf::Keyboard::D:
                    mSnake.setDirection(Snake::Direction::Right);
                    mKeypressSound.play();
                    break;
                case sf::Keyboard::Right:
                    mSnake.setDirection(Snake::Direction::Right);
                    mKeypressSound.play();
                    break;
                case sf::Keyboard::Escape:
                    mStateManager.setNextState(&mPauseState, true);
                    mKeypressSound.play();
                    break;
                default:
                    break;
            }
        }
    }
}

void GamePlayState::updade()
{
    if(mClock.getElapsedTime().asSeconds() > mDelayToSnakeMove)
    {
        mClock.restart();

        switch(mSnake.move())
        {
            case Snake::MoveOutcome::FruitEaten:
                mFruitEatenSound.play();
                mPointsText.setString("Size: " + std::to_string(mSnake.getSnakeSize()));
                break;
            case Snake::MoveOutcome::Crashed:
                mDeathSound.play();
                mScore = mSnake.getSnakeSize();
                mStateManager.setNextState(&mGameOverState, true);
                break;
            case Snake::MoveOutcome::Nothing:
                break;
        }
    }
}

void GamePlayState::draw()
{
    mWindow.clear();

    for(int i = 0; i < mLines; i++)
    {
        for(int j = 0; j < mCols; j++)
        {
            mBackgroundSprite.setPosition(j * mSquareSize, i * mSquareSize);
            mWindow.draw(mBackgroundSprite);
        }
    }

    for(auto& snakePart : mSnake.getSnakeCoords())
    {
        mSnakeSprite.setPosition(snakePart.x * mSquareSize, snakePart.y * mSquareSize);
        mWindow.draw(mSnakeSprite);
    }

    mFruitSprite.setPosition(mFruit.getPosition().x * mSquareSize, mFruit.getPosition().y * mSquareSize);
    mWindow.draw(mFruitSprite);

    mWindow.draw(mPointsText);

    mWindow.display();
}

void GamePlayState::reset()
{
    mSnake.reset();
    mFruit.respawn();
    mPointsText.setString("Size: " + std::to_string(mSnake.getSnakeSize()));
}

}
