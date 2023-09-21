#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
    sf::String title = "Fundamentos Iniciais";
    sf::RenderWindow window(sf::VideoMode(1280, 720), title);

    sf::CircleShape circle(100.f);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Fechou a janela\n";
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << "Pressionou o mouse\n";
            }
        }

        window.clear(sf::Color::Cyan);
        window.draw(circle);
        window.display();
    }

    return EXIT_SUCCESS;
}
