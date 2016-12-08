#include "ofMain.h"

class Boid {
public:
	Boid();
	void update(std::vector<Boid> boids);
	ofVec2f getLocation() { return location; }
	ofVec2f getVelocity() { return velocity; }
	float getRadius() { return radius; }
private:
	void checkBounds();
	void applyForce(ofVec2f force);
	void flock(std::vector<Boid> boids);
	ofVec2f separate(std::vector<Boid> boids);
	ofVec2f cohere(std::vector<Boid> boids);
	ofVec2f align(std::vector<Boid> boids);
	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
	float radius;
	float weight;
	float deceleration;
};
