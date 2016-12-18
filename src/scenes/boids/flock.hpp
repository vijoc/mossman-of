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
	std::shared_ptr<Boid> getBoid(int i) { return boids[i]; }
private:
	std::vector<std::shared_ptr<Boid>> boids;
};

#endif /* FLOCK_H */
