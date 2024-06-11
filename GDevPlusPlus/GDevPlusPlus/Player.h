#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Rigidbody.h"
#include "Circle.h"
#include "Entity.h"

class Player
{
private:
	float radius;
	float movementForce;
	float gravity;

public:
	Circle body;
	Rigidbody rb;

	sf::Sprite sprite;

	Player(float radius, float movementForce, float gravity, Vector2 pos, float mass, sf::Sprite sprite);
	Player(const Player& other);
	Player& operator=(const Player& other);
	~Player();

	void Update(Vector2 input, sf::RenderWindow& window, float dt);
};

