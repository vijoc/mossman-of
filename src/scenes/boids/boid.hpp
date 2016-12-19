#ifndef BOID_H
#define BOID_H

#include "ofMain.h"
#include "boidBody.hpp"

class Boid {
public:
	Boid(): body() {;}
	void update(std::vector<std::shared_ptr<Boid>> boids);
	ofVec2f getLocation() { return body.getLocation(); }
	ofVec2f getVelocity() { return body.getVelocity(); }
	float getRadius() { return body.getRadius(); }
private:
	BoidBody body;
	void applyForce(ofVec2f force);
	void flock(std::vector<std::shared_ptr<Boid>> boids);
	ofVec2f separate(std::vector<std::shared_ptr<Boid>> boids);
	ofVec2f cohere(std::vector<std::shared_ptr<Boid>> boids);
	ofVec2f align(std::vector<std::shared_ptr<Boid>> boids);
};

#endif /* BOID_H */
