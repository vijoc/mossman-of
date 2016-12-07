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
