#include "headers/Object.hpp"
#include <iostream>
    Object::Object(float height, bool up){
        if(up == true){
        des.x = 900;
        des.y = 0;
        object_rect.setSize(sf::Vector2f(50.f, height));
        object_rect.setFillColor(sf::Color::Green);
        object_rect.setPosition(des.x,des.y);
        }else{
        des.x = 900;
        des.y = 504 - height;
        object_rect.setSize(sf::Vector2f(50.f, height));
        object_rect.setFillColor(sf::Color::Green);
        object_rect.setPosition(des.x,des.y);
        }
    }
    void
    Object::operator + (float x_pos){
        des.x += x_pos;
        object_rect.setPosition(des.x,des.y);
    }
    Object::~Object(){}