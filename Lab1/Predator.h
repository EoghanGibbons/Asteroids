#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include "gameObject.h"

class Predator : public gameObject{
public:
	Predator(std::string name, float pXPos, float pYPos, float pXVel, float pYVel);

	void update(sf::Vector2u maxExtends, sf::Vector2f playerPos, float time);
	sf::Sprite returnDrawable();
private:
	sf::Sprite sprite;
	sf::Texture texture;
	short range;
	short health;

	void seek();
	void flock();
	void fire();
	float lenght(sf::Vector2f);

	//assign these values later
	int width = 173;
	int height = 291;
};