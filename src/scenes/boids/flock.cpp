#include "flock.hpp"

Flock::Flock() {
	for (int i = 0; i < 32; i++) {
		float r = 10.0f;
		boids.push_back(Boid(r));
	}
}

void Flock::draw() {
	for (int i = 0; i < 32; i++) {
		boids[i].draw();
	}
}

void Flock::update() {
	for (int i = 0; i < 32; i++) {
		boids[i].update(boids);
	}
}
