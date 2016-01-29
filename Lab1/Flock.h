#ifndef FLOCK_H_
#define FLOCK_H_

#include <iostream>
#include <vector>
#include "Boid.h"

/*
Brief description of Flock Class:
// This file contains the class needed to create flock of boids. It utilizes
// the boids class and initializes boid flocks with parameters that can be
// specified. This class will be utilized in main.
*/

class Flock
{
public:
	//! Public Variables

	//! Container for boids in a flock
	std::vector<Boid> flock; 

	//! Constructor
	Flock(); 

	//! Destructor
	~Flock(); 

	//! Accessor functions

	//! Returns the size of a flock
	int getSize();
	//! Returns a specific boid in a flock
	Boid getBoid(int i); 
	
	//! Mutator Functions
	
	//! add a boid to the flock
	void addBoid(Boid b); 
	//! Movement control for the flocking behaviour
	void flocking(); 
	//! Movement control for the swarming behaviour
	void swarming(); 
	//! Movement control for following a leader behaviour
	void cFormation(int fLeader); 
	//! Checks the bounds of the world as implementation of wrap round world
	void CheckBounds(); 
private:

};

#endif