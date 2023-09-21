#include <SFML/Graphics.hpp>

int main()
{
    sf::String title = "Formas";
    sf::RenderWindow window(sf::VideoMode(1280, 720), title);
    sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(
        (static_cast<float>(window.getSize().x) / 2) - (rectangle.getSize().x / 2),
        (static_cast<float>(window.getSize().y) / 2) - (rectangle.getSize().y / 2)
    );

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (rectangle.getFillColor() == sf::Color::Green)
                {
                    rectangle.setFillColor(sf::Color::Red);
                }
                else
                {
                    rectangle.setFillColor(sf::Color::Green);
                }
            }
        }

        auto position = sf::Mouse::getPosition(window);

        if (position.x < window.getSize().x - rectangle.getSize().x &&
            position.y < window.getSize().y - rectangle.getSize().y &&
            position.x > 0 &&
            position.y > 0)
        {
            rectangle.setPosition(sf::Vector2f(position));
        }

        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.display();
    }

    return EXIT_SUCCESS;
}
