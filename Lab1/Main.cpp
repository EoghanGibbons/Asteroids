#include "Player.h"
#include <iostream>
#include <vector>
#include "Flock.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <string>
#include "Predator.h"



int main() {
	float boidsSize = 4;
	std::string action = "flock";

	//Gets the resolution, size, and bits per pixel for the screen of the PC that is running this program.
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	const int window_height = desktop.height;
	const int window_width = desktop.width;

	//Having the style of "None" gives a false-fullscreen effect for easier closing and access.
	//No FPS limit of V-sync setting needed for it may cause unnecessary slowdown.
	//sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Boids", sf::Style::Fullscreen);

	sf::Vector2f maxEntends;
	maxEntends = { 960, 540 };
	sf::RenderWindow window(sf::VideoMode(960, 540), "Astroids");

	Player myPlayer("player", 200, 200, .0, .0);

	//Create flock, vector of shapes, and initialize boids
	Flock flock;
	std::vector<sf::CircleShape> shapes;

	Predator killaPredator("player", 900, 500, .3, .3);
	sf::Clock clock;

	sf::View mainView;
	mainView.setCenter(myPlayer.getPosition());
	window.setView(mainView);

	for (int i = 0; i < 50; i++) {//Number of boids is hardcoded for testing pusposes.
		Boid b(rand() % window_width, rand() % window_height); //Starts the boid with a random position in the window.
		//Boid b(window_width / 2, window_height / 2); //Starts all boids in the center of the screen
		sf::CircleShape shape(8, 3); //Shape with a radius of 10 and 3 points (Making it a triangle)

		//Changing the Visual Properties of the shape
		//shape.setPosition(b.location.x, b.location.y); //Sets position of shape to random location that boid was set to.
		shape.setPosition(window_width, window_height); //Testing purposes, starts all shapes in the center of screen.
		shape.setOutlineColor(sf::Color(0, 255, 0));
		shape.setFillColor(sf::Color::Green);
		shape.setOutlineColor(sf::Color::White);
		shape.setOutlineThickness(2);
		shape.setRadius(boidsSize);

		//Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
		flock.addBoid(b);
		shapes.push_back(shape);
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)){
			if ((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
					window.close();
				}
		}

		if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space))
			if (action == "flock")
				action = "swarm";
			else
				action = "flock";

		sf::Time time = clock.restart();
		float elapsedTimeInSeconds = time.asSeconds();
		
		myPlayer.update(maxEntends, elapsedTimeInSeconds);
		killaPredator.update(maxEntends, myPlayer.getPosition(), elapsedTimeInSeconds);
		mainView.move(myPlayer.getVelocity().x, myPlayer.getVelocity().y);

		window.clear();

		//Draws all of the Boids out, and applies functions that are needed to update.
		for (int i = 0; i < shapes.size(); i++)
		{
			window.draw(shapes[i]);

			//Cout's removed due to slowdown and only needed for testing purposes
			//cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
			//cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;

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

		//Applies the three rules to each boid in the flock and changes them accordingly.
		if (action == "flock")
			flock.flocking();
		else
			flock.swarming();

		window.draw(myPlayer.returnDrawable());
		window.display();
	}

	return 0;
}