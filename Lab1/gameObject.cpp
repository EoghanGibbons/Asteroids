#include "gameObject.h"

gameObject::gameObject(float pXPos, float pYPos, float pXVel, float pYVel):
health(4), range(15) {
	position.x = pXPos;
	position.y = pYPos;
	velocity.x = pXVel;
	velocity.y = pYVel;
	direction = sf::Vector2f(0, 0);
}

gameObject::~gameObject() {

}

float gameObject::lenght(sf::Vector2f vec) {
	return ((vec.x * vec.x) + ((vec.y * vec.y)));
}

sf::Vector2f gameObject::normalise(sf::Vector2f vec){
	//if (lenght(vec))
	return (vec / lenght(vec));
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

	direction = sf::Vector2f(cos( 0 * PI / 180), sin( 0 * PI / 180));

	sf::Vector2f nextVelocity(direction * speed * time);
	
	if ( lenght(nextVelocity) > MAX_SPEED ) {
		velocity = normalise(nextVelocity);
	}
	position = position + velocity* time;
}

void gameObject::update(sf::Vector2f maxExtends, float time, bool controlable) { //controllable gameObject
	angularRotation += angularVelocity*time;
	if (angularVelocity > MAX_ANGULAR_VELOCTIY){
		angularVelocity = MAX_ANGULAR_VELOCTIY;
	}
	else if (angularVelocity < -1 * MAX_ANGULAR_VELOCTIY){
		angularVelocity = MAX_ANGULAR_VELOCTIY * -1;
	}
	
	direction = sf::Vector2f((cos((sprite.getRotation() + 90)* PI / 180)*-1), (sin((sprite.getRotation() + 90)* PI / 180) )*-1 );
	sf::Vector2f nextVelocity(direction * speed * time);

	if (lenght(nextVelocity) > MAX_SPEED) {
		velocity = normalise(nextVelocity);
	}
	else {
		velocity = nextVelocity;
	}

	position += velocity;

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

	sprite.setRotation(angularRotation);
	sprite.setPosition(position);
}

void gameObject::thrust() {
	speed += 10;
}

void gameObject::reverse() {
	speed -= 10;
}