#include "ofMain.h"
#include "boid.hpp"

class Flock
{
public:
	Flock();
	void draw();
	void update();
private:
	float x;
	float y;
	Boid *boids [32];
};
