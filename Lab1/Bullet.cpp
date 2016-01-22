#include "Bullet.h"

Bullet::Bullet(sf::Vector2f pPos, float angle, float speed) :
gameObject(pPos, angle, speed) {
	texture.loadFromFile("Bullet.png");
	gameObject::sprite.setTexture(texture);
}

void Bullet::update(float time) {
	gameObject::update(time);
}