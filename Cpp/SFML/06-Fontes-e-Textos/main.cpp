#include <SFML/Graphics.hpp>

#include <iostream>

int main(int argc, char const *argv[])
{
    sf::String title = "Textos e Fontes";
    sf::RenderWindow window(sf::VideoMode(1280, 720), title);

    sf::Font arial, pixel;
    if(!arial.loadFromFile("./arial.ttf") || !pixel.loadFromFile("./PixelBloated.ttf"))
    {
        std::cerr << "Falha ao ler a fonte!\n";
        return EXIT_FAILURE;
    }

    sf::Color rgb(55, 44, 77);
    
    sf::Text score("Score: 0", arial, 32);
    score.setPosition(sf::Vector2f(1100.f, 0));
    score.setFillColor(rgb);

    sf::Text life("Life: 100", pixel, 32);
    life.setPosition(sf::Vector2f(10.f,0));
    life.setFillColor(sf::Color::Red);

    int num_score{};
    int num_life = 100;
    bool pressed = false;

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

        if (event.type == event.MouseButtonReleased && event.type == event.MouseButtonPressed)
        {
            pressed = false;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && pressed)
        {
            num_life--;
            pressed = !pressed;
            life.setString("Life: " + std::to_string(num_life));
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !pressed)
        {
            num_score++;
            // std::cout << "Voce clicou com o botao esquerdo " << num << " vezes\n";
            score.setString("Score: " + std::to_string(num_score));
            pressed = true;
        }

        if(num_life < 0)
        {
            std::cout << "Game Over\n";
            window.close();
        }

        window.clear(sf::Color::White);
        window.draw(score);
        window.draw(life);
        window.display();
    }
    return 0;
}
