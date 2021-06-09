#include <SFML/Graphics.hpp>

#pragma once

class Game 
{
private:
    sf::RenderWindow mWindow;

    sf::Texture mTexture;   
    sf::Sprite  mPlayer;

    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;

    const float PlayerSpeed = 53.f;
    const sf::Time TimePerFrame = sf::seconds(1.f/60.f);

private:   
    void processEvents();
    void update(sf::Time deltaTime); 
    void render();

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

public:   
    Game();
        
    void run();
};