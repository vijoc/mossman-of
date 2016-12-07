#ifndef FLOCK_H
#define FLOCK_H

#include "ofMain.h"
#include "boid.hpp"

class Flock
{
public:
	Flock();
	void draw();
	void update();
private:
	std::vector<Boid> boids;
};

#endif /* FLOCK_H */
