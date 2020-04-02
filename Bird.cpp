#include "headers/Bird.hpp"
#include <SFML/Graphics.hpp>

    Bird::Bird(){
    score = 0;
    des.x = 200;
    des.y = 252;
    bird_texture.loadFromFile("data/bird.png");
    bird_sprite.setTexture(bird_texture);
    bird_sprite.setPosition(des.x,des.y);
    }
    void
    Bird::operator + (float y_pos){
        des.y += y_pos;
        bird_sprite.setPosition(des.x,des.y);
    }
    Bird::~Bird(){}