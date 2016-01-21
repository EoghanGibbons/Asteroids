#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Sprite.hpp>

#define PI 3.14159265

class gameObject {
public:
	gameObject();
	gameObject(float pXPos, float pYPos, float pXVel, float pYVel);
	~gameObject();
	sf::Vector2f normalise(sf::Vector2f);
	float lenght(sf::Vector2f);
	sf::Sprite sprite;
	void update(sf::Vector2f maxExtends, float time);
	void update(sf::Vector2f maxExtends, float time, bool controlable);

	void thrust();
	void reverse();

	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f direction;
	float speed;
	float angularRotation;
	float angularVelocity;
	const float MAX_SPEED = 500;
	const float MAX_ANGULAR_VELOCTIY = 500;
	short range;
	short health;

	int width;
	int height;
};

#endif