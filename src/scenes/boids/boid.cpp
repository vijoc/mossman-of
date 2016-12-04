#include "boid.hpp"

Boid::Boid() {
	location = ofVec2f(ofRandomWidth(), ofRandomHeight());
	velocity = ofVec2f(ofRandomf(), ofRandomf());
	radius = 20;
}

void Boid::draw() {
	ofSetColor(0, 0, 0);
	ofDrawCircle(location, radius);
}

void Boid::update() {
	location += velocity;
	if(location.x > ofGetWidth() + radius) location.x = -radius;
	if(location.x < -radius) location.x = ofGetWidth() + radius;
	if(location.y > ofGetHeight() + radius) location.y = -radius;
	if(location.y < -radius) location.y = ofGetHeight() + radius;
}
