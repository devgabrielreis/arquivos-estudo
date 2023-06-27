#include <SFML/Graphics.hpp>
#include <iostream>

const int H = 23, W = 80; // tiramos a divisão por conta do offset

float offset_x = 0.f, offset_y = 0.f;

sf::String tilemap[H] = {
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                                B                                       B     B",
"B                                B                                       B     B",
"B                                B                                       B     B",
"B                                B                                       B     B",
"B                                B                                       B     B",
"B                                B                                       B     B",
"B                                B                                       B     B",
"B          0                     B                                       B     B",
"B                                B                                       B     B",
"B                                B                                       B     B",
"B        BBBB                    B                                       B     B",
"B                                B                                       B     B",
"B                   BBBBB      0 B                                       B     B",
"B                                B                                       B     B",
"B         0 0 0 0             BBBB                0 0 0               BBBB     B",
"B                                B                                       B     B",
"BBB                              B       BB                              B     B",
"B              BB                BB    BB              BB              BBBB    B",
"B        0     BB         BB           BB              BB                      X",
"B    B         BB         BB           BB    B         BB         BB           X",
"B    B         BB    0    BB           BB    B         BB         BB           X",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
};


class Player {
  public:
    const int ground = 736 - (82 + 32);
    float dx, dy, frame;
    bool on_ground;
    sf::FloatRect rect;
    sf::Sprite sprite;
    bool fase_1;

    Player(sf::Texture &texture){
      sprite.setTexture(texture);
      sprite.setTextureRect(sf::IntRect(0,0,43,82));
      rect = sf::FloatRect(64,ground,43,82);
      dx = 0.f;
      dy = 0.f;
      frame = 0.f;
      on_ground = false;
      fase_1 = false;
    }

    void update(float time){
      // PULO/GRAVIDADE
      // Para usar no setPosition
      rect.left += dx * time;
      collision(1);
      rect.top += dy * time;

      // Pular de acordo com a gravidade
      if(!on_ground){
        dy = dy + 0.0006 * time;
        sprite.move(sprite.getPosition().x, dy);
      }
      on_ground = false; // Para ele não ficar voando
      collision(0);

      if( rect.top > ground ){ // Para ele não passar do chão
        rect.top = ground;
        dy = 0;
        on_ground = true;
      }

      frame += 0.3f * time;
      if( frame > 6){
        frame -= 6;
      }

      // Para utilizar os frames(7) para direita
      if( dx > 0 ){
        sprite.setTextureRect(sf::IntRect(43 * (int)frame,0,43,82));
      }

      // Para utilizar os frames(7) para esquerda
      if( dx < 0){
        sprite.setTextureRect(sf::IntRect(43 * (int)frame + 43,0,-43,82));
      }

      sprite.setPosition(rect.left - offset_x, rect.top - offset_y); // dx e o dy os de movimento verdadeiros foram armazenados em rect.left e rect.top
      dx = 0; // Para ele mmovimentar a cada vez que a gente teclar as setas, caso contrário ele ficará andando sequencialmente
    }


    void collision(int direction){
      for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; ++i){
        for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; ++j){
          if(tilemap[i][j] == 'B'){
            // PARA o X
            if( direction == 1){
              if( dx > 0){
                rect.left = j * 32 - rect.width;
              }
              if( dx < 0 ){
                rect.left = j * 32 + 32;
              }
            }

            // PARA o Y
            if( direction == 0){
              if( dy > 0){
                rect.top = i * 32 - rect.height;
                dy = 0;
                on_ground = true;
              }
              if( dy < 0 ){
                rect.top = i * 32 + 32;
                dy = 0;
              }
            }
          } 

          if( tilemap[i][j] == '0'){
            tilemap[i][j] = ' ';
          }
          if( tilemap[i][j] == 'X'){
            fase_1 = true;
          }
        } 
      }
    }
};

int main(){
  sf::RenderWindow window(sf::VideoMode(1280,736), "Plataforma 2D", sf::Style::Titlebar | sf::Style::Close); 
  window.setPosition(sf::Vector2i(0,0));

  const float height_floor = 32.f, speed = 0.4f;

  sf::Texture texture, floor_texture, bg_texture, box, points, fase;
  texture.loadFromFile("./afro.png");
  bg_texture.loadFromFile("./bgnew.jpg");
  box.loadFromFile("./box.jpg");
  points.loadFromFile("./points.png");
  fase.loadFromFile("./floor.jpg");
  sf::Sprite bg(bg_texture);

  sf::RectangleShape rectangle(sf::Vector2f(height_floor, height_floor));

  Player player(texture);

  // pulo/gravidade
  sf::Clock clock;

  while( window.isOpen() ){
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time = time / 800;

    sf::Event event;
    while( window.pollEvent(event)){
      if( event.type == sf::Event::Closed ){
        window.close();
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
      player.dx = speed;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
      player.dx = -speed;
    }

    // Quando pressionarmos a tecla espaço ele pulará
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
      if(player.on_ground){
        player.dy = -speed;
      }
    }

    player.update(time);

    // TODO: remover espaço final do offset
    if( player.rect.left > (float)window.getSize().x / 2 ){
      offset_x = player.rect.left - (float)window.getSize().x / 2;
    }
    //if( player.rect.top < (float)window.getSize().y / 2 ){
    //  offset_y = player.rect.top - (float)window.getSize().y / 2;
    //}


    window.clear(sf::Color::Yellow);
    window.draw( bg );

    for (int i{}; i < H; ++i){
      for (int j{}; j < W; ++j){
       if( tilemap[i][j] == 'B'){
         //rectangle.setFillColor(sf::Color::Black);
         rectangle.setTexture(&box);
       } 
       if( tilemap[i][j] == '0'){
         //rectangle.setFillColor(sf::Color::Blue);
         rectangle.setTexture(&points);
       } 
       if( tilemap[i][j] == ' '){
         continue;
       } 

       if( tilemap[i][j] == 'X'){
         rectangle.setTexture(&fase);
       }

       rectangle.setPosition( j * 32 - offset_x, i * 32 - offset_y);
       window.draw(rectangle);
      }
    }

    if( player.fase_1 ){
      std::cout << "-------------------------------- PASSOU DA FASE 1 -------------------------" << '\n';
      window.close();
    }
    window.draw( player.sprite );
    window.display();
  }

  return EXIT_SUCCESS;
}
// g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system
