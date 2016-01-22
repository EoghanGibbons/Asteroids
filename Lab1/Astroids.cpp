#include "Astroids.h"

//Constructor
Astroids::Astroids(std::string name, sf::Vector2f pPos, sf::Vector2f pVel) :
gameObject(pPos) {
	texture.loadFromFile(name + ".png");
	gameObject::sprite.setTexture(texture);
	gameObject::sprite.setScale(.25, .25);
	gameObject::speed = 50;
}

void Astroids::update(sf::Vector2f maxExtends, float time) {
	gameObject::update(maxExtends, time);
}