#include "boid.hpp"
#include "rules.hpp"

static Rules::Boundaries bounds = Rules::Boundaries::Wrap;

Boid::Boid() {
	acceleration = ofVec2f(0, 0);
	radius = Rules::radius;
	weight = Rules::weight;
	deceleration = Rules::deceleration;
	float x = ofRandom(radius, ofGetWidth() - radius);
	float y = ofRandom(radius, ofGetHeight() - radius);
	location = ofVec2f(x, y);
	velocity = ofVec2f(ofRandomf(), ofRandomf());
}

void Boid::update(std::vector<std::shared_ptr<Boid>> boids) {
	velocity += acceleration;
	if(velocity.length() > Rules::maxSpeed) velocity.scale(Rules::maxSpeed);
	location += velocity;
	acceleration *= deceleration;
	flock(boids);
	checkBounds();
}

void Boid::checkBounds() {
	switch(bounds) {
		case Rules::Boundaries::Wrap :
			if(location.x > ofGetWidth() + radius) location.x = -radius;
			if(location.x < -radius) location.x = ofGetWidth() + radius;
			if(location.y > ofGetHeight() + radius) location.y = -radius;
			if(location.y < -radius) location.y = ofGetHeight() + radius;
			break;
		case Rules::Boundaries::Bounce :
			if(location.x > ofGetWidth() - radius) {
				velocity.x = -velocity.x;
				location.x -= 2 * (location.x - (ofGetWidth() - radius)); // bounce back
			}
			if(location.x < radius) {
				velocity.x = -velocity.x;
				location.x -= 2 * (location.x - radius); // bounce back
			}
			if(location.y > ofGetHeight() - radius) {
				velocity.y = -velocity.y;
				location.y -= 2 * (location.y - (ofGetHeight() - radius)); // bounce back
			}
			if(location.y < radius) {
				velocity.y = -velocity.y;
				location.y -= 2 * (location.y - radius); // bounce back
			}
			break;
	}
}

void Boid::flock(std::vector<std::shared_ptr<Boid>> boids) {
	ofVec2f separation = separate(boids) * Rules::separationWeight;
	ofVec2f cohesion   = cohere(boids)   * Rules::cohesionWeight;
	ofVec2f alignment  = align(boids)    * Rules::alignmentWeight;

	applyForce(separation);
	applyForce(cohesion);
	applyForce(alignment);
}

void Boid::applyForce(ofVec2f force) {
	acceleration = acceleration + (force / weight);
}

ofVec2f Boid::separate(std::vector<std::shared_ptr<Boid>> boids) {
	ofVec2f c = ofVec2f(0, 0);
	for(int i = 0; i < boids.size(); i++) {
		std::shared_ptr<Boid> b = boids[i];
		float distance = location.distance(b->getLocation());
		if(distance < Rules::desiredSeparation && distance > 0) {
			ofVec2f d = b->getLocation() - location;
			d.normalize();
			c += d;
		}
	}
	return -c;
}

ofVec2f Boid::cohere(std::vector<std::shared_ptr<Boid>> boids) {
	ofVec2f c = ofVec2f(0, 0);
	for(int i = 0; i < boids.size(); i++) {
		std::shared_ptr<Boid> b = boids[i];
		float distance = location.distance(b->getLocation());
		if(distance < Rules::cohesionDist && distance > 0) {
			ofVec2f d = b->getLocation() - location;
			d.normalize();
			c += d;
		}
	}
	return c;
}

ofVec2f Boid::align(std::vector<std::shared_ptr<Boid>> boids) {
	ofVec2f c = ofVec2f(0, 0);
	for(int i = 0; i < boids.size(); i++) {
		std::shared_ptr<Boid> b = boids[i];
		float distance = location.distance(b->getLocation());
		if(distance < Rules::alignmentDist && distance > 0) {
			ofVec2f d = b->getVelocity();
			d.normalize();
			c += d;
		}
	}
	return c;
}
