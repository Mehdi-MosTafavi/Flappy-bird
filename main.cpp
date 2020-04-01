#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>
using namespace std;
#include "Object.cpp"
#include "Bird.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 504), "Flappy Bird");
    sf::Texture background_texture;
    //sf::RectangleShape
    background_texture.loadFromFile("data/background.png");
    sf::Sprite s(background_texture);

    while (window.isOpen())
    {
        //Handling events like closing the game or pessing space
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            switch(event.type){
                case sf::Event::Closed :{
                    window.close();
                    break;
                }
                case sf::Event::KeyPressed :{
                    if(event.key.code == sf::Keyboard::Space){
                        
                    }
                    break;
                }
            }
        }

        window.clear();
        window.draw(s);
        window.display();
    }

    return 0;
}