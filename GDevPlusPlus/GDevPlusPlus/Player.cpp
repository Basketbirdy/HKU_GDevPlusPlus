#include <iostream>

#include "Player.h"
#include "Circle.h"

Player::Player(float radius, float movementForce, Vector2 pos, float mass): radius(radius), movementForce(movementForce) {
	rb = Rigidbody(pos, mass, 0.01);
	body = Circle(radius);
}

Player::Player(const Player& other)
{
	radius = other.radius;
	movementForce = other.movementForce;
	body = other.body;
	rb = other.rb;
}

Player& Player::operator=(const Player& other) {
	if (this != &other) {
		radius = other.radius;
		movementForce = other.movementForce;
		body = other.body;
		rb = other.rb;
	}

	return *this;
}

Player::~Player()
{
}

// function that should get called in the main function window while loop
void Player::UpdatePlayer(Vector2 input, sf::RenderWindow& window, float dt)
{
	//Vector2 drag = rb.CalculateDrag(rb.frictionCoefficient, rb.velocity);
	//std::cout << "drag: " << drag.x << "," << drag.y << std::endl;

	//Vector2 force = input.Multiply(movementForce) - drag;
	//std::cout << "force: " << force.x << "," << force.y << std::endl;

	////rb.acceleration = rb.CalculateAcceleration(input, rb.mass);
	////std::cout << "acceleration: " << rb.acceleration.x << "," << rb.acceleration.y << std::endl;

	//Vector2 impulse = force * dt;
	//rb.velocity = impulse / rb.mass + rb.velocity;
	//std::cout << "velocity: " << rb.velocity.x << "," << rb.velocity.y << std::endl;

	//Vector2 newPos = rb.pos + (rb.velocity * rb.mass);
	//std::cout << "newPos: " << newPos.x << "," << newPos.y << std::endl;

	body.SetPosition(rb.pos);
	body.draw(window);
}
