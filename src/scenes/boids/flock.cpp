#include "flock.hpp"

Flock::Flock() {
	for (int i = 0; i < 32; i++) {
		boids[i] = new Boid();
	}
}

void Flock::draw() {
	for (int i = 0; i < 32; i++) {
		boids[i]->draw();
	}
}

void Flock::update() {
	for (int i = 0; i < 32; i++) {
		boids[i]->update();
	}
}
