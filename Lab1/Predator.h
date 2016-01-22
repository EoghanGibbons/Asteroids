#ifndef	PREDATOR_H
#define PREDATOR_H

#include <SFML\Graphics\Texture.hpp>
#include "gameObject.h"

class Predator : public gameObject{
public:
	Predator(std::string name, sf::Vector2f pPos, sf::Vector2f pVel);
	enum State {
		seeking = 0,
		flocking = 1,
	};
	~Predator(){
		gameObject::~gameObject();
	}

	void update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time);
	State getState();
private:
	sf::Texture texture;

	State currentState;
	void seek(sf::Vector2f playerPos);
	void arrive(float arriveRadius, float slowRadius, sf::Vector2f playerPos, float time);
	void flock();
	void fire();
};

#endif;