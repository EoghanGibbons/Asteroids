#ifndef	PREDATOR_H
#define PREDATOR_H

#include <SFML\Graphics\Texture.hpp>
#include "Bullet.h"

class Predator : public gameObject{
public:
	//! Constructor for predator, pPos is passed to it's gameObject
	Predator(std::string name, sf::Vector2f pPos); 
	//! States
	enum State {
		//! Seeking state
		seeking = 0, 
		//! Flocking state
		flocking = 1, 
	};
	//! Implemented Predator destructor
	~Predator(){
		//! Calls it's gameObject's destructor
		gameObject::~gameObject(); 
	}

	//! Update function, takes world bounds, player position, and time since last frame
	void update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time);
	//! Container for bullets created by Predator
	std::vector<Bullet> bullets; 
private:
	//! Predators texture
	sf::Texture texture; 

	//! Current state of Predator
	State currentState; 
	//! Seeking implementation
	void seek(sf::Vector2f playerPos); 
	//! Arriving implementation
	void arrive(float arriveRadius, float slowRadius, sf::Vector2f playerPos, float time); 
	//! Flocking implementation
	void flock();
	//! Fires a bullet
	void fire(); 
};

#endif;