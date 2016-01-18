#include "gameObject.h"

gameObject::gameObject(float pXPos, float pYPos, float pXVel, float pYVel){
	position.x = pXPos;
	position.y = pYPos;
	velocity.x = pXVel;
	velocity.y = pYVel;
}

float gameObject::lenght(sf::Vector2f vec) {
	return ((vec.x * vec.x) + ((vec.y * vec.y)));
}

sf::Vector2f gameObject::normalise(sf::Vector2f vec){
	return velocity;
}