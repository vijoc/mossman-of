#include "flock.hpp"

static int numberOfBoids = 256;

Flock::Flock() {
	for (int i = 0; i < numberOfBoids; i++) {
		boids.push_back(std::shared_ptr<Boid>(new Boid()));
	}
}

void Flock::update() {
	for (int i = 0; i < boids.size(); i++) {
		boids[i]->update(boids);
	}
}

void Flock::setRadius(float r) {
	for (int i = 0; i < numberOfBoids; i++) {
		boids[i]->setRadius(r);
	}
}
