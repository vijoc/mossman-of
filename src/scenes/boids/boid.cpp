#include "boid.hpp"

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

void Boid::draw() {
	ofSetColor(0, 0, 0);
	ofDrawCircle(location, radius);
}

void Boid::update(Boid boids[]) {
	if(velocity.length() > 2) velocity.scale(2);
	location += velocity;
	separate(boids);
	checkBounds();
}

void Boid::checkBounds() {
	if(location.x > ofGetWidth() + radius) location.x = -radius;
	if(location.x < -radius) location.x = ofGetWidth() + radius;
	if(location.y > ofGetHeight() + radius) location.y = -radius;
	if(location.y < -radius) location.y = ofGetHeight() + radius;
}

void Boid::separate(Boid boids[]) {
	ofVec2f c = ofVec2f(0, 0);
	for(int i = 0; i < 32; i++) {
		Boid b = boids[i];
		if(b.location.distance(location) < 100 && b.location.distance(location) > 0) {
			c += (b.location - location);
		}
	}
	velocity -= c.normalize();
}
