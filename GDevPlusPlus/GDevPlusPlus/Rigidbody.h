#pragma once

#include "Vector2.h"

class Rigidbody
{
private:

	Vector2 g = Vector2{ 0, 9.81f };
	enum ForceMode
	{
		Force,
		Impulse
	};

public:
	float mass;
	float frictionCoefficient;

	Vector2 pos;

	Vector2 velocity;
	Vector2 acceleration;

	Rigidbody();
	Rigidbody(float mass, float frictionCoefficient);
	Rigidbody(Vector2 pos, float mass, float frictionCoefficient);
	~Rigidbody();

	Vector2 GetNewVelocity(Vector2 initialVelocity, Vector2 acceleration, float time);
	Vector2 GetNewPosition(Vector2 currentPosition, Vector2 initialVelocity, Vector2 acceleration, float time);

	void AddForce(Vector2 direction, float strength, ForceMode mode, float dt);

	Vector2 CalculateGravity(float m);
	Vector2 CalculateDrag(float friction, Vector2 v);

	Vector2 CalculateAcceleration(Vector2 f, float m);

	void UpdateRigidbody(Vector2 force, float dt);
};



