#include "headers/Bird.hpp"
#include <SFML/Graphics.hpp>
//using std::string;
//using std::to_string;
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
    string
    Bird::score_return(){
        return to_string(score);
    }
    Bird::~Bird(){}