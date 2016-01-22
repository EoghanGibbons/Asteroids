#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include "gameObject.h"

class Astroids : public gameObject{
public:
	Astroids(std::string name, sf::Vector2f pPos, sf::Vector2f pVel);
	~Astroids(){
		gameObject::~gameObject();
	}
	void update(sf::Vector2f maxExtends, float time);
private:
	sf::Texture texture;
};