#include "Rigidbody.h"

#include "Vector2.h"

#include <iostream>

Rigidbody::Rigidbody() : mass(10), frictionCoefficient(.1) {
	pos = Vector2{ 0,0 };
	velocity = Vector2(0, -10);
	acceleration = Vector2();
}

Rigidbody::Rigidbody(float mass, float frictionCoefficient) : mass(mass), frictionCoefficient(frictionCoefficient) {
	pos = Vector2{ 0,0 };
	velocity = Vector2(0, -10);
	acceleration = Vector2();
}

Rigidbody::Rigidbody(Vector2 pos, float mass, float frictionCoefficient): pos(pos), mass(mass), frictionCoefficient(frictionCoefficient) {
}

Rigidbody::~Rigidbody(){
}

Vector2 Rigidbody::GetNewVelocity(Vector2 initialVelocity, Vector2 acceleration, float time)
{
	Vector2 newVelocity = initialVelocity + acceleration * time;
	return newVelocity;
}

Vector2 Rigidbody::GetNewPosition(Vector2 currentPosition, Vector2 initialVelocity, Vector2 acceleration, float time) {
	Vector2 deltaPos = initialVelocity * time + (acceleration * .5f) * time * time;
	return currentPosition + deltaPos;
}

void Rigidbody::AddForce(Vector2 direction, float strength, ForceMode mode, float dt)
{
	switch (mode) {
	case Force:
		velocity = velocity + (direction * strength) * dt / mass;
		break;
	case Impulse:
		velocity = velocity + (direction * strength) / mass;
		break;
	}
}

Vector2 Rigidbody::CalculateGravity(float m) {
	Vector2 gravity = g * m;
	std::cout << "gravity: " << gravity.x << ", " << gravity.y << std::endl;
	return gravity;
}

Vector2 Rigidbody::CalculateDrag(float friction, Vector2 v) {
	float xDrag = friction * v.x;
	float yDrag = friction * v.y;
	return Vector2{ xDrag, yDrag };
}

Vector2 Rigidbody::CalculateAcceleration(Vector2 f, float m) {
	return f / m;
}

void Rigidbody::UpdateRigidbody(Vector2 force, float dt) {
	acceleration = CalculateAcceleration(CalculateGravity(mass), mass);
	velocity = GetNewVelocity(velocity, acceleration, dt);

	std::cout << "acceleration: " << acceleration.x << ", " << acceleration.y << std::endl;
	std::cout << "velocity: " << velocity.x << ", " << velocity.y << std::endl;
}


