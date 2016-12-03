#include "boid.hpp"

Boid::Boid() {
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());
}

void Boid::draw() {
	ofSetColor(0, 0, 0);
	ofDrawCircle(x, y, 20);
}

void Boid::update() {

}
