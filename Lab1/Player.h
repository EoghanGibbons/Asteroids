#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Keyboard.hpp>
class Player{
public:
	Player(std::string name, float pXPos, float pYPos, float pXVel, float pYVel);

	void update(sf::Vector2u);
	sf::Sprite returnDrawable();
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Sprite sprite;
	sf::Texture texture;

	int width = 173;
	int height = 291;
};