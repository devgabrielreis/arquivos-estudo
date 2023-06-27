#include "GamePlayState.hpp"

namespace space
{

GamePlayState::GamePlayState(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager, int& points)
    : State{window, assetManager, stateManager}, mPoints{points}
{
    std::srand(std::time(nullptr));

    mPointsText.setFont(mAssetManager.getFont(AssetManager::Font::digital));
    mPointsText.setCharacterSize(mWindow.getSize().y / 20);
    mPointsText.setString("Destroyed enemies: 0");
    mPointsText.setFillColor(sf::Color::White);
    mPointsText.setPosition(10.f, 10.f);

    mBackgroundSprite.setTexture(mAssetManager.getTexture(AssetManager::Texture::bg));
    mBackgroundSprite.setScale(
        1.f / (mBackgroundSprite.getGlobalBounds().width / static_cast<float>(mWindow.getSize().x)),
        1.f / (mBackgroundSprite.getGlobalBounds().height / static_cast<float>(mWindow.getSize().y))
    );
    mBackgroundSprite.setPosition(0.f, 0.f);

    mSpaceshipSprite.setTexture(assetManager.getTexture(AssetManager::Texture::spaceship_min));
    mSpaceshipSprite.setScale(
        1.f / (mSpaceshipSprite.getGlobalBounds().width / (static_cast<float>(mWindow.getSize().x) / 12.5f)),
        1.f / (mSpaceshipSprite.getGlobalBounds().height / (static_cast<float>(mWindow.getSize().y) / 11.6f))
    );
    mSpaceshipSprite.setPosition(
        0.f,
        (static_cast<float>(mWindow.getSize().y) - mSpaceshipSprite.getGlobalBounds().height) / 2.f
    );

    mSpaceshipSpeed = static_cast<float>(mWindow.getSize().x) / 3.f;
    mEnemySpeed = static_cast<float>(mWindow.getSize().x) / 3.f;

    mBulletSpeed = static_cast<float>(mWindow.getSize().x) / .55f;

    mShootDelay = .25f;
    mLastShoot = mShootDelay + 1.f;

    mEnemySpawnDelay = 1.f;
    mLastEnemySpawn = 0.f;

    mPlayerHP = 3;

    mHPSprite = sf::Sprite(mAssetManager.getTexture(AssetManager::Texture::power_life));
    mHPSprite.setScale(
        1.f / (mHPSprite.getGlobalBounds().width / (static_cast<float>(mWindow.getSize().x) / 4.266f)),
        1.f / (mHPSprite.getGlobalBounds().height / (static_cast<float>(mWindow.getSize().y) / 6.f))
    );
    mHPSprite.setPosition(mWindow.getSize().x - mHPSprite.getGlobalBounds().width - 10.f, 10.f);

    mHPSpriteHeight = mHPSprite.getGlobalBounds().height;

    mHPSprite.setTextureRect(sf::IntRect(0, 0, mHPSprite.getGlobalBounds().width, mHPSpriteHeight / 4));
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
            if(event.key.code == sf::Keyboard::Space)
            {
                this->shoot();
            }
        }
    }
}

void GamePlayState::updade()
{
    if(mLastEnemySpawn > mEnemySpawnDelay)
    {
        this->spawnEnemy();
        mLastEnemySpawn = 0;
    }
    this->moveSpaceship();
    this->moveBullets();
    this->moveEnemies();
    this->updateAnimations();

    mLastShoot += mClock.getElapsedTime().asSeconds();
    mLastEnemySpawn += mClock.getElapsedTime().asSeconds();

    mClock.restart();
}

void GamePlayState::draw()
{
    mWindow.clear();

    mWindow.draw(mBackgroundSprite);
    mWindow.draw(mSpaceshipSprite);

    for(auto& bullet : mBullets)
    {
        mWindow.draw(bullet);
    }
    for(auto& enemy : mEnemies)
    {
        mWindow.draw(enemy);
    }
    for(auto& animation : mAnimations)
    {
        mWindow.draw(animation.sprite);
    }

    mWindow.draw(mPointsText);
    mWindow.draw(mHPSprite);

    mWindow.display();
}

