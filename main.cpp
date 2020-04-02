#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
using std::vector;
#include "Object.cpp"
#include "Bird.cpp"

int main()
{
    //Initializing and opening window
    sf::RenderWindow window(sf::VideoMode(900, 504), "Flappy Bird");
    sf::Texture background_texture;
    background_texture.loadFromFile("data/background.png");
    sf::Sprite background_sprite(background_texture);
    Bird bird;
    sf::Font font;
    font.loadFromFile("data/FlappyBirdy.ttf");
    //Game main boolean
    bool running = true;
    while (window.isOpen())
    {
        
        while(running){
        window.clear();
        window.draw(background_sprite);
        window.draw(rectangle);
        window.draw(bird.bird_sprite);
        //Bird default speed vertically
        bird + 0.01;
        window.display();
        //Handling events like closing the game or pessing space
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed :{
                    window.close();
                    return 0;
                    break;
                }
                case sf::Event::KeyPressed :{
                    //Bird move up when space pressed
                    if(event.key.code == sf::Keyboard::Space){
                        //check the bird if it is goint out of window or not
                        if(bird.des.y > 50){
                            bird + (-50);
                        }else{
                            bird + (-bird.des.y);
                        }
                    }
                    break;
                }
            }
        }
        }
        
    }

    return 0;
}