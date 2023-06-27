#include <SFML/Graphics.hpp>

#include <iostream>

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Imagens e Movimento");

    sf::Texture texture;
    if(!texture.loadFromFile("./ball.png"))
    {
        std::cerr << "Nao foi possivel carregar imagem\n";
        return EXIT_FAILURE;
    }

    sf::Texture campo;
    if(!campo.loadFromFile("./campo.jpg"))
    {
        std::cerr << "Nao foi possivel carregar imagem\n";
        return EXIT_FAILURE;
    }

    sf::Sprite sprite(texture);
    sprite.setPosition(500.f,200.f);

    sf::Sprite fundo(campo);

    sf::Vector2u size = texture.getSize();
    sf::Vector2f velocidade(0.4f, 0.4f);
    sf::Vector2f pos_text(0.f, -50.f);

    sf::Font font;
    if(!font.loadFromFile("./arial.ttf"))
    {
        std::cerr << "Nao foi possivel ler a fonte\n";
        return EXIT_FAILURE;
    }
    sf::Text text("400, 200", font, 32);
    text.setFillColor(sf::Color::Black);

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if((sprite.getPosition().x + size.x > window.getSize().x && velocidade.x > 0) ||
           (sprite.getPosition().x < 0 && velocidade.x < 0))
        {
            velocidade.x = -velocidade.x;
            sprite.setColor(sf::Color::Red);
        }

        if((sprite.getPosition().y + size.y > window.getSize().y && velocidade.y > 0) ||
           (sprite.getPosition().y < 0 && velocidade.y < 0))
        {
            velocidade.y = -velocidade.y;
            sprite.setColor(sf::Color::Yellow);
        }

        sprite.setPosition(sprite.getPosition() + velocidade);
        text.setPosition(sprite.getPosition() + velocidade + pos_text);
        text.setString(
            std::to_string(static_cast<int>(sprite.getPosition().x)) +
            ", " +
            std::to_string(static_cast<int>(sprite.getPosition().y))
        );

        window.clear();
        window.draw(fundo);
        window.draw(sprite);
        window.draw(text);
        window.display();
    }

    return EXIT_SUCCESS;
}
