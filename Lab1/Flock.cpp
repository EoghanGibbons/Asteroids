#include "Flock.h"

// =============================================== //
// ======== Flock Functions from Flock.h ========= //
// =============================================== //

Flock::Flock() {
	
}

Flock::~Flock() {
	std::cout << "Flock is being deleted by destructor!" << std::endl;
}

int Flock::getSize()
{
	return flock.size();
}

Boid Flock::getBoid(int i)
{
	return flock[i];
}

void Flock::addBoid(Boid b)
{
	flock.push_back(b);
}

// Runs the run function for every boid in the flock checking against the flock
// itself. Which in turn applies all the rules to the flock.
void Flock::flocking()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].run(flock);
	}
}
// Runs the swarm function for every boid in the flock checking against the flock
// itself. Which in turn applies all the rules to the flock.
void Flock::swarming()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].swarm(flock);
	}
}