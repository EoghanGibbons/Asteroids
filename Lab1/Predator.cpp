#include "Predator.h"

//Constructor
Predator::Predator(std::string name, float pXPos, float pYPos, float pXVel, float pYVel) :
gameObject(pXPos, pYPos, pXVel, pYVel) {
	texture.loadFromFile(name + ".png");
	sprite.setTexture(texture);

	//l8r m8
	//sprite.setScale(.5, .5);
	//sprite.setOrigin(width / 2, height / 2);
	angularRotation = 0;

	width = 173;
	height = 291;
}

void Predator::update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time) {
	seek(playerPos);

	if (lenght(playerPos) - lenght(position) < 50){
		arrive(20, 50, playerPos, time);
	}

	gameObject::update(maxExtends, time); 
	
	float nexAngularRoation = sprite.getRotation() * time;

	if (nexAngularRoation > MAX_ROTATION) {
		sprite.setRotation(MAX_ROTATION);
	}
	
	else if (-nexAngularRoation > MAX_ROTATION) {
		sprite.setRotation(-MAX_ROTATION);
	}
	//call intelligence methods

	if (true /* playerDistance < range*/){
		fire();
	}

	if (true /* if seek has confirmed for us that a predator is engaged in combat with the player */) {
		flock();
	}

	sprite.setPosition(position);
}

sf::Sprite Predator::returnDrawable() {
	return sprite;
}

void Predator::seek(sf::Vector2f playerPos) {
	//speed = playerPos - position;
	//speed = normalise(speed);
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
	/*speed = targetVelocity - velocity;
	speed = speed * (time * 60);
	if (lenght(speed) > MAX_speedERATION) {
		speed = normalise(speed);
		speed = speed * MAX_speedERATION;
	}*/
}