#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
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
    //Initializing and opening window and first time run
  Start:  sf::Event event;
    vector<vector<Object>> obj;
    vector<Object> obj_t;
    obj_t.push_back(Object(float(rand() % 250 + 50),true));
    obj_t.push_back(Object(float(rand() % 250 + 50),false));
    obj.push_back(obj_t);
    sf::RenderWindow window(sf::VideoMode(900, 504), "Flappy Bird");
    //Init background
    sf::Texture background_texture;
    background_texture.loadFromFile("data/background.png");
    sf::Sprite background_sprite(background_texture);
    //Init Bird
    Bird bird;
    //Sound system
    sf::Sound sound;
    sf::SoundBuffer hit;
    sf::SoundBuffer lose;
    sf::SoundBuffer wing;
    sf::SoundBuffer point;
    hit.loadFromFile("data/sfx_hit.wav");
    lose.loadFromFile("data/sfx_die.wav");
    wing.loadFromFile("data/sfx_wing.wav");
    point.loadFromFile("data/sfx_point.wav");
    srand(time(nullptr));
    //Text stuff
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
        //Game main loop
        while(running){
        
            window.clear();
            //Creating new objects
            if(obj.empty() == true || obj[obj.size()-1][0].des.x < 550){
                int h1 = rand() % 351 + 50;
                int h2 = rand() % 351 + 50;
                //Get random numbers for objects and control them not to be very small nor big
                while(h1 + h2 >= 420 || h1 + h2 <= 400 || abs(obj[obj.size()-1][0].des.y - h1) > 200 ){
                    h1 = rand() % 351 + 50;
                    h2 = rand() % 351 + 50;
                }
                
                obj_t.push_back(Object(float(h1),true));
                obj_t.push_back(Object(float(h2),false));
                obj.push_back(obj_t);
                obj_t.clear();
            }
        score.setString(bird.score_return());
        window.draw(background_sprite);
        window.draw(bird.bird_sprite);
        window.draw(score);
        //Bird default speed horizontally
        bird + 0.01;
        //Moving objects , There is 2 loop because i don't want to move all elements (For ex 100) and just move elements that user can see to decrease loop time
        if(obj.size() < 6){
        for(int i = 0; i < obj.size() ; i++){
           if(i>1){
            window.draw(obj[i][0].object_rect);
            window.draw(obj[i][1].object_rect);
            //Check if bird hits the objects or not and play sound and make main boolean false
            if(obj[i][0].object_rect.getGlobalBounds().intersects(bird.bird_sprite.getGlobalBounds()) || obj[i][1].object_rect.getGlobalBounds().intersects(bird.bird_sprite.getGlobalBounds())){
                    sound.setBuffer(hit);
                    sound.play();
                    running = false;
                    gameover = true;
                }
                //Add score, 1 per object
            if(obj[i][0].des.x < 200 && obj[i][0].score_check == false){
                sound.setBuffer(point);
                sound.play();
                bird.score++;
                obj[i][0].score_check = true;
            }
           }
            obj[i][1] + (-0.02);
            obj[i][0] + (-0.02);
        }
        }else{

           for(int i = obj.size()-4; i < obj.size() ; i++){
               
            window.draw(obj[i][0].object_rect);
            window.draw(obj[i][1].object_rect);
            obj[i][1] + (-0.02);
            obj[i][0] + (-0.02);
            if(obj[i][0].object_rect.getGlobalBounds().intersects(bird.bird_sprite.getGlobalBounds()) || obj[i][1].object_rect.getGlobalBounds().intersects(bird.bird_sprite.getGlobalBounds())){
                    sound.setBuffer(hit);
                    sound.play();
                    running = false;
                    gameover = true;
                }
            if(obj[i][0].des.x < 200 && obj[i][0].score_check == false){
                sound.setBuffer(point);
                sound.play();
                bird.score++;
                obj[i][0].score_check = true;
            }
        } 
        }
        window.display();
        //Handling events like closing the game or pessing space
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
                        sound.setBuffer(wing);
                        sound.play();
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
        //If the bird hits the ground, will lose
        if(bird.des.y > 470){
                running = false;
                gameover = true;
            }
        }
        if(bird.score < 20){
            sound.setBuffer(lose);
            sound.play();
            //Set Gameover and score text
            text.setString("GAME OVER!");
            text.setStyle(sf::Text::Bold);
            text.setColor(sf::Color::Red);
            text.setCharacterSize(200);
            text.setPosition(100,10);
            score.setString("Score: " + bird.score_return());
            score.setColor(sf::Color::Blue);
            score.setCharacterSize(150);
            score.setPosition(200,200);
            window.draw(score);
            window.draw(text);
            window.display();
        
        }else{
            sound.setBuffer(lose);
            sound.play();
            //Set Gameover and score text
            text.setString("YOU WIN!");
            text.setStyle(sf::Text::Bold);
            text.setColor(sf::Color::Yellow);
            text.setCharacterSize(200);
            text.setPosition(100,10);
            score.setString("Score: " + bird.score_return());
            score.setColor(sf::Color::Blue);
            score.setCharacterSize(150);
            score.setPosition(200,200);
            window.draw(score);
            window.draw(text);
            window.display();
        }
        running = true;
        //End game menu
        sf::Texture exit;
        exit.loadFromFile("data/exit.png");
        sf::Sprite e_sprite;
        e_sprite.setTexture(exit);
        e_sprite.setPosition(200,400);
        sf::Texture again;
        again.loadFromFile("data/replay.png");
        sf::Sprite a_sprite;
        a_sprite.setTexture(again);
        a_sprite.setPosition(400,400);
        window.draw(e_sprite);
        window.draw(a_sprite);
        window.display();
        
        while(running){
                if(event.type == sf::Event::Closed){
                    window.close();
                    return 0;
                    break;
                }
            
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::FloatRect e_bounds = e_sprite.getGlobalBounds();
        sf::FloatRect again_bound = a_sprite.getGlobalBounds();
    //Chech if player press exit or playagain button
    if (e_bounds.contains(mouse))
    {
        window.close();
        return 0;
    }
    if(again_bound.contains(mouse)){
        running = true;
        goto Start;
    }
    }
        }
    //return 0;
}