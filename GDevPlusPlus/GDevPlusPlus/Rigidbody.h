#pragma once

#include "Vector2.h"

class Rigidbody
{
private:

	Vector2 g = Vector2{ 0, 9.81 };

public:
	enum ForceMode
	{
		Force,
		Impulse
	};

	float mass;
	Vector2 frictionCoefficient;

	Vector2 pos;

	Vector2 velocity;
	Vector2 acceleration;

	Vector2 force;

	Rigidbody();
	Rigidbody(float mass, Vector2 frictionCoefficient);
	Rigidbody(Vector2 pos, float mass, Vector2 frictionCoefficient);
	~Rigidbody();

	Vector2 GetNewVelocity(Vector2 force, float time, ForceMode mode);
	Vector2 GetNewPosition(float time);

	Vector2 CalculateGravity(float gMultiplier);
	Vector2 CalculateDrag(Vector2 friction, Vector2 v);

	void UpdateRigidbody(Vector2 force, float gravity, float dt);
};



