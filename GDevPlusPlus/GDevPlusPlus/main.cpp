// main script from which everything is started

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Vector2.h"
#include "Shape.h"
#include "Circle.h"
#include "Rigidbody.h"

#include "Player.h"

#include "Obstacle.h"

// window
Vector2 windowSize = Vector2(480, 640);

sf::Clock deltaClock;
sf::Font font;

// player
Player* player;
Vector2 inputDir;

// obstacles
int obstacleCount = 10;

std::vector<Obstacle*> obstacles;

// points
sf::Text pointText;
int pointCount = 0;

// lives
sf::Text livesText;
int lifeCount = 3;

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Speedracer");
    window.setFramerateLimit(120);

    // fonts
    if (!font.loadFromFile("Assets/Fonts/VT323-Regular.ttf")) {

    }

    // text
    pointText.setFont(font);
    pointText.setCharacterSize(48);
    pointText.setPosition(24, 12);

    livesText.setFont(font);
    livesText.setCharacterSize(48);
    livesText.setPosition(windowSize.x - 168, 12);

    // player
    player = new Player{ 40, 2, 0, Vector2(windowSize.x/2,windowSize.y/6 * 5), 1 };
    inputDir = Vector2();

    // obstacle
    for (int i = obstacleCount; i > 0; i--) {
        int xRange = 6 - 1 + 1;
        int randomXPos = rand() % xRange + 1;
        int yRange = -30 - -2400 + 1;
        int randomYPos = rand() % yRange + -2400;
        obstacles.push_back(new Obstacle{ 25, 3, 5, 5, Vector2{ (float)windowSize.x / 6 * (float)randomXPos - 40, (float)randomYPos } });
    }

    // background
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("Assets/Images/BackgroundSprite.png")) {
        std::cout << "Nope, not loading" << std::endl;
    }

    sf::Sprite bgSprite(bgTexture);

    while (window.isOpen())
    {
        // calculate deltatime
        auto deltaTime = deltaClock.restart().asSeconds();
        //std::cout << "dt = " << deltaTime << " s" << std::endl;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // if player presses left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            inputDir.x = -1;
        }
        // if player presses right
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            inputDir.x = 1;
        }
        else {
            inputDir.x = 0;
        }

        //std::cout << "Input direction: " << inputDir.x << std::endl;
        //rb.UpdateRigidbody(Vector2(), deltaTime);

        window.clear();

        window.draw(bgSprite);
        
        player->Update(inputDir, window, deltaTime);
       

        for (int i = obstacles.size() - 1; i >= 0; i--) {
            Obstacle* currentObstacle = obstacles[i];
            currentObstacle->Update(window, deltaTime);
            
            // collision
            if ((currentObstacle->rb.pos - player->rb.pos).Length() < currentObstacle->body.radius + player->body.radius && !currentObstacle->passedPlayer) {
                // TODO - collide and end the game 
                lifeCount--;
                obstacles.erase(obstacles.begin() + i);
            }

            if (obstacles[i]->rb.pos.y > windowSize.y + 100) {
                pointCount++;
                obstacles.erase(obstacles.begin() + i);
                delete currentObstacle;
            }
        }

        pointText.setString("points: " + std::to_string(pointCount));
        window.draw(pointText);
        livesText.setString("lives: " + std::to_string(lifeCount));
        window.draw(livesText);

        window.display();
    }

    return 0;
}

// code for getting a button or key input once
//if (event.type == sf::Event::KeyPressed)
//{
//    if (event.key.code == sf::Keyboard::U)
//    {
//        std::cout << "the left mouse key was pressed" << std::endl;
//        std::cout << "control:" << event.key.control << std::endl;
//        std::cout << "alt:" << event.key.alt << std::endl;
//        std::cout << "shift:" << event.key.shift << std::endl;
//        std::cout << "system:" << event.key.system << std::endl;
//    }
//}

//if (event.type == sf::Event::MouseButtonPressed)
//{
//    if (event.mouseButton.button == sf::Mouse::Left)
//    {
//        std::cout << "the left button was pressed" << std::endl;
//        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
//        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
//    }
//}