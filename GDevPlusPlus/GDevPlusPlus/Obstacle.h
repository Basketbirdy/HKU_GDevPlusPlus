#pragma once

#include "Circle.h"
#include "Vector2.h"
#include "Rigidbody.h"

class Obstacle
{
private:
	float radius;
	float movementForce;
	float gravity;

public:
	Circle body;
	Rigidbody rb;

	Obstacle(float radius, float movementForce, float gravity, float mass, Vector2 pos);
	~Obstacle();

	Obstacle(const Obstacle& other);
	Obstacle& operator=(const Obstacle& other);

	void Update(Vector2 dir, sf::RenderWindow& window, float dt);
};

