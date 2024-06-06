#include "Circle.h"
#include "Vector2.h"

#include <math.h>
#include <SFML/Graphics.hpp>

Circle::Circle(): radius(10) {
}

Circle::Circle(float r) : radius(r) {

}

//Circle::Circle(const Circle& other) {
//	this->radius = other.radius;
//}

float Circle::area() {
	return 3.14159265358979323846 * (radius * radius);
}

void Circle::draw(sf::RenderWindow& window) {
	auto shape = sf::CircleShape(radius);
	shape.setFillColor(sf::Color::Blue);

	shape.setOrigin(radius, radius);
	shape.setPosition(pos.sfVector());

	window.draw(shape);
}

Vector2& Circle::GetPosition() {
	return pos;
}