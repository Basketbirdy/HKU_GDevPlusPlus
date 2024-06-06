#pragma once
#include "Shape.h"
#include "Vector2.h"

class Circle : public Shape
{
private:
	float radius;

public:
	Circle();
	Circle(float r);
	//Circle(const Circle& other);

	Vector2& GetPosition();
	float area();
	virtual void draw(sf::RenderWindow& window);
};

