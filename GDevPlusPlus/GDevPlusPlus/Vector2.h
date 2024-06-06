#pragma once

#include <SFML/Graphics.hpp>

class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);
	sf::Vector2f sfVector();
	virtual ~Vector2();

	float Length();
	Vector2 Normalize();

	Vector2 Add(Vector2 v);
	Vector2 Subtract(Vector2 v);
	Vector2 Multiply(float scalar);
	Vector2 Divide(float scalar);
	float Dot(Vector2 v);

	friend Vector2 operator+(Vector2 v1, Vector2 v2);
	friend Vector2 operator-(Vector2 v1, Vector2 v2);
	friend Vector2 operator*(Vector2 v1, float scalar);
	friend Vector2 operator/(Vector2 v1, float scalar);

	void PrintVector();

private:
};

