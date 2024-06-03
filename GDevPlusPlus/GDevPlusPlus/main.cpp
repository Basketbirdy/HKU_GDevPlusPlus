// main script from which everything is started

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Vector2.h"
#include "Shape.h"
#include "Circle.h"
#include "Rigidbody.h"


sf::Clock deltaClock;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");

    auto circle = Circle{ 50 };
    auto rb = Rigidbody{ 10 };

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

        rb.UpdateRigidbody(deltaTime);

        window.clear();
        
        circle.SetPosition(rb.GetNewPosition(circle.GetPosition(), rb.velocity, rb.acceleration, deltaTime));
        circle.draw(window);

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