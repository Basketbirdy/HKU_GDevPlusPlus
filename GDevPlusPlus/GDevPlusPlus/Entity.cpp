#include "Entity.h"

Entity::Entity() {

}

Entity::Entity(float radius, float movementForce, float gravity, Vector2 pos, float mass): radius(radius), movementForce(movementForce), gravity(gravity){
	rb = Rigidbody(pos, mass, Vector2{ 7,.6 });
	body = Circle(radius);
}

Entity::~Entity() {
}

void Entity::Update(Vector2 dir, sf::RenderWindow& window, float dt) {
}
