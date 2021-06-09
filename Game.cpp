#include "Game.hpp"

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event)) 
    {    
        switch(event.type)
        {
            case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;

            case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;

            case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::update(sf::Time deltaTime) 
{
    sf::Vector2f movement(0.f, 0.f);
    if(mIsMovingUp)
    {
        movement.y -= PlayerSpeed;
    }
    else if(mIsMovingDown)
    {
        movement.y += PlayerSpeed;
    }
    else if(mIsMovingLeft)
    {
        movement.x -= PlayerSpeed;
    }
    else if(mIsMovingRight)
    {
        movement.x += PlayerSpeed;
    }

    mPlayer.move(movement * deltaTime.asSeconds());

    mIsMovingUp = false;
    mIsMovingDown = false;
    mIsMovingLeft = false;
    mIsMovingRight = false;
} 

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if(key == sf::Keyboard::W)
    {
        mIsMovingUp = true;
    }
    else if(key == sf::Keyboard::S)
    {
        mIsMovingDown = true;
    }
    else if(key == sf::Keyboard::A)
    {
        mIsMovingLeft = true;
    }
    else if(key == sf::Keyboard::D)
    {
        mIsMovingRight = true;
    }
} 

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application"), mPlayer(),
    mIsMovingUp(false), mIsMovingDown(false), mIsMovingLeft(false), mIsMovingRight(false), mTexture()
{
    if(!mTexture.loadFromFile("Textures/Eagle.png"))
    {
        // Error
    }
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.f, 100.f);
} 

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())   
    {   
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}