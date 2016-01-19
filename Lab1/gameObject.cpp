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

void gameObject::update(sf::Vector2f maxExtends, float time) {
#pragma region Wrap Around World
	if (position.x > maxExtends.x){
		position.x = -1 * width;
	}
	else if (position.x < -1 * width){
		position.x = maxExtends.x;
	}

	if (position.y > maxExtends.y){
		position.y = -1 * height;
	}
	else if (position.y < -1 * height){
		position.y = maxExtends.y;
	}
#pragma endregion

	sf::Vector2f nextVelocity(accel * time);
	
	if ( lenght(nextVelocity) > MAX_SPEED ) {
		sf::Vector2f normalisedVelocity = normalise(nextVelocity);
	}
	position = position + velocity* time;
}