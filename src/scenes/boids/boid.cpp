#include "boid.hpp"

Boid::Boid() {
	location = ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
}

void Boid::draw() {
	ofSetColor(0, 0, 0);
	ofDrawCircle(location, 20);
}

void Boid::update() {
	location.x += 1;
	if(location.x > ofGetWidth()) location.x = 0;
}
