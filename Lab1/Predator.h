#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include "gameObject.h"



class Predator : public gameObject{
public:
	Predator(std::string name, float pXPos, float pYPos, float pXVel, float pYVel);
	enum State {
		seeking = 0,
		flocking = 1,
	};

	~Predator(){
		gameObject::~gameObject();
	}
	void update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time);
	sf::Sprite returnDrawable();
	State getState();
private:
	sf::Texture texture;

	State currentState;
	void seek(sf::Vector2f playerPos);
	void arrive(float arriveRadius, float slowRadius, sf::Vector2f playerPos, float time);
	void flock();
	void fire();
};