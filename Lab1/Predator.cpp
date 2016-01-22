#include "Predator.h"
#include <iostream>

//Constructor
Predator::Predator(std::string name, sf::Vector2f pPos) :
gameObject(pPos) {
	texture.loadFromFile(name + ".png");
	gameObject::sprite.setTexture(texture);
	currentState = State::seeking;
}

void Predator::update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time) {
	if (currentState == State::seeking){
		seek(playerPos);
	}
	else {

	}

	//call intelligence methods
	if (true /* playerDistance < range*/){
		fire();
	}

	if (true /* if seek has confirmed for us that a predator is engaged in combat with the player */) {
		flock();
	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].update(time);
	}

	gameObject::update(maxExtends, time);
}

void Predator::seek(sf::Vector2f playerPos) {
	gameObject::angularRotation = gameObject::angleBetween(playerPos, gameObject::position);
	gameObject::speed = 250;
}

void Predator::flock() {
}

void Predator::fire() {
	bullets.push_back(Bullet(gameObject::position, gameObject::sprite.getRotation(), 600));
}

void Predator::arrive(float arriveRadius, float slowRadius, sf::Vector2f playerPos, float time){
	/* sf::Vector2f direction = playerPos - position;
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
	if (lenght(speed) > MAX_speedERATION) {
		speed = normalise(speed);
		speed = speed * MAX_speedERATION;
	}*/
}