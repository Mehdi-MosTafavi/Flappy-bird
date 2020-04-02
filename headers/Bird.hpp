
#ifndef BIRD_HPP
#define BIRD_HPP
#include <SFML/Graphics.hpp>
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
    ~Bird();
};
#endif