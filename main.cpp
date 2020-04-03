#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using std::vector;
using std::time;
using std::rand;
#include "Object.cpp"
#include "Bird.cpp"

int main()
{
    //Initializing and opening window
    vector<vector<Object>> obj;
    sf::RenderWindow window(sf::VideoMode(900, 504), "Flappy Bird");
    sf::Texture background_texture;
    background_texture.loadFromFile("data/background.png");
    sf::Sprite background_sprite(background_texture);
    Bird bird;
    srand(time(nullptr));
    sf::Font font;
    font.loadFromFile("data/FlappyBirdy.ttf");
    sf::Text text;
    sf::Text score;
    score.setFont(font);
    text.setFont(font);
    score.setCharacterSize(50);
    //Game main boolean
    bool running = true;
    bool gameover = false;
    vector<Object> obj_t;
        obj_t.push_back(Object(float(rand() % 200 + 150),true));
        obj_t.push_back(Object(float(rand() % 200 + 150),false));
        obj.push_back(obj_t);
        int index = -1;
        while(running){
        
            window.clear();
            //Creating new objects
            if(obj[obj.size()-1][0].des.x < 550){
                int h1 = rand() % 351 + 50;
                int h2 = rand() % 351 + 50;
                //Get random numbers for objects and control them not to be very small nor big
                while(h1 + h2 >= 425 || h1 + h2 <= 415 || abs(obj[obj.size()-1][0].des.y - h1) > 275 ){
                    h1 = rand() % 351 + 50;
                    h2 = rand() % 351 + 50;
                    std::cout<<h1<<" "<<h2<<std::endl;
                }
                
                obj_t.push_back(Object(float(h1),true));
                obj_t.push_back(Object(float(h2),false));
                obj.push_back(obj_t);
                obj_t.clear();
            }
        //Score section
        //if(bird.des.x == obj[index][0].des.x+50 && index != -1){
        //    std::cout<<"X";
         //   bird.score++;
        //}
        score.setString(bird.score_return());
        window.draw(background_sprite);
        window.draw(bird.bird_sprite);
        window.draw(score);
        //Bird default speed vertically
        bird + 0.01;
        //Moving objects
        if(obj.size() < 6){
        for(int i = 0; i < obj.size() ; i++){
           
            window.draw(obj[i][0].object_rect);
            window.draw(obj[i][1].object_rect);
            obj[i][1] + (-0.02);
            obj[i][0] + (-0.02);
        }
        }else{

           for(int i = obj.size()-4; i < obj.size() ; i++){
               
            window.draw(obj[i][0].object_rect);
            window.draw(obj[i][1].object_rect);
            obj[i][1] + (-0.02);
            obj[i][0] + (-0.02);
        } 
        }
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
                        if(bird.des.y > 50 && running == true){
                            bird + (-50);
                        }else{
                            bird + (-bird.des.y);
                        }
                    }
                    break;
                }
            }
            
        }
        if(bird.des.y > 470){
                running = false;
                gameover = true;
            }
        }
        if(gameover == true){
            
        }else{

        }
    return 0;
}