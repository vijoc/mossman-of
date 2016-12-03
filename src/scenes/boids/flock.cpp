#include "flock.hpp"

Flock::Flock() {
	x = 200.0;
	y = 200.0;
	for (int i = 0; i < 32; i++) {
		boids[i] = new Boid();
	}
}

void Flock::draw() {
	ofSetColor(255, 0, 0);
	ofDrawCircle(x, y, 20);
	for (int i = 0; i < 32; i++) {
		boids[i]->draw();
	}
}

void Flock::update() {

}
