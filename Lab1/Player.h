#include <SFML\Window\Keyboard.hpp>
#include "Bullet.h"

class Player: public gameObject{
public:
	//! Constructor for player, pPos is passed to gameObject
	Player(std::string name, sf::Vector2f pPos, sf::Vector2f pVel); 
	//! Destructor implementation
	~Player(){
		//! Calls the gameObjects destructor
		gameObject::~gameObject(); 
	}

	//! Update function, takes world bounds and time since last frame
	void update(sf::Vector2f, float time);
	//! Returns the players Position
	sf::Vector2f getPosition(); 
	//! Returns the players velocity
	sf::Vector2f getVelocity(); 
	//! Container for bullets created by the Player
	std::vector<Bullet> bullets; 
private:
	//! The players texture
	sf::Texture texture; 
	//! Vector of the direction the player is facing
	sf::Vector2f direction;

	//! Width of the player sprite
	const int width = 173; 
	//! Height of the player sprite
	const int height = 291;
	//! Angle of rotation of the player sprite
	float rotation; 
};