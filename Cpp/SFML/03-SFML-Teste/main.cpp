/*
https://stackoverflow.com/questions/23397536/how-to-compile-sfml-with-mingw

Compile Project
// dynamic linking
g++ -c main.cpp -IC:\SFML-2.5.1\include

// static linking
g++ -c main.cpp -IC:\SFML-2.5.1\include -DSFML_STATIC


Link Project
// dynamic linking
g++ main.o -o main -LC:\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32

// static linking
g++ main.o -o main -LC:\SFML-2.5.1\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32
*/

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
