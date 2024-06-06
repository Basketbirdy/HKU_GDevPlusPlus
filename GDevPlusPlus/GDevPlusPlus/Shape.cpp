#include "Shape.h"
#include "Vector2.h"

Shape::Shape() {
	pos = Vector2();
}

Shape::~Shape() {

}

Shape::Shape(const Shape& other) : alpha(other.alpha), pos(other.pos) {

}

Shape& Shape::operator=(const Shape& other)
{
	if (this == &other) { return *this; }

	alpha = other.alpha;
	pos.x = other.pos.x;
	pos.y = other.pos.y;

	// bgImage = other.bgImage;
	//delete bgImage;
	//bgImage = new sf::Image{};

	return *this;
}

void Shape::SetAlpha(float a) {
	alpha = a;
}

void Shape::SetPosition(Vector2 pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

Vector2& Shape::GetPosition() {
}

float Shape::area() {
	return 0;
}

void Shape::draw(sf::RenderWindow& window) {

}