#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include "gameObject.h"

class Astroids : public gameObject{
public:
	//! Constructor for asteroid, pPos is passed to it's gameObject
	Astroids(std::string name, sf::Vector2f pPos, sf::Vector2f pVel); 	
	//! Implemented destructor method
	~Astroids(){
		//! Calls it's gameObject's destructor
		gameObject::~gameObject(); 
	}
	//! Update takes world bounds and time since last frame
	void update(sf::Vector2f maxExtends, float time); 
private:
	//! The texture for the asteroid
	sf::Texture texture; 
};