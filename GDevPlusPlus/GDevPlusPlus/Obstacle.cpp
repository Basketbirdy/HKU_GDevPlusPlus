#include "Obstacle.h"

Obstacle::Obstacle(float radius, float movementForce, float gravity, float mass, Vector2 pos) : 
	radius(radius), movementForce(movementForce), gravity(gravity) {
	rb = Rigidbody{ pos, mass, Vector2 { 7, .6f } };
	body = Circle{ radius };
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

void Obstacle::Update(Vector2 dir, sf::RenderWindow& window, float dt)
{
	Vector2 force = dir * movementForce;
	rb.UpdateRigidbody(force, gravity, dt);

	body.SetPosition(rb.pos);
	body.draw(window);
}

