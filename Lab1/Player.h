#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Keyboard.hpp>
class Player{
public:
	Player(std::string name, float pXPos, float pYPos, float pXVel, float pYVel);

	void update(sf::Vector2f);
	sf::Sprite returnDrawable();
	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f direction;
	sf::Sprite sprite;
	sf::Texture texture;

	int width = 173;
	int height = 291;
	float M_PI = 3.141f;
};