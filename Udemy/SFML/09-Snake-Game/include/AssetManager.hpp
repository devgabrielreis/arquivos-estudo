#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace snake
{

class AssetManager
{
    public:
        enum class Font
        {
            Silkscreen = 0,
            Unibody_8_Black = 1
        };

        enum class Texture
        {
            Background = 0,
            Fruit = 1,
            Snake = 2
        };

        enum class SoundBuffer
        {
            Death = 0,
            FruitEaten = 1,
            Keypress = 2
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
