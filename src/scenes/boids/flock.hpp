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
	std::shared_ptr<Boid> getBoid(int i) { return boids[i]; } // TODO should be unique_ptr
	void setRadius(float r);
	void addBoid();
	void removeBoid();
	void randomizeBoidRules();
	void setBoidRules(BoidRules boidRules);
private:
	std::vector<std::shared_ptr<Boid>> boids;
};

#endif /* FLOCK_H */
