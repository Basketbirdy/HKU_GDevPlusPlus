#pragma once

#include <SFML/Graphics.hpp>

#include "Vector2.h"

class Shape
{
private:

protected:
	float alpha = 1;
	Vector2 pos;

public:
	Shape();
	~Shape();

	Shape(const Shape& other);
	Shape& operator=(const Shape& other);

	void SetAlpha(float a);
	void SetPosition(Vector2 pos);

	virtual Vector2& GetPosition() = 0;
	virtual float area(); // = 0, word niet gedefinieerd in deze class, MOET in subclass
	virtual void draw(sf::RenderWindow& window);
};