void GamePlayState::reset()
{
    mSpaceshipSprite.setPosition(
        0.f,
        (static_cast<float>(mWindow.getSize().y) - mSpaceshipSprite.getGlobalBounds().height) / 2.f
    );

    mBullets.clear();
    mLastShoot = mShootDelay + 1.f;

    mEnemies.clear();
    mLastEnemySpawn = 0.f;

    mAnimations.clear();

    mPoints = 0;
    mPlayerHP = 0;

    mHPSprite.setTextureRect(sf::IntRect(0, 0, mHPSprite.getGlobalBounds().width, mHPSpriteHeight / 4));

    mClock.restart();
}

void GamePlayState::moveSpaceship()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        mSpaceshipSprite.move(0.f, -(mClock.getElapsedTime().asSeconds() * mSpaceshipSpeed));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        mSpaceshipSprite.move(0.f, mClock.getElapsedTime().asSeconds() * mSpaceshipSpeed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        mSpaceshipSprite.move(-(mClock.getElapsedTime().asSeconds() * mSpaceshipSpeed), 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        mSpaceshipSprite.move(mClock.getElapsedTime().asSeconds() * mSpaceshipSpeed, 0.f);
    }

    if(mSpaceshipSprite.getPosition().x < 0)
    {
        mSpaceshipSprite.setPosition(0.f, mSpaceshipSprite.getPosition().y);
    }
    if(mSpaceshipSprite.getPosition().x > mWindow.getSize().x - mSpaceshipSprite.getGlobalBounds().width)
    {
        mSpaceshipSprite.setPosition(mWindow.getSize().x - mSpaceshipSprite.getGlobalBounds().width, mSpaceshipSprite.getPosition().y);
    }
    if(mSpaceshipSprite.getPosition().y < 0)
    {
        mSpaceshipSprite.setPosition(mSpaceshipSprite.getPosition().x, 0.f);
    }
    if(mSpaceshipSprite.getPosition().y > mWindow.getSize().y - mSpaceshipSprite.getGlobalBounds().height)
    {
        mSpaceshipSprite.setPosition(mSpaceshipSprite.getPosition().x, mWindow.getSize().y - mSpaceshipSprite.getGlobalBounds().height);
    }
}

void GamePlayState::shoot()
{
    if(mLastShoot < mShootDelay)
    {
        return;
    }

    mLastShoot = 0;

    mBullets.push_back(
        sf::Sprite(mAssetManager.getTexture(AssetManager::Texture::bullet))
    );

    mBullets[mBullets.size() - 1].setScale(
        1.f / (mBullets[mBullets.size() - 1].getGlobalBounds().width / (static_cast<float>(mWindow.getSize().x) / 25.6f)),
        1.f / (mBullets[mBullets.size() - 1].getGlobalBounds().height / (static_cast<float>(mWindow.getSize().y) / 80.f))
    );

    mBullets[mBullets.size() - 1].setPosition(
        mSpaceshipSprite.getPosition().x + mSpaceshipSprite.getGlobalBounds().width - mBullets[mBullets.size() - 1].getGlobalBounds().width,
        mSpaceshipSprite.getPosition().y + (mSpaceshipSprite.getGlobalBounds().height - mBullets[mBullets.size() - 1].getGlobalBounds().height) / 2.f
    );
}

void GamePlayState::moveBullets()
{
    for(std::vector<sf::Sprite>::iterator bullet = mBullets.begin(); bullet != mBullets.end();)
    {
        if(bullet->getPosition().x > mWindow.getSize().x)
        {
            bullet = mBullets.erase(bullet);
        }
        else
        {
            bullet->move(mClock.getElapsedTime().asSeconds() * mBulletSpeed, 0.f);

            for(std::vector<sf::Sprite>::iterator enemy = mEnemies.begin(); enemy != mEnemies.end();)
            {
                if(bullet->getGlobalBounds().intersects(enemy->getGlobalBounds()))
                {
                    this->addAnimation(enemy->getPosition());
                    enemy = mEnemies.erase(enemy);
                    bullet = mBullets.erase(bullet);
                    bullet--;
                    mPoints++;
                    mPointsText.setString("Destroyed enemies: " + std::to_string(mPoints));
                }
                else
                {
                    enemy++;
                }
            }

            bullet++;
        }
    }
}

