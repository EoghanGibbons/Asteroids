#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "gameObject.h"

class Player: public gameObject{
public:
	Player(std::string name, float pXPos, float pYPos, float pXVel, float pYVel);
	~Player(){
		gameObject::~gameObject();
	}

	void update(sf::Vector2f, float time);
	sf::Sprite returnDrawable();
	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();
private:
	sf::Texture texture;
	sf::Vector2f direction;

	const int width = 173;
	const int height = 291;
	float M_PI = 3.141f;
};