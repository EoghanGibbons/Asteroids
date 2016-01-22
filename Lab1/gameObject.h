#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Sprite.hpp>

class gameObject {
public:
	//Constructors
	gameObject();
	gameObject(sf::Vector2f pPos);
	gameObject(sf::Vector2f pPos, float pAngle, float pSpeed);
	~gameObject();
	
	void update(float time);
	void update(sf::Vector2f maxExtends, float time);
	void update(sf::Vector2f maxExtends, float time, bool controlable);
	float angleBetween(sf::Vector2f vec1, sf::Vector2f vec2);
	float dotProduct(sf::Vector2f vec1, sf::Vector2f vec2);
	void thrust();
	void reverse();
	sf::Sprite sprite;
	sf::Sprite returnDrawable();

	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f direction;
	short range;
	short health;

	float speed;
	float angularVelocity;
	float angularRotation;

	const float MAX_SPEED = 500;
	const float MAX_ANGULAR_VELOCTIY = 500;
	const float PI = 3.14159265;
	int width;
	int height;

	sf::Vector2f normalise(sf::Vector2f);
	float lenght(sf::Vector2f);
private:
	void wrapRound(sf::Vector2f maxExtends);
};

#endif