#include "flock.hpp"

static int numberOfBoids = 32;

Flock::Flock() {
	for (int i = 0; i < numberOfBoids; i++) {
		float r = 10.0f;
		boids.push_back(Boid(r));
	}
}

void Flock::update() {
	for (int i = 0; i < boids.size(); i++) {
		boids[i].update(boids);
	}
}
