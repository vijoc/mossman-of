#ifndef FLOCK_H
#define FLOCK_H

#include "ofMain.h"
#include "boid.hpp"

class Flock
{
public:
	Flock();
	void update();
	int getSize() { return boids.size(); }
	Boid getBoid(int i) { return boids[i]; }
private:
	std::vector<Boid> boids;
};

#endif /* FLOCK_H */
