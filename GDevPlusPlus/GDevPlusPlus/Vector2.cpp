#include "Vector2.h"

#include <iostream>

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(float x = 0, float y = 0) : x(x), y(y) {
}

// converts my vector2 class into a sfml vector2f class
sf::Vector2f Vector2::sfVector() 
{
	return sf::Vector2f(x, y);
}

Vector2::~Vector2() {
}

float Vector2::Length() {
	return std::sqrt(x * x + y * y);
}

// normalizes the vector length to 1
Vector2 Vector2::Normalize() {
	float length = Vector2::Length();

	float newX = x / length;
	float newY = y / length;

	return Vector2(newX, newY);
}

Vector2 Vector2::Add(Vector2 v) {
	float newX = x + v.x;
	float newY = y + v.y;
	return Vector2::Vector2(newX, newY);
}

Vector2 Vector2::Subtract(Vector2 v) {
	float newX = x - v.x;
	float newY = y - v.y;
	return Vector2::Vector2(newX, newY);
}

Vector2 Vector2::Multiply(float scalar)
{
	float newX = x * scalar;
	float newY = y * scalar;
	return Vector2::Vector2(newX, newY);
}

Vector2 Vector2::Divide(float scalar)
{
	float newX = x / scalar;
	float newY = y / scalar;
	return Vector2::Vector2(newX, newY);
}

float Vector2::Dot(Vector2 v) {
	return (x * v.x) + (y * v.y);
}

Vector2 operator+(Vector2 v1, Vector2 v2) {
	return v1.Add(v2);
}

Vector2 operator-(Vector2 v1, Vector2 v2) {
	return v1.Subtract(v2);
}

Vector2 operator*(Vector2 v1, float scalar) {
	return v1.Multiply(scalar);
}

Vector2 operator/(Vector2 v1, float scalar) {
	return v1.Divide(scalar);
}

void Vector2::PrintVector() {
	std::cout << "x: " << x << ", y: " << y << std::endl;
}
