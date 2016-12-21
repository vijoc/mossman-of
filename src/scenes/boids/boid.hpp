#ifndef BOID_H
#define BOID_H

#include "ofMain.h"
#include "boidBody.hpp"
#include "boidRules.hpp"

class Boid {
public:
	Boid(): body(), rules() {;}
	void update(std::vector<std::shared_ptr<Boid>> boids);
	ofVec2f getLocation() { return body.getLocation(); }
	ofVec2f getVelocity() { return body.getVelocity(); }
	void setRadius(float f) { body.setRadius(f); }
	float getRadius() { return body.getRadius(); }
	void setBoidRules(BoidRules boidRules) { rules = boidRules; }
private:
	BoidBody body;
	BoidRules rules;
	void applyForce(ofVec2f force);
	void flock(std::vector<std::shared_ptr<Boid>> boids);
	ofVec2f separate(std::vector<std::shared_ptr<Boid>> boids);
	ofVec2f cohere(std::vector<std::shared_ptr<Boid>> boids);
	ofVec2f align(std::vector<std::shared_ptr<Boid>> boids);
};

#endif /* BOID_H */
