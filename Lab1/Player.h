#include <SFML\Window\Keyboard.hpp>
#include "Bullet.h"

class Player: public gameObject{
public:
	Player(std::string name, sf::Vector2f pPos, sf::Vector2f pVel);
	~Player(){
		gameObject::~gameObject();
	}

	void update(sf::Vector2f, float time);
	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();
	std::vector<Bullet> bullets;
private:
	sf::Texture texture;
	sf::Vector2f direction;

	const int width = 173;
	const int height = 291;
	float rotation;
};