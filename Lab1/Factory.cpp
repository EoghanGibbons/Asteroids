#include "Factory.h"

//Constructor
Factory::Factory(std::string name, sf::Vector2f pPos, sf::Vector2f pVel):
gameObject(pPos, pVel) {
	texture.loadFromFile(name + ".png");
	sprite.setTexture(texture);
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