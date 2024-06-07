#include "Rigidbody.h"

#include "Vector2.h"

#include <iostream>

Rigidbody::Rigidbody() : mass(10), frictionCoefficient(Vector2{7, 2}) {
	pos = Vector2{ 0,0 };
	velocity = Vector2(0, -10);
	acceleration = Vector2();
}

Rigidbody::Rigidbody(float mass, Vector2 frictionCoefficient) : mass(mass), frictionCoefficient(frictionCoefficient) {
	pos = Vector2{ 0,0 };
	velocity = Vector2(0, -10);
	acceleration = Vector2();
}

Rigidbody::Rigidbody(Vector2 pos, float mass, Vector2 frictionCoefficient): pos(pos), mass(mass), frictionCoefficient(frictionCoefficient) {
}

Rigidbody::~Rigidbody(){
}

Vector2 Rigidbody::GetNewVelocity(Vector2 force, float time)
{
	Vector2 newVelocity = velocity + force / mass * time;
	return newVelocity;
}

Vector2 Rigidbody::GetNewPosition(float time)
{
	Vector2 newPosition = pos + velocity * time;
	return newPosition;
}

Vector2 Rigidbody::CalculateGravity(float gMultiplier) {
	Vector2 gravity = g * gMultiplier * mass;
	std::cout << "gravity: " << gravity.x << ", " << gravity.y << std::endl;
	return gravity;
}

Vector2 Rigidbody::CalculateDrag(Vector2 friction, Vector2 v) {
	float xDrag = friction.x * v.x;
	float yDrag = friction.y * v.y;
	return Vector2{ -xDrag, -yDrag };
}

void Rigidbody::UpdateRigidbody(Vector2 force, float gravity, float dt) {

	Vector2 dragForce = CalculateDrag(frictionCoefficient, velocity);
	Vector2 gravityForce = CalculateGravity(gravity);
	Vector2 finalForce = force + gravityForce + dragForce;

	velocity = GetNewVelocity(finalForce, dt);
	pos = GetNewPosition(dt);

	//std::cout << "acceleration: " << acceleration.x << ", " << acceleration.y << std::endl;
	//std::cout << "velocity: " << velocity.x << ", " << velocity.y << std::endl;
}


