#include "Factory.h"

//Constructor
Factory::Factory(std::string name, float pXPos, float pYPos, float pXVel, float pYVel) :
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

void Factory::update(sf::Vector2u maxExtends, sf::Vector2f playerPos	/* add a value in here for time since last frame, this way we can produce predators at a regular rate */) {
																		//something like one every 3/4 seconds should be loads!
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

	float playerDistance; // = Distance between factory and player position, simple formula, cba to write it since I can't execute on laptop anyway

	//call intelligence methods
	
	if (true /* playerDistance < range*/){
		//take evasive action
		if (true /* activeInterceptors < 6 (they can have 5) */){
			//Fire an interceptor Missile at the player
		}
	}

	else {
		//wander();
	}

	sprite.setPosition(position);
}

sf::Sprite Factory::returnDrawable() {
	return sprite;
}

void Factory::evade() {

}

void Factory::fireInterceptor() {

}

void Factory::producePredator() {

}