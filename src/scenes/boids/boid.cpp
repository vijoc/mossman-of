#include "boid.hpp"

Boid::Boid() {
	x = 300.0;
	y = 300.0;
}

void Boid::draw() {
	ofSetColor(255, 0, 0);
	ofDrawCircle(x, y, 20);
}

void Boid::update() {

}
