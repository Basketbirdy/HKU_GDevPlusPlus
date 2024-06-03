#pragma once

#include "Vector2.h"

class Rigidbody
{
private:

	Vector2 g = Vector2{ 0, 9.81f };

public:
	float mass;
	Vector2 velocity;
	Vector2 acceleration;

	Rigidbody(float mass);
	Vector2 GetNewVelocity(Vector2 initialVelocity, Vector2 acceleration, float time);
	Vector2 GetNewPosition(Vector2 currentPosition, Vector2 initialVelocity, Vector2 acceleration, float time);

	//AddForce(float force, Vector2 direction);
	//AddDrag(float mass);

	Vector2 CalculateGravity(float m, Vector2 g);
	Vector2 CalculateDrag(float f, Vector2 v);

	Vector2 CalculateAcceleration(Vector2 f, float m);

	void UpdateRigidbody(float dt);
};



