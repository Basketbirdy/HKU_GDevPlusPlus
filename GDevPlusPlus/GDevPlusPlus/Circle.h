#pragma once
#include "Shape.h"
#include "Vector2.h"

class Circle : public Shape
{
private:

public:
	float radius;
	Circle();
	Circle(float r);
	//Circle(const Circle& other);

	Vector2& GetPosition();
	float area();
	virtual void draw(sf::RenderWindow& window);
};

