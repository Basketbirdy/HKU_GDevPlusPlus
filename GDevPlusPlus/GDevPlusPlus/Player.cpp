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
	gravity = other.gravity;
	body = other.body;
	rb = other.rb;
}

Player& Player::operator=(const Player& other) {
	if (this != &other) {
		radius = other.radius;
		movementForce = other.movementForce;
		gravity = other.gravity;
		body = other.body;
		rb = other.rb;
	}

	return *this;
}

Player::~Player()
{
}

// function that should get called in the main function window while loop
void Player::Update(Vector2 input, sf::RenderWindow& window, float dt)
{
	rb.UpdateRigidbody(input * (movementForce * 1000), gravity, dt);

	// screen collision

	if (rb.pos.x - radius < 0) {
		rb.pos.x = 0 + radius;
	}
	else if (rb.pos.x + radius > window.getSize().x) {
		rb.pos.x = window.getSize().x - radius;
	}

	body.SetPosition(rb.pos);
	body.draw(window);
}
