#include "boid.hpp"

enum Boundaries { Wrap, Bounce };

static Boundaries bounds = Boundaries::Bounce;

Boid::Boid() {
	location = ofVec2f(ofRandomWidth(), ofRandomHeight());
	velocity = ofVec2f(ofRandomf(), ofRandomf());
	radius = 20;
}

Boid::Boid(float r) {
	location = ofVec2f(ofRandomWidth(), ofRandomHeight());
	velocity = ofVec2f(ofRandomf(), ofRandomf());
	radius = r;
}

void Boid::update(std::vector<Boid> boids) {
	if(velocity.length() > 2) velocity.scale(2);
	location += velocity;
	separate(boids);
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
			if(location.x > ofGetWidth() - radius || location.x < radius) velocity.x = -velocity.x;
			if(location.y > ofGetHeight() - radius || location.y < radius) velocity.y = -velocity.y;
			break;
	}
}

void Boid::separate(std::vector<Boid> boids) {
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
	velocity -= c;
}
