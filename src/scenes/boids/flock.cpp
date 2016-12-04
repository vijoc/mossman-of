#include "flock.hpp"

Flock::Flock() {
	for (int i = 0; i < 32; i++) {
		float r = 20.0f;
		if(i != 0) r = 10.0f;
		boids[i] = new Boid(r);
	}
}

void Flock::draw() {
	for (int i = 0; i < 32; i++) {
		boids[i]->draw();
	}
}

void Flock::update() {
	for (int i = 0; i < 32; i++) {
		boids[i]->update(*boids);
	}
}
