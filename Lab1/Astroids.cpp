#include "Astroids.h"

//Constructor
Astroids::Astroids(std::string name, sf::Vector2f pPos, sf::Vector2f pVel) :
gameObject(pPos) {
	texture.loadFromFile(name + ".png");
	sprite.setTexture(texture);
	//l8r m8
	//sprite.setScale(.5, .5);
	//sprite.setOrigin(width / 2, height / 2);
	angularRotation = 0;

	width = 173;
	height = 291;
}

void Astroids::update(sf::Vector2f maxExtends, float time) {
	gameObject::update(maxExtends, time);
}

sf::Sprite Astroids::returnDrawable() {
	return sprite;
}
