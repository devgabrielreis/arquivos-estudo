#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace space
{

class AssetManager
{
    public:
        enum class Font
        {
            digital = 0,
            SPACE = 1
        };

        enum class Texture
        {
            bg = 0,
            bullet = 1,
            enemy_min = 2,
            explosion = 3,
            power_life = 4,
            spaceship_min = 5
        };

        enum class SoundBuffer
        {
            placeholder
        };

        AssetManager();
        sf::Font& getFont(Font font);
        sf::Texture& getTexture(Texture texture);
        sf::SoundBuffer& getSoundBuffer(SoundBuffer soundBuffer);
    
    private:
        std::map<Font, sf::Font> mFonts;
        std::map<Texture, sf::Texture> mTextures;
        std::map<SoundBuffer, sf::SoundBuffer> mSoundBuffers;
};

}
