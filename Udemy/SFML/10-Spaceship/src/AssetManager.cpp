#include "AssetManager.hpp"

namespace space
{

AssetManager::AssetManager()
{
    const std::string fontsFolder = "./assets/fonts/";
    const std::string soundsFolder = "./assets/sounds/";
    const std::string texturesFolder = "./assets/textures/";

    const std::vector<std::string> fontsFiles{
        "digital.ttf",
        "SPACE.ttf"
    };
    const std::vector<std::string> soundBuffersFiles{};
    const std::vector<std::string> texturesFiles{
        "bg.jpg",
        "bullet.png",
        "enemy_min.png",
        "explosion.png",
        "power_life.png",
        "spaceship_min.png"
    };

    for(int i = 0; i < static_cast<int>(fontsFiles.size()); i++)
    {
        mFonts[static_cast<Font>(i)] = sf::Font();
        if(!mFonts[static_cast<Font>(i)].loadFromFile(fontsFolder + fontsFiles[i]))
        {
            throw std::runtime_error("Could not load \"" + fontsFolder + fontsFiles[i] + '\"');
        }
    }

    for(int i = 0; i < static_cast<int>(soundBuffersFiles.size()); i++)
    {
        mSoundBuffers[static_cast<SoundBuffer>(i)] = sf::SoundBuffer();
        if(!mSoundBuffers[static_cast<SoundBuffer>(i)].loadFromFile(soundsFolder + soundBuffersFiles[i]))
        {
            throw std::runtime_error("Could not load \"" + soundsFolder + soundBuffersFiles[i] + '\"');
        }
    }

    for(int i = 0; i < static_cast<int>(texturesFiles.size()); i++)
    {
        mTextures[static_cast<Texture>(i)] = sf::Texture();
        if(!mTextures[static_cast<Texture>(i)].loadFromFile(texturesFolder + texturesFiles[i]))
        {
            throw std::runtime_error("Could not load \"" + texturesFolder + texturesFiles[i] + '\"');
        }
    }
}

sf::Font& AssetManager::getFont(Font font)
{
    return mFonts[font];
}

sf::Texture& AssetManager::getTexture(Texture texture)
{
    return mTextures[texture];
}

sf::SoundBuffer& AssetManager::getSoundBuffer(SoundBuffer soundBuffer)
{
    return mSoundBuffers[soundBuffer];
}

}
