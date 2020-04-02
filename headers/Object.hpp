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
    vector<vector<Object>> obj;
    Cordinate des;

    Object();
    void operator + (float);
    ~Object();
};
#endif