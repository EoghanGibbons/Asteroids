#include "Predator.h"

//Constructor
Predator::Predator(std::string name, float pXPos, float pYPos, float pXVel, float pYVel) :
health(4), range(15) {
	texture.loadFromFile(name + ".png");
	sprite.setTexture(texture);

	//l8r m8
	//sprite.setScale(.5, .5);
	//sprite.setOrigin(width / 2, height / 2);

	position.x = pXPos;
	position.y = pYPos;
	velocity.x = pXVel;
	velocity.y = pYVel;
}

void Predator::update(sf::Vector2u maxExtends, sf::Vector2f playerPos) {
	//Wrap around world implementation
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

	float playerDistance; // = Distance between Pred and player position, simple formula, cba to write it since I can't execute on laptop anyway
	seek();
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

void Predator::seek() {
	//seek out the player and move towards him
}

void Predator::flock() {
	//this needs much further consideration, HOWEVER, my current understanding is that
	//if there is one predator ship already engaged in combat with the player the rest
	//should flock to it and engage the player from stratigic angels
}

void Predator::fire() {
	//Fire at the player, if you think you can hit him
}