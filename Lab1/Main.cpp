#include "Player.h"
#include <iostream>
#include <vector>
#include "Flock.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <string>
#include "Predator.h"

void cameraManWalls(sf::View* view, float windowWidth, float windowHeight);
void createStars(std::vector<sf::CircleShape>* stars, int windowWidth, int WindowHeight);

int main() {
	float boidsSize = 5;
	std::string action = "flock";

	//Gets the resolution, size, and bits per pixel for the screen of the PC that is running this program.
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	const int window_height = desktop.height;
	const int window_width = desktop.width;

	//Having the style of "None" gives a false-fullscreen effect for easier closing and access.
	//No FPS limit of V-sync setting needed for it may cause unnecessary slowdown.
	sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Eoghan and John's Astroids", sf::Style::Fullscreen);

	sf::Vector2f maxEntends;
	maxEntends = { 3000, 3000 };
	
	sf::View fixed = window.getView(); // The 'fixed' view will never change
	sf::View standard = fixed; // The 'standard' view will be the game world
	
	/*sf::View radar = fixed;

	radar.setViewport(sf::FloatRect(0.01f, 0.79f, 0.2, 0.2));
	radar.zoom(3);*/

	Player myPlayer("player", 200, 200, .0, .0);

	//Create f                                                                                                                                                                   lock, vector of shapes, and initialize boids
	Flock flock;
	std::vector<sf::CircleShape> shapes;

	//Create the stars
	std::vector<sf::CircleShape> stars;

	Predator killaPredator("player", 300, 300, .0, .0);
	sf::Clock clock;

	int fLeader = 0;
	
	//Create Boids
	for (int i = 0; i < 25; i++) {
		//Number of boids is hardcoded for testing pusposes.
		//Boid b(rand() % window_width, rand() % window_height);
		Boid b(600, 600); //Starts the boid with a random position in the window.
		//Boid b(window_width / 2, window_height / 2); //Starts all boids in the center of the screen
		sf::CircleShape shape(8, 3); //Shape with a radius of 10 and 3 points (Making it a triangle)

		//Changing the Visual Properties of the shape
		shape.setPosition(b.location.x, b.location.y); //Sets position of shape to random location that boid was set to.
		//shape.setPosition(window_width, window_height); //Testing purposes, starts all shapes in the center of screen.
		shape.setOutlineColor(sf::Color(255, 0, 0));
		shape.setFillColor(sf::Color(255,0,0));
		shape.setOutlineColor(sf::Color(0,255,0));
		shape.setOutlineThickness(1);
		shape.setRadius(boidsSize);

		//Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
		flock.addBoid(b);
		shapes.push_back(shape);
	}

	createStars(&stars, window_width, window_height);

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
		killaPredator.update(maxEntends, myPlayer.getPosition(), elapsedTimeInSeconds);

		window.clear();

		//Draws all of the Boids out, and applies functions that are needed to update.
		for (int i = 0; i < shapes.size(); i++)	{
			window.draw(shapes[i]);

			//Matches up the location of the shape to the boid
			shapes[i].setPosition(flock.getBoid(i).location.x, flock.getBoid(i).location.y);

			// Calculates the angle where the velocity is pointing so that the triangle turns towards it.
			float theta;
			theta = flock.getBoid(i).angle(flock.getBoid(i).velocity);
			shapes[i].setRotation(theta);

			// These if statements prevent boids from moving off the screen through warpping
			// If boid exits right boundary
			if (shapes[i].getPosition().x > maxEntends.x)
				shapes[i].setPosition(shapes[i].getPosition().x - window_width, shapes[i].getPosition().y);
			// If boid exits bottom boundary
			if (shapes[i].getPosition().y > maxEntends.y)
				shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y - window_height);
			// If boid exits left boundary
			if (shapes[i].getPosition().x < 0)
				shapes[i].setPosition(shapes[i].getPosition().x + window_width, shapes[i].getPosition().y);
			// If boid exits top boundary
			if (shapes[i].getPosition().y < 0)
				shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y + window_height);
		}

		for (int i = 0; i < stars.size(); i++){
			window.draw(stars[i]);
		}

		//Applies the three rules to each boid in the flock and changes them accordingly.
		if (action == "flock")
			flock.flocking();
		else
			flock.swarming();

		window.draw(myPlayer.returnDrawable());
		window.draw(killaPredator.returnDrawable());



		//Applies the three rules to each boid in the flock and changes them accordingly.
		if (action == "flock")
			flock.flocking();
		else if (action == "swarm")
			flock.swarming();
		else
			flock.cFormation(fLeader); //Pass in the index position of the leader.

		standard.setCenter(myPlayer.getPosition());
		cameraManWalls(&standard, window_width, window_height);
		window.setView(standard);
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

	//Y Axis
	if (view->getCenter().y <= -windowHeight * 0.5f) {
		newCentre.y = -windowHeight * 0.5f;
	}
	else if (view->getCenter().y >= windowHeight * 1.5f) {
		newCentre.y = windowHeight * 1.5f;
	}

	view->setCenter(newCentre);
}

void createStars(std::vector<sf::CircleShape>* stars, int windowWidth, int WindowHeight) {
	for (int i = 0; i < 25; i++) {
		//Boid b(rand() % window_width, rand() % window_height);
		Boid b(600, 600); //Starts the boid with a random position in the window.
		sf::CircleShape shape( rand() % 10 + 1, rand() % 10 + 1);

		shape.setPosition( rand() % windowWidth % 10, rand() % WindowHeight + 10 );
		shape.setOutlineColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
		shape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
		shape.setOutlineColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
		shape.setOutlineThickness(1);
		shape.setRadius(rand() % 10 + 1);

		stars->push_back(shape);
	}
}