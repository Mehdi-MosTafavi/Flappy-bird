#ifndef OBJECT
#define OBJECT
#include <vector>
using std::vector;
#include <SFML/Graphics.hpp>
struct Cordinate{
    float x;
    float y;
};
class Object{
    public:
    sf::RectangleShape object_rect;
    //sf::Sprite object_sprite;
    Cordinate des;
    bool score_check = false;
    Object(float,bool);
    //void add_object(float,float);
    void operator + (float);
    ~Object();
};
#endif