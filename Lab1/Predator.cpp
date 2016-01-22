#include "Predator.h"

//Constructor
Predator::Predator(std::string name, float pXPos, float pYPos, float pXVel, float pYVel) :
gameObject(pXPos, pYPos, pXVel, pYVel) {
	texture.loadFromFile(name + ".png");
	gameObject::sprite.setTexture(texture);
	currentState = State::seeking;
}

void Predator::update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time) {
	seek(playerPos);
	//if (lenght(playerPos) - lenght(position) < 50){
	//	arrive(20, 50, playerPos, time);
	//}

	//call intelligence methods
	if (true /* playerDistance < range*/){
		fire();
	}

	if (true /* if seek has confirmed for us that a predator is engaged in combat with the player */) {
		flock();
	}

	gameObject::update(maxExtends, time);
}

sf::Sprite Predator::returnDrawable() {
	return gameObject::sprite;
}

void Predator::seek(sf::Vector2f playerPos) {
	gameObject::sprite.setRotation(gameObject::angleBetween(gameObject::position, playerPos));
	gameObject::speed = 20;
}

void Predator::flock() {
	//this needs much further consideration, HOWEVER, my current understanding is that
	//if there is one predator ship already engaged in combat with the player the rest
	//should flock to it and engage the player from stratigic angels
}

void Predator::fire() {
	//Fire at the player, if you think you can hit him
}

void Predator::arrive(float arriveRadius, float slowRadius, sf::Vector2f playerPos, float time){
	sf::Vector2f direction = playerPos - position;
	float distance = lenght(direction);
	float targetSpeed;
	if (distance > arriveRadius){
		targetSpeed = 0;
	}
	else if (distance > slowRadius){
		targetSpeed = MAX_SPEED;
	}
	else {
		targetSpeed = MAX_SPEED *(distance / slowRadius);
	}
	sf::Vector2f targetVelocity = direction;
	targetVelocity = normalise(targetVelocity);
	targetVelocity = targetVelocity * targetSpeed;
	speed = speed * (time * 60);
	/*if (lenght(speed) > MAX_speedERATION) {
		speed = normalise(speed);
		speed = speed * MAX_speedERATION;
	}*/
}