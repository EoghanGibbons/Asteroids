#include "gameObject.h"

gameObject::gameObject(float pXPos, float pYPos, float pXVel, float pYVel):
health(4), range(15) {
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

void gameObject::update(float time){

	sf::Vector2f nextVelocity(accel * time);
	
	if ( lenght(nextVelocity) > MAX_SPEED ) {
		sf::Vector2f normalisedVelocity = normalise(nextVelocity);
	}
	position = position + velocity* time;
}