#ifndef BULLET_H
#define BULLET_H

#include <SFML\Graphics\Texture.hpp>
#include "gameObject.h"

class Bullet : public gameObject {
public:
	Bullet(sf::Vector2f pPos, float angle, float speed);
	~Bullet() {
		gameObject::~gameObject();
	}

	void update(float time);
private:
	sf::Texture texture;
};

#endif