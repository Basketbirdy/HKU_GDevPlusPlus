#include <iostream>

#include "Player.h"
#include "Circle.h"

Player::Player(float radius, float movementForce,float gravity, Vector2 pos, float mass): radius(radius), movementForce(movementForce), gravity(gravity) {
	rb = Rigidbody(pos, mass, Vector2{ 7,.6 });
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
	rb.UpdateRigidbody(input * (movementForce * 1000), gravity, dt);

	body.SetPosition(rb.pos);
	body.draw(window);
}