void GamePlayState::spawnEnemy()
{
    mEnemies.push_back(
        sf::Sprite(mAssetManager.getTexture(AssetManager::Texture::enemy_min))
    );

    mEnemies[mEnemies.size() - 1].setScale(
        1.f / (mEnemies[mEnemies.size() - 1].getGlobalBounds().width / (static_cast<float>(mWindow.getSize().x) / 16.f)),
        1.f / (mEnemies[mEnemies.size() - 1].getGlobalBounds().height / (static_cast<float>(mWindow.getSize().y) / 8.888f))
    );

    mEnemies[mEnemies.size() - 1].setPosition(
        mWindow.getSize().x,
        std::rand() % static_cast<int>(mWindow.getSize().y - mEnemies[mEnemies.size() - 1].getGlobalBounds().height)
    );
}

void GamePlayState::moveEnemies()
{
    for(std::vector<sf::Sprite>::iterator enemy = mEnemies.begin(); enemy != mEnemies.end();)
    {
        if(enemy->getPosition().x < -(enemy->getGlobalBounds().width))
        {
            enemy = mEnemies.erase(enemy);
        }
        else if(enemy->getGlobalBounds().intersects(mSpaceshipSprite.getGlobalBounds()))
        {
            mPlayerHP--;
            mHPSprite.setTextureRect(
                sf::IntRect(0, (mHPSpriteHeight / 4) * std::abs(mPlayerHP - 3), mHPSprite.getGlobalBounds().width, mHPSpriteHeight / 4)
            );
            this->addAnimation(enemy->getPosition());
            enemy = mEnemies.erase(enemy);
            mPoints++;
            mPointsText.setString("Destroyed enemies: " + std::to_string(mPoints));
        }
        else
        {
            enemy->move(mClock.getElapsedTime().asSeconds() * -mEnemySpeed, 0.f);
            enemy++;
        }
    }
}

void GamePlayState::addAnimation(const sf::Vector2f& position)
{
    Animation animation;
    animation.sprite = sf::Sprite(mAssetManager.getTexture(AssetManager::Texture::explosion));
    animation.sprite.setPosition(position);
    animation.sprite.setScale(
        1.f / (animation.sprite.getGlobalBounds().width / (static_cast<float>(mWindow.getSize().x) / 1.231f)),
        1.f / (animation.sprite.getGlobalBounds().height / (static_cast<float>(mWindow.getSize().y) / 7.42f))
    );
    animation.currentFrame = 0;
    animation.totalFrames = 13;
    animation.frameDelay = .04f;
    animation.lastFrame = 0.f;
    animation.frameWidth = animation.sprite.getGlobalBounds().width / animation.totalFrames;
    animation.frameHeight = animation.sprite.getGlobalBounds().height;
    animation.sprite.setTextureRect(
        sf::IntRect(0, 0, animation.frameWidth, animation.sprite.getGlobalBounds().height)
    );
    mAnimations.push_back(animation);
}

void GamePlayState::updateAnimations()
{
    for(std::vector<Animation>::iterator animation = mAnimations.begin(); animation != mAnimations.end();)
    {
        animation->lastFrame += mClock.getElapsedTime().asSeconds();
        if(animation->frameDelay > animation->lastFrame)
        {
            animation++;
            continue;
        }

        animation->currentFrame++;
        animation->lastFrame = 0.f;

        if(animation->currentFrame >= animation->totalFrames)
        {
            animation = mAnimations.erase(animation);
        }
        else
        {
            animation->sprite.setTextureRect(
                sf::IntRect(animation->frameWidth * animation->currentFrame, 0, animation->frameWidth, animation->frameHeight)
            );
            animation++;
        }
    }
}

}
