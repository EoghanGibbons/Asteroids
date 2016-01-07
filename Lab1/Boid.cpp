#include "Boid.h"

//Constructor
Boid::Boid(std::string name, float pXPos, float pYPos, float pXVel, float pYVel):
health(1), range(15) {
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

void Boid::update(sf::Vector2u maxExtends, sf::Vector2f playerPos) {
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

	float playerDistance; // = Distance between Boid and player position, simple formula, cba to write it since I can't execute on laptop anyway

	//call intelligence methods

	if (true /* playerDistance < range*/){
		intercept();
	}

	else {
		//swarm();
	}

	sprite.setPosition(position);
}

sf::Sprite Boid::returnDrawable() {
	return sprite;
}

void Boid::intercept() {
	//called if player is within range, intercept and kill him
}

void Boid::swarm() {
	//look for other boids, swarm with them
}