#include "Astroids.h"

//Constructor
Astroids::Astroids(std::string name, float pXPos, float pYPos, float pXVel, float pYVel) :
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

void Astroids::update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time) {

}

sf::Sprite Astroids::returnDrawable() {
	return sprite;
}
