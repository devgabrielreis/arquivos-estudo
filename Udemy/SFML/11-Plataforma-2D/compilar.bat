g++ -c main.cpp -IC:\SFML-2.5.1\include -DSFML_STATIC -Wall
g++ *.o -o Plataforma-2D -LC:\SFML-2.5.1\lib -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lFLAC -lvorbisenc -lvorbisfile -lvorbis -logg -Wall
del *.o