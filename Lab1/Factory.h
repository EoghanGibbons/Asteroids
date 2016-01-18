#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>

class Factory{
public:
	Factory(std::string name, float pXPos, float pYPos, float pXVel, float pYVel);

	void update(sf::Vector2u maxExtends, sf::Vector2f playerPos);
	sf::Sprite returnDrawable();
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Sprite sprite;
	sf::Texture texture;
	short health;
	short range;
	
	void fireInterceptor();
	void evade();
	void wander();
	void producePredator();

	//assign these values later
	int width = 173;
	int height = 291;
};