#include "Rigidbody.h"

#include "Vector2.h"

#include <iostream>

Rigidbody::Rigidbody(float mass) : mass(mass) {
	velocity = Vector2();
	acceleration = Vector2();
}

Vector2 Rigidbody::GetNewVelocity(Vector2 initialVelocity, Vector2 acceleration, float time)
{
	Vector2 newVelocity = initialVelocity + acceleration * time;
	return newVelocity;
}

Vector2 Rigidbody::GetNewPosition(Vector2 currentPosition, Vector2 initialVelocity, Vector2 acceleration, float time) {
	Vector2 deltaPos = initialVelocity * time + acceleration * .5f * time * time;
	return currentPosition + deltaPos;
}

Vector2 Rigidbody::CalculateGravity(float m, Vector2 g) {
	return g * m;
}

Vector2 Rigidbody::CalculateDrag(float friction, Vector2 v) {
	float xDrag = friction * v.x;
	float yDrag = friction * v.y;
}

Vector2 Rigidbody::CalculateAcceleration(Vector2 f, float m) {
	return f / m;
}

void Rigidbody::UpdateRigidbody(float dt) {
	acceleration = CalculateAcceleration(Vector2{ 10, 10 }, mass);
	velocity = GetNewVelocity(velocity, acceleration, dt);

	std::cout << "velocity: " << velocity.x << ", " << velocity.y << std::endl;
}


