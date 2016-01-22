#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include "gameObject.h"

class Astroids : public gameObject{
public:
	Astroids(std::string name, float pXPos, float pYPos, float pXVel, float pYVel);
	enum State {
	};

	~Astroids(){
		gameObject::~gameObject();
	}
	void update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time);
	sf::Sprite returnDrawable();
	State getState();
private:
	sf::Texture texture;

	State currentState;
	void moveMent(sf::Vector2f playerPos);
	void arrive(float arriveRadius, float slowRadius, sf::Vector2f playerPos, float time);
};