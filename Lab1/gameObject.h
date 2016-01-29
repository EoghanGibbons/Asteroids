#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Sprite.hpp>

class gameObject {
public:
	//! Constructors
	
	//! Default contructor
	gameObject();
	//! Constructor for non-player controled objects
	gameObject(sf::Vector2f pPos); 
	//! Constructor for player controled objects
	gameObject(sf::Vector2f pPos, float pAngle, float pSpeed);
	//! Destructor for gameObjects
	~gameObject(); 
	
	//! Update function for objects that don't wrap around, used for bullets
	void update(float time); 
	//! Update function for non-player controled objects
	void update(sf::Vector2f maxExtends, float time); 
	//! Update function for player controled objects
	void update(sf::Vector2f maxExtends, float time, bool controlable);
	//! Returns the angle between two vectors
	float angleBetween(sf::Vector2f vec1, sf::Vector2f vec2); 
	//! Returns the dot product of two vectors
	float dotProduct(sf::Vector2f vec1, sf::Vector2f vec2);
	//! Accelerates an object in the direction it's facing
	void thrust(); 
	//! Accelerates an object opposite the direction it's facing
	void reverse(); 
	//! An Objects sprite
	sf::Sprite sprite; 
	//! Returns the drawable for SFML to draw
	sf::Sprite returnDrawable(); 

	//! Objects position in 2d
	sf::Vector2f position; 
	//! Acceleration of an object
	sf::Vector2f velocity; 
	//! Direction an object is facing
	sf::Vector2f direction;
	//! An objects effective range
	short range; 
	//! An objects health
	short health; 

	//! An Objects speed as an integer
	float speed; 
	//! Angular velocity of an object
	float angularVelocity; 
	//! An objects rotation
	float angularRotation; 

	//! Maximum speed constant
	const float MAX_SPEED = 500; 
	//! Maximum rate of rotation
	const float MAX_ANGULAR_VELOCTIY = 500; 
	//! Pi
	const float PI = 3.14159265;
	//! Width of an object
	int width; 
	//! Height of an object
	int height; 

	//! Returns the normal of a vector
	sf::Vector2f normalise(sf::Vector2f); 
	//! Returns the lenght of a vector
	float lenght(sf::Vector2f); 
private:
	//! Implementation of wrap around world
	void wrapRound(sf::Vector2f maxExtends); 
};

#endif