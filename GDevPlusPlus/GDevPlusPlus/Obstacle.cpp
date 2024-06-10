#include "Obstacle.h"

#include <iostream>

Obstacle::Obstacle(float radius, float movementForce, float gravity, float mass, Vector2 pos) : 
	radius(radius), movementForce(movementForce), gravity(gravity) {
	rb = Rigidbody{ pos, mass, Vector2 { 7, .6f } };
	body = Circle{ radius };

	if (std::rand() >= 0.5) {
		dir = Vector2{ 1, 0 };
	}
	else {
		dir = Vector2{ -1, 0 };
	}

	passedPlayer = false;
}

Obstacle::~Obstacle()
{

}

Obstacle::Obstacle(const Obstacle& other)
{
	radius = other.radius;
	movementForce = other.movementForce;
	gravity = other.gravity;
	body = other.body;
	rb = other.rb;
}

Obstacle& Obstacle::operator=(const Obstacle& other) {
	if (this != &other) {
		radius = other.radius;
		movementForce = other.movementForce;
		gravity = other.gravity;
		body = other.body;
		rb = other.rb;
	}

	return *this;
}

void Obstacle::Update(sf::RenderWindow& window, float dt)
{
	Vector2 force = dir * (movementForce * 1000);
	rb.UpdateRigidbody(force, gravity, dt);

	if (rb.pos.x - (rb.velocity.x * dt) - radius < 0 && dir.x == -1) {
		dir = Vector2{ 1, 0 };
		rb.velocity.x *= 0;
		std::cout << "obstacleDir = " << dir.x << std::endl;
	}
	else if (rb.pos.x + (rb.velocity.x * dt) + radius > window.getSize().x && dir.x == 1) {
		dir = Vector2{ -1, 0 };
		rb.velocity.x *= 0;
		std::cout << "obstacleDir = " << dir.x << std::endl;
	}

	// if obstacle reaches the player
	if (rb.pos.y + radius >= window.getSize().y / 6 * 5) {

	}

	body.SetPosition(rb.pos);
	body.draw(window);
}

