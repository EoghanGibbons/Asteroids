#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include "gameObject.h"

class Factory : public gameObject{
public:
	Factory(std::string name, float pXPos, float pYPos, float pXVel, float pYVel);

	void update(sf::Vector2u maxExtends, sf::Vector2f playerPos, float time);
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