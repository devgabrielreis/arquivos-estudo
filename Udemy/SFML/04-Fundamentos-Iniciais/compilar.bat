g++ -c main.cpp -IC:\SFML-2.5.1\include -DSFML_STATIC
g++ main.o -o main -LC:\SFML-2.5.1\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32