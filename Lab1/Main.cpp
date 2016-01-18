#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Predator.h"

int main() {
	sf::Vector2f maxEntends;
	maxEntends = { 3000, 3000 };
	sf::RenderWindow window(sf::VideoMode(960, 540), "AI Labs!");
	Player myPlayer("player", 200, 200, .3, .3);
	Predator killaPredator("player", 900, 500, .3, .3);
	sf::Clock clock;

	sf::View mainView;
	mainView.setCenter(myPlayer.getPosition());
	window.setView(mainView);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time time = clock.restart();
		float elapsedTimeInSeconds = time.asSeconds();
		
		myPlayer.update(maxEntends);
		killaPredator.update(maxEntends, myPlayer.getPosition(), elapsedTimeInSeconds);
		mainView.move(myPlayer.getVelocity().x, myPlayer.getVelocity().y);

		window.clear();
		window.draw(myPlayer.returnDrawable());
		window.display();
	}

	return 0;
}