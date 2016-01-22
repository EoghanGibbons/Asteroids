#include "Player.h"
#include <iostream>
#include <vector>
#include "Flock.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <string>
#include "Factory.h"
#include "Astroids.h"

void cameraManWalls(sf::View* view, float windowWidth, float windowHeight);
void createStars(std::vector<sf::CircleShape>* stars, int windowWidth, int WindowHeight);

int main() {
	float border = 3000;
	float smallSize = 5;
	float bigSize = 20;
	std::string action = "flock";

	std::vector<Astroids> astroids;

	for (int i = 0; i < 25; i++){
		astroids.push_back(Astroids("noName", sf::Vector2f(rand() % 3000 + 10, rand() % 3000 + 10), sf::Vector2f(rand() % 200 + 10, rand() % 200 + 10)));
	}

	//Gets the resolution, size, and bits per pixel for the screen of the PC that is running this program.
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	const int window_height = desktop.height;
	const int window_width = desktop.width;

	//sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Eoghan and John's Astroids", sf::Style::Fullscreen);
	sf::RenderWindow window(sf::VideoMode(960, 540), "Astroids");

	sf::Vector2f maxEntends;
	maxEntends = { 3000, 3000 };
	
	sf::View fixed = window.getView(); // The 'fixed' view will never change
	sf::View standard = fixed; // The 'standard' view will be the game world
	sf::View radar = fixed;

	radar.setViewport(sf::FloatRect(0.01f, 0.79f, 0.2, 0.2));
	radar.zoom(3);

	//Create radar background
	sf::Texture texture;
	texture.loadFromFile("radar.png");
	sf::Sprite sprite;
	sprite.setTexture(texture, true);
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	sprite.setScale((window_width / sprite.getLocalBounds().width) * 3, (window_height / sprite.getLocalBounds().height) * 3);
	sprite.setPosition(window_width / 2, window_height / 2);


	Player myPlayer("player", sf::Vector2f(200, 200), sf::Vector2f(.0, .0));

	//Create f                                                                                                                                                                   lock, vector of shapes, and initialize boids
	Flock BS;
	Flock SS;
	std::vector<sf::CircleShape> smallShips;
	std::vector<sf::CircleShape> bigShips;

	//Create the stars
	std::vector<sf::CircleShape> stars;

	//Predator killaPredator("predator", sf::Vector2f(300, 300), sf::Vector2f(.0, .0));
	Factory myFactory("factory", sf::Vector2f(300, 300), sf::Vector2f(0.0f, 0.0f));
	//draws our game border
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(0, 0)),
		sf::Vertex(sf::Vector2f(3000, 0)),
	};
	//draws our game border
	sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f(3000, 0)),
		sf::Vertex(sf::Vector2f(3000, 3000)),

	};
	//draws our game border
	sf::Vertex line3[] =
	{
		sf::Vertex(sf::Vector2f(3000, 3000)),
		sf::Vertex(sf::Vector2f(0, 3000))
	};
	//draws our game border
	sf::Vertex line4[] =
	{
		sf::Vertex(sf::Vector2f(0, 0)),
		sf::Vertex(sf::Vector2f(0, 3000)),
	};
	sf::Clock clock;

	int fLeader = 0;
	
	//Create Boids
	for (int i = 0; i < 25; i++) {
		//Number of boids is hardcoded for testing pusposes.
		Boid small(rand() % 3000, rand() % 3000);
		//Boid small(600, 600); //Starts the boid with a random position in the window.
		//Boid b(window_width / 2, window_height / 2); //Starts all boids in the center of the screen
		sf::CircleShape shape(8, 3); //Shape with a radius of 10 and 3 points (Making it a triangle)
		//Changing the Visual Properties of the shape
		shape.setPosition(small.location.x, small.location.y); //Sets position of shape to random location that boid was set to.
		//shape.setPosition(window_width, window_height); //Testing purposes, starts all shapes in the center of screen.
		shape.setOutlineColor(sf::Color(255, 0, 0));
		shape.setFillColor(sf::Color(0,0,255));
		shape.setOutlineColor(sf::Color(0,255,0));
		shape.setOutlineThickness(1);
		shape.setRadius(smallSize);

		//Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
		SS.addBoid(small);
		bigShips.push_back(shape);
	}

	for (int i = 0; i < 25; i++) {//Number of boids is hardcoded for testing pusposes.
		Boid big(rand() % 3000, rand() % 3000);
		//Boid big(200, 200); //Starts the boid with a random position in the window.
		//Boid b(window_width / 2, window_height / 2); //Starts all boids in the center of the screen
		sf::CircleShape shape(8, 3); //Shape with a radius of 10 and 3 points (Making it a triangle)

		//Changing the Visual Properties of the shape
		shape.setPosition(big.location.x, big.location.y); //Sets position of shape to random location that boid was set to.
		shape.setOutlineColor(sf::Color(0, 0, 255));
		shape.setFillColor(sf::Color(255, 0, 0));
		shape.setOutlineColor(sf::Color(0, 255, 0));
		shape.setOutlineThickness(1);
		shape.setRadius(bigSize);

		//Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
		BS.addBoid(big);
		smallShips.push_back(shape);
	}

	createStars(&stars, maxEntends.x, maxEntends.y);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)){
			if ((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
				window.close();
			}
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space))
				if (action == "flock")
					action = "swarm";
				else
					action = "flock";
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z))
				action = "cformation";
		}

		sf::Time time = clock.restart();
		float elapsedTimeInSeconds = time.asSeconds();

		myPlayer.update(maxEntends, elapsedTimeInSeconds);
		myFactory.update(maxEntends, myPlayer.getPosition(), elapsedTimeInSeconds);

		window.clear();

		standard.setCenter(myPlayer.getPosition());
		cameraManWalls(&standard, maxEntends.x, maxEntends.y);
		window.setView(standard);

		//Draws all of the Boids out, and applies functions that are needed to update.
		for (int i = 0; i < smallShips.size(); i++)	{
			window.draw(smallShips[i]);
			//Matches up the location of the shape to the boid
			smallShips[i].setPosition(SS.getBoid(i).location.x, SS.getBoid(i).location.y);
			// Calculates the angle where the velocity is pointing so that the triangle turns towards it.
			float theta;
			theta = SS.getBoid(i).angle(SS.getBoid(i).velocity);
			smallShips[i].setRotation(theta);

			// These if statements prevent boids from moving off the screen through warpping
			// If boid exits right boundary
			if (smallShips[i].getPosition().x > maxEntends.x)
				smallShips[i].setPosition(smallShips[i].getPosition().x - maxEntends.x, smallShips[i].getPosition().y);
			// If boid exits bottom boundary
			if (smallShips[i].getPosition().y > maxEntends.y)
				smallShips[i].setPosition(smallShips[i].getPosition().x, smallShips[i].getPosition().y - maxEntends.y);
			// If boid exits left boundary
			if (smallShips[i].getPosition().x < 0)
				smallShips[i].setPosition(smallShips[i].getPosition().x + maxEntends.x, smallShips[i].getPosition().y);
			// If boid exits top boundary
			if (smallShips[i].getPosition().y < 0)
				smallShips[i].setPosition(smallShips[i].getPosition().x, smallShips[i].getPosition().y + maxEntends.y);
		}

		//Draws all of the Boids out, and applies functions that are needed to update.
		for (int i = 0; i < bigShips.size(); i++)	{
			window.draw(bigShips[i]);
			//Matches up the location of the shape to the boid
			bigShips[i].setPosition(BS.getBoid(i).location.x, BS.getBoid(i).location.y);
			// Calculates the angle where the velocity is pointing so that the triangle turns towards it.
			float theta;
			theta = BS.getBoid(i).angle(BS.getBoid(i).velocity);
			bigShips[i].setRotation(theta);

			// These if statements prevent boids from moving off the screen through warpping
			// If boid exits right boundary
			if (bigShips[i].getPosition().x > maxEntends.x)
				bigShips[i].setPosition(bigShips[i].getPosition().x - maxEntends.x, smallShips[i].getPosition().y);
			// If boid exits bottom boundary
			if (bigShips[i].getPosition().y > maxEntends.y)
				bigShips[i].setPosition(bigShips[i].getPosition().x, bigShips[i].getPosition().y - maxEntends.y);
			// If boid exits left boundary
			if (bigShips[i].getPosition().x < 0)
				bigShips[i].setPosition(bigShips[i].getPosition().x + maxEntends.x, bigShips[i].getPosition().y);
			// If boid exits top boundary
			if (bigShips[i].getPosition().y < 0)
				bigShips[i].setPosition(bigShips[i].getPosition().x, bigShips[i].getPosition().y + maxEntends.y);
		}

		for (int i = 0; i < stars.size(); i++){
			window.draw(stars[i]);
		}

		for (int i = 0; i < myPlayer.bullets.size(); i++) {
			window.draw(myPlayer.bullets[i].returnDrawable());
		}
		/*for (int i = 0; i < myFactory.predators.size(); i++) {
			for (int j = 0; myFactory.predators[i].bullets.size(); j++){
				window.draw(myFactory.predators[i].bullets[j].returnDrawable());
			}
		}*/
		for (int i = 0; i < myFactory.predators.size(); i++){
			window.draw(myFactory.predators[i].returnDrawable());
		}
		window.draw(myFactory.returnDrawable());
		window.draw(myPlayer.returnDrawable());

		window.draw(line, 2, sf::Lines);
		window.draw(line2, 2, sf::Lines);
		window.draw(line3, 2, sf::Lines);
		window.draw(line4, 2, sf::Lines);

		//Applies the three rules to each boid in the flock and changes them accordingly.
		if (action == "flock"){
			SS.flocking();
			BS.flocking();
		}
		else if (action == "swarm"){
			SS.swarming();
			BS.swarming();
		}
		else{
			SS.cFormation(fLeader); //Pass in the index position of the leader.
			BS.cFormation(fLeader);
		}

		//draws radar and all objecta within radar
		window.setView(radar);
		window.draw(sprite);
		window.draw(myPlayer.returnDrawable());
		for (int i = 0; i < bigShips.size(); i++)	{
			window.draw(bigShips[i]);
		}
		for (int i = 0; i < smallShips.size(); i++)	{
			window.draw(smallShips[i]);
		}

		window.display();
	}
	return 0;
}

void cameraManWalls(sf::View* view, float windowWidth, float windowHeight) {
	sf::Vector2f newCentre = view->getCenter();

	if (view->getCenter().x <= -windowWidth * 0.5f) {
		newCentre.x = -windowWidth * 0.5f;
	}
	else if (view->getCenter().x >= windowWidth * 1.5f) {
		newCentre.x = windowWidth * 1.5f;
	}

	if (view->getCenter().y <= -windowHeight * 0.5f) {
		newCentre.y = -windowHeight * 0.5f;
	}
	else if (view->getCenter().y >= windowHeight * 1.5f) {
		newCentre.y = windowHeight * 1.5f;
	}
	view->setCenter(newCentre);
}

void createStars(std::vector<sf::CircleShape>* stars, int windowWidth, int WindowHeight) {
	for (int i = 0; i < 500; i++) {
		sf::CircleShape shape( rand() % 10 + 1, rand() % 10 + 1);

		shape.setPosition( rand() % windowWidth + 10, rand() % WindowHeight + 10 );
		shape.setPosition( rand() % windowWidth + 20, rand() % WindowHeight + 10 );
		shape.setOutlineColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
		shape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
		shape.setOutlineColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
		shape.setOutlineThickness(1);
		shape.setRadius(rand() % 10 + 1);
		stars->push_back(shape);
	}
}