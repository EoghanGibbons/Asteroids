#include "gameObject.h"
#include <iostream>
#include <math.h>

gameObject::gameObject(sf::Vector2f pPos, sf::Vector2f pVel):
position(pPos), velocity(pVel), health(4), range(15) {
	direction = sf::Vector2f(0, 0);
}

gameObject::gameObject(sf::Vector2f pPos, float pAngle, float pSpeed) :
position(pPos), angularRotation(pAngle), speed(pSpeed) {
	sprite.setRotation(pAngle);
	direction = sf::Vector2f((cos((sprite.getRotation() + 90)* PI / 180)*-1), (sin((sprite.getRotation() + 90)* PI / 180))*-1);
}

gameObject::~gameObject() {}

float gameObject::lenght(sf::Vector2f vec) {
	return ((vec.x * vec.x) + ((vec.y * vec.y)));
}

sf::Vector2f gameObject::normalise(sf::Vector2f vec){
	//if (lenght(vec))
	return (vec / lenght(vec));
}

void gameObject::thrust() {
	if (speed < MAX_SPEED)
		speed += 10;
	else
		speed = MAX_SPEED;
}

void gameObject::reverse() {
	if (speed > -MAX_SPEED)
		speed -= 10;
	else
		speed = -MAX_SPEED;
}

float gameObject::angleBetween(sf::Vector2f vec1, sf::Vector2f vec2){
	if (vec1.x == 0 && vec1.y == 0) return 0.0f;
	if (vec2.x == 0 && vec2.y == 0) return 0.0f;
	
	//vec1 = normalise(vec1);
	//vec2 = normalise(vec2);
	float x = dotProduct(vec1, vec2);
	if (x <= -1) {
		return PI;
	}
	else if (x >= 1) {
		return 0;
	} 
	return acos(x);
}

float gameObject::dotProduct(sf::Vector2f vec1, sf::Vector2f vec2) {
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) );
}

sf::Sprite gameObject::returnDrawable(){
	return sprite;
}

/////////////////////////////
//////Updater Functions//////
/////////////////////////////

//update objects that move in straight lines
void gameObject::update(float time) {
	velocity = sf::Vector2f(direction * speed * time);
	position += velocity;
	sprite.setPosition(position);
}

//Update an Ai Object
void gameObject::update(sf::Vector2f maxExtends, float time) {
	wrapRound(maxExtends);

	sprite.setRotation(angularRotation);
	direction = sf::Vector2f((cos((sprite.getRotation() + 90)* PI / 180)*-1), (sin((sprite.getRotation() + 90)* PI / 180))*-1);
	velocity = sf::Vector2f(direction * speed * time);

	position += velocity;
	sprite.setPosition(position);
}

//Update a controlable object
void gameObject::update(sf::Vector2f maxExtends, float time, bool controlable) {
	angularRotation += angularVelocity*time;
	if (angularVelocity > MAX_ANGULAR_VELOCTIY){
		angularVelocity = MAX_ANGULAR_VELOCTIY;
	}
	else if (angularVelocity < -1 * MAX_ANGULAR_VELOCTIY){
		angularVelocity = MAX_ANGULAR_VELOCTIY * -1;
	}

	//Drag
	angularVelocity *= .9;

	direction = sf::Vector2f((cos((sprite.getRotation() + 90)* PI / 180)*-1), (sin((sprite.getRotation() + 90)* PI / 180))*-1);
	velocity = sf::Vector2f(direction * speed * time);

	wrapRound(maxExtends);

	position += velocity;
	sprite.setRotation(angularRotation);
	sprite.setPosition(position);
}

void gameObject::wrapRound(sf::Vector2f maxExtends){
	if (position.x > maxExtends.x){
		position.x = 0;
	}
	else if (position.x < 0){
		position.x = maxExtends.x;
	}

	if (position.y > maxExtends.y + 100){
		position.y = 0;
	}
	else if (position.y < 0){
		position.y = maxExtends.y - (sprite.getGlobalBounds().height);
	}
}