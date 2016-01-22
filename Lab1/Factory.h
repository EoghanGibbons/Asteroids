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
	enum state{
		wander,
		evade
	};

	void update(sf::Vector2f maxExtends, sf::Vector2f playerPos, float time);
private:
	sf::Texture texture;
	std::vector<Predator> predators;

	void fireInterceptor();
	void Evade();
	void Wander();
	void producePredator();
};