#ifndef BULLET_H
#define BULLET_H

#include <SFML\Graphics\Texture.hpp>
#include "gameObject.h"

class Bullet : public gameObject {
public:
	//! Bullet contructor, pPos is passed to it's gameObject
	Bullet(sf::Vector2f pPos, float angle, float speed); 
	//! Implemented Destructor
	~Bullet() {
		//! Calls it's gameObject's destructor
		gameObject::~gameObject(); 
	}

	//! Update takes time since last frame
	void update(float time); 
private:
	//! Bullet's texture
	sf::Texture texture; 
};

#endif