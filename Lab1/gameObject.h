#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Sprite.hpp>

class gameObject{
public:
	gameObject();
	gameObject(float pXPos, float pYPos, float pXVel, float pYVel);
	virtual ~gameObject();
	virtual sf::Vector2f normalise(sf::Vector2f);
	virtual float lenght(sf::Vector2f);
	sf::Sprite sprite;
	void update(float time);

	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f accel;
	float angularRotation;
	const float MAX_SPEED = 50;
	const float MAX_ROTATION = 360;
};