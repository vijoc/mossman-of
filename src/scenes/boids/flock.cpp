#include "flock.hpp"

static int flockSize = 64;

Flock::Flock() {
	for (int i = 0; i < flockSize; i++) {
		boids.push_back(std::shared_ptr<Boid>(new Boid()));
	}
}

void Flock::update() {
	for (int i = 0; i < boids.size(); i++) {
		boids[i]->update(boids);
	}
}

void Flock::setRadius(float r) {
	for (int i = 0; i < boids.size(); i++) {
		boids[i]->setRadius(r);
	}
}

void Flock::addBoid() {
	boids.push_back(std::shared_ptr<Boid>(new Boid()));
}

void Flock::removeBoid() {
	boids.erase(boids.end() - 1);
}
