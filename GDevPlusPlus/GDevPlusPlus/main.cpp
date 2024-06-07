// main script from which everything is started

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Vector2.h"
#include "Shape.h"
#include "Circle.h"
#include "Rigidbody.h"

#include "Player.h"

// window
int windowWidth = 480;
int windowHeight = 640;

sf::Clock deltaClock;

Player* player;
Vector2 inputDir;

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");

    //auto circle = Circle{ 50 };
    //circle.SetPosition(Vector2{ (float)windowWidth / 2, (float)windowHeight / 2 });
    //auto rb = Rigidbody{ 1 };

    player = new Player{ 40, 2, 0, Vector2(windowWidth/2,windowHeight/6 * 5), 1 };
    inputDir = Vector2();

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        // calculate deltatime
        auto deltaTime = deltaClock.restart().asSeconds();
        std::cout << "dt = " << deltaTime << " s" << std::endl;

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

        std::cout << "Input direction: " << inputDir.x << std::endl;
        //rb.UpdateRigidbody(Vector2(), deltaTime);

        window.clear();

        //circle.SetPosition(rb.GetNewPosition(circle.GetPosition(), rb.velocity, rb.acceleration, deltaTime));
        //circle.draw(window);

        player->UpdatePlayer(inputDir, window, deltaTime);

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