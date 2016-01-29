#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include "Predator.h"

class Factory : public gameObject{
public:
	//! Constructor for factory object Position is passed to it's gameObject
	Factory(std::string name, sf::Vector2f pPos, sf::Vector2f pVel); 
	//! Implemented Destructor method
	~Factory(){
		//! calls it's gameObjects destructor
		gameObject::~gameObject(); 
	}
	//! States
	enum state{
		//! Wandering state
		wander, 
		//! Evading state
		evade 
	};

	//! Update function takes world bounds, players position, and time since last frame
	void update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time); 
	//! container for predators created by the factory
	std::vector<Predator> predators; 
private:
	//! Factorys texture
	sf::Texture texture; 

	//! Fires an interceptor missle at the player
	void fireInterceptor(); 
	//! Evading implementation
	void Evade(); 
	//! Wander implementation
	void Wander(); 
	//! Produces a predator
	void producePredator(); 
};