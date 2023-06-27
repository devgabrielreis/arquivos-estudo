#pragma once

#include "State.hpp"

namespace space
{

class GamePlayState final : public State
{
    public:
        GamePlayState(sf::RenderWindow& window, AssetManager& assetManager, StateManager& stateManager, int& points);
        void processEvents() override;
        void updade() override;
        void draw() override;
        void reset() override;

    private:
        struct Animation
        {
            sf::Sprite sprite;
            int currentFrame;
            int totalFrames;
            int frameWidth;
            int frameHeight;
            float frameDelay;
            float lastFrame;
        };

        int& mPoints;
        int mPlayerHP;

        sf::Clock mClock;
        float mSpaceshipSpeed;
        float mEnemySpeed;

        sf::Sprite mBackgroundSprite;
        sf::Sprite mSpaceshipSprite;
        sf::Sprite mHPSprite;
        float mHPSpriteHeight;

        std::vector<sf::Sprite> mBullets;
        std::vector<sf::Sprite> mEnemies;
        std::vector<Animation> mAnimations;

        sf::Text mPointsText;

        float mShootDelay;
        float mLastShoot;

        float mBulletSpeed;

        float mEnemySpawnDelay;
        float mLastEnemySpawn;

        void moveSpaceship();
        void shoot();
        void moveBullets();
        void spawnEnemy();
        void moveEnemies();
        void addAnimation(const sf::Vector2f& position);
        void updateAnimations();
};

}
