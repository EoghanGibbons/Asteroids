#include "Factory.h"

//Constructor
Factory::Factory(std::string name, sf::Vector2f pPos, sf::Vector2f pVel):
gameObject(pPos, pVel) {
	texture.loadFromFile(name + ".png");
	gameObject::sprite.setTexture(texture);
	predators.reserve(4);
}

void Factory::update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time) {
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
	
	gameObject::update(maxExtends, time);
}

void Factory::Evade() {

}

void Factory::fireInterceptor() {

}

void Factory::producePredator() {

}