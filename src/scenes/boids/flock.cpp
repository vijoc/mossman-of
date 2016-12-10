#include "flock.hpp"

static int numberOfBoids = 256;

Flock::Flock() {
	for (int i = 0; i < numberOfBoids; i++) {
		boids.push_back(Boid());
	}
}

void Flock::update() {
	for (int i = 0; i < boids.size(); i++) {
		boids[i].update(boids);
	}
}
