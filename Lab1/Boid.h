#include "Pvector.h"
#include <vector>
#include <stdlib.h>
#include <iostream>

#ifndef BOID_H_
#define BOID_H_

/*
Brief description of Boid Class:
//The boid class creates an object which has multiple vectors (location, velocity, acceleration)
//Boids are given certain properties and rules to follow when interacting with other boids.
//They are being used to simulate flocking patterns and properties

For predators:
Predators should act by themselves. Thus, their maxSpeed should be different,
and they should not adhere to the three laws. However, they should adhere to
cohesion -- how should they seek prey? Also, prey should be able to run away
from predators. There are several ways to do this. The easiest way:

Predators are part of the flock. This means that when the boids check
through the vector of other boids, the predators are included. Check if
the boid being looked at is a predator, and if it is, calculate a Pvector
that maximizes separation.
*/

class Boid {
public:
	//! Leader of the formation
	bool predator; 
	//! Location as a Pvector
	Pvector location; 
	//! Velocity as a Pvector
	Pvector velocity; 
	//! Acceleration as a Pvector
	Pvector acceleration; 
	//! Maximum allowed Velocity as a float
	float maxSpeed; 
	//! Max acceleration force as a float
	float maxForce; 
	//! Constructor
	Boid() {} 

	//! Overloaded constructor just implementing position
	Boid(float x, float y)
	{
		acceleration = Pvector(0, 0);
		velocity = Pvector(rand() % 3 - 2, rand() % 3 - 2); // Allows for range of -2 -> 2
		location = Pvector(x, y);
		maxSpeed = 3.5;
		maxForce = 0.5;
	}
	
	//! Overloaded contructor marking the boid as the leader of the formation
	Boid(float x, float y, bool predCheck)
	{
		predator = predCheck;
		if (predCheck == true) {
			maxSpeed = 4.5;
			maxForce = 0.5;
			velocity = Pvector(rand() % 3 - 1, rand() % 3 - 1);
		}
		else {
			maxSpeed = 2.5;
			maxForce = 0.5;
			velocity = Pvector(rand() % 3 - 2, rand() % 3 - 2); // Allows for range of -2 -> 2
		}
		acceleration = Pvector(0, 0);
		location = Pvector(x, y);
	}
	
	//! Applies acceleration force to boid each frame
	void applyForce(Pvector force); 
	
	//! Three Laws that boids follow

	//! All boids separate
	Pvector Separation(std::vector<Boid> Boids); 
	//! All boids form in a circle around leader
	Pvector Alignment(std::vector<Boid> Boids); 
	//! All boids swarm together
	Pvector Cohesion(std::vector<Boid> Boids); 
	
	//! Functions involving SFML and visualisation linking

	//! Returns a vector in the direction of the player
	Pvector seek(Pvector v); 
	void run(std::vector <Boid> v); //! 
	//! Called each frame
	void update(); 
	//! Implemented flocking behaviour
	void flock(std::vector <Boid> v); 
	//! Implementation of wrap around world
	void borders(); 
	//! returns the angle between boid and a given position
	float angle(Pvector v); 
	//! Implemented flocking behaviour
	void swarm(std::vector <Boid> v); 
};

#endif