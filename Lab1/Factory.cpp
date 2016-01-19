#include "Factory.h"

//Constructor
Factory::Factory(std::string name, float pXPos, float pYPos, float pXVel, float pYVel):
gameObject(pXPos, pYPos, pXVel, pYVel) {
	texture.loadFromFile(name + ".png");
	sprite.setTexture(texture);
	
	//l8r m8
	//sprite.setScale(.5, .5);
	//sprite.setOrigin(width / 2, height / 2);
}

void Factory::update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time) {
														
	gameObject::update(maxExtends, time);

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