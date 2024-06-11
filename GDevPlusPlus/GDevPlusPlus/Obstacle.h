#pragma once

#include "Circle.h"
#include "Vector2.h"
#include "Rigidbody.h"
#include "Player.h"

class Obstacle
{
private:
	float radius;
	float movementForce;
	float gravity;

public:
	Circle body;
	Rigidbody rb;

	sf::Sprite sprite;

	Vector2 dir;
	bool passedPlayer = false;

	Obstacle(float radius, float movementForce, float gravity, float mass, Vector2 pos, sf::Sprite sprite);
	~Obstacle();

	Obstacle(const Obstacle& other);
	Obstacle& operator=(const Obstacle& other);

	void Update(sf::RenderWindow& window, float dt);
};

