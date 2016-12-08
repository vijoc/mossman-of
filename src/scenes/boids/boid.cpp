#include "boid.hpp"
#include "rules.hpp"

enum Boundaries { Wrap, Bounce };

static Boundaries bounds = Boundaries::Bounce;

Boid::Boid() {
	acceleration = ofVec2f(0, 0);
	radius = 10;
	weight = Rules::weight;
	deceleration = 0.3;
	float x = ofRandom(radius, ofGetWidth() - radius);
	float y = ofRandom(radius, ofGetHeight() - radius);
	location = ofVec2f(x, y);
	velocity = ofVec2f(ofRandomf(), ofRandomf());
}

void Boid::update(std::vector<Boid> boids) {
	velocity += acceleration;
	if(velocity.length() > 2) velocity.scale(2);
	location += velocity;
	acceleration *= deceleration;
	flock(boids);
	checkBounds();
}

void Boid::checkBounds() {
	switch(bounds) {
		case Boundaries::Wrap :
			if(location.x > ofGetWidth() + radius) location.x = -radius;
			if(location.x < -radius) location.x = ofGetWidth() + radius;
			if(location.y > ofGetHeight() + radius) location.y = -radius;
			if(location.y < -radius) location.y = ofGetHeight() + radius;
			break;
		case Boundaries::Bounce :
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

void Boid::flock(std::vector<Boid> boids) {
	ofVec2f separation = separate(boids);
	separation *= 2;
	ofVec2f cohesion = cohere(boids);
	cohesion /= 8;
	ofVec2f alignment = align(boids);
	alignment /= 16;

	applyForce(separation);
	applyForce(cohesion);
	applyForce(alignment);
}

void Boid::applyForce(ofVec2f force) {
	acceleration = acceleration + (force / weight);
}

ofVec2f Boid::separate(std::vector<Boid> boids) {
	ofVec2f c = ofVec2f(0, 0);
	for(int i = 0; i < boids.size(); i++) {
		Boid b = boids[i];
		float distance = location.distance(b.getLocation());
		if(distance < 50 && distance > 0) {
			ofVec2f d = b.getLocation() - location;
			d.normalize();
			c += d;
		}
	}
	return -c;
}

ofVec2f Boid::cohere(std::vector<Boid> boids) {
	ofVec2f c = ofVec2f(0, 0);
	for(int i = 0; i < boids.size(); i++) {
		Boid b = boids[i];
		float distance = location.distance(b.getLocation());
		if(distance < 150 && distance > 0) {
			ofVec2f d = b.getLocation() - location;
			d.normalize();
			c += d;
		}
	}
	return c;
}

ofVec2f Boid::align(std::vector<Boid> boids) {
	ofVec2f c = ofVec2f(0, 0);
	for(int i = 0; i < boids.size(); i++) {
		Boid b = boids[i];
		float distance = location.distance(b.getLocation());
		if(distance < 150 && distance > 0) {
			ofVec2f d = b.getVelocity();
			d.normalize();
			c += d;
		}
	}
	return c;
}
