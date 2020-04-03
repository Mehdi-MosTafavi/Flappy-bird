
#ifndef BIRD_HPP
#define BIRD_HPP
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using std::string;
using std::to_string;
struct location{
    float x;
    float y;
};
class Bird{
    public:
    sf::Texture bird_texture;
    sf::Sprite bird_sprite;
    int score;
    location des;
    Bird();
    void operator + (float);
    string score_return();
    ~Bird();
};
#endif