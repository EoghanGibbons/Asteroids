#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 540), "AI Labs!");
	Player myPlayer("player", 200, 200, .3, .3);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		myPlayer.update(window.getSize());

		window.clear();
		window.draw(myPlayer.returnDrawable());
		window.display();
	}

	return 0;
}