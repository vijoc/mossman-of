#include "flock.hpp"

static int flockSize = 64;
static int minimumFlockSize = 4; // some renderer segfaults if this is smaller, TODO fix

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
	if (boids.size() > minimumFlockSize) boids.erase(boids.end() - 1);
}

void Flock::setBoidRules(BoidRules boidRules) {
	for (int i = 0; i < boids.size(); i++) {
		boids[i]->setBoidRules(boidRules);
	}
}

void Flock::randomizeBoidRules() { // TODO continue from here
	BoidRules r(500);
	std::cout << r;
	setBoidRules(r);
}
