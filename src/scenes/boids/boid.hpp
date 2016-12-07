#include "ofMain.h"

class Boid {
public:
	Boid();
	Boid(float r);
	void update(std::vector<Boid> boids);
	ofVec2f getLocation() { return location; }
	ofVec2f getVelocity() { return velocity; }
	float getRadius() { return radius; }
private:
	void checkBounds();
	void separate(std::vector<Boid> boids);
	ofVec2f location;
	ofVec2f velocity;
	float radius;
};
