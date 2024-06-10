#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Rigidbody.h"
#include "Circle.h"

class Entity
{
protected:
	float radius;
	float movementForce;
	float gravity;

public:
	Circle body;
	Rigidbody rb;

	Entity();
	Entity(float radius, float movementForce, float gravity, Vector2 pos, float mass);
	~Entity();

	virtual void Update(Vector2 dir, sf::RenderWindow& window, float dt);
};

