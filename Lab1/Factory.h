#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include "Predator.h"

class Factory : public gameObject{
public:
	Factory(std::string name, sf::Vector2f pPos, sf::Vector2f pVel);
	~Factory(){
		gameObject::~gameObject();
	}
	void update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time);
	sf::Sprite returnDrawable();
private:
	sf::Texture texture;
	
	void fireInterceptor();
	void evade();
	void wander();
	void producePredator();

	//assign these values later
	int width = 173;
	int height = 291;
};