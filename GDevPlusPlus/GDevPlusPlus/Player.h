#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Rigidbody.h"
#include "Circle.h"

class Player
{
private:
	float radius;
	float movementForce;

public:
	Circle body;
	Rigidbody rb;

	Player(float radius, float movementForce, Vector2 pos, float mass);
	Player(const Player& other);
	Player& operator=(const Player& other);
	~Player();

	void UpdatePlayer(Vector2 input, sf::RenderWindow& window, float dt);
};

