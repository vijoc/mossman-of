#include "boid.hpp"

void Boid::update(std::vector<std::shared_ptr<Boid>> boids) {
	body.update();
	// applyForce(ofVec2f(0, 10)); // TODO separate gravity to proper control
	flock(boids);
}

void Boid::flock(std::vector<std::shared_ptr<Boid>> boids) {
	ofVec2f separation = separate(boids) * rules.separationWeight;
	ofVec2f cohesion   = cohere(boids)   * rules.cohesionWeight;
	ofVec2f alignment  = align(boids)    * rules.alignmentWeight;

	applyForce(separation);
	applyForce(cohesion);
	applyForce(alignment);
}

void Boid::applyForce(ofVec2f force) {
	body.applyForce(force);
}

ofVec2f Boid::separate(std::vector<std::shared_ptr<Boid>> boids) {
	ofVec2f c = ofVec2f(0, 0);
	for(int i = 0; i < boids.size(); i++) {
		std::shared_ptr<Boid> b = boids[i];
		ofVec2f location = body.getLocation();
		float distance = location.distance(b->getLocation());
		if(distance < rules.desiredSeparation && distance > 0) {
			ofVec2f d = b->getLocation() - location;
			d.normalize();
			d /= distance;
			d *= 100.0; // magic number to balance behavior for now -> TODO move to rules
			c += d;
		}
	}
	return -c;
}

ofVec2f Boid::cohere(std::vector<std::shared_ptr<Boid>> boids) {
	ofVec2f c = ofVec2f(0, 0);
	for(int i = 0; i < boids.size(); i++) {
		std::shared_ptr<Boid> b = boids[i];
		ofVec2f location = body.getLocation();
		float distance = location.distance(b->getLocation());
		if(distance < rules.cohesionDist && distance > 0) {
			ofVec2f d = b->getLocation() - location;
			d.normalize();
			c += d;
		}
	}
	return c;
}

ofVec2f Boid::align(std::vector<std::shared_ptr<Boid>> boids) {
	ofVec2f c = ofVec2f(0, 0);
	for(int i = 0; i < boids.size(); i++) {
		std::shared_ptr<Boid> b = boids[i];
		ofVec2f location = body.getLocation();
		float distance = location.distance(b->getLocation());
		if(distance < rules.alignmentDist && distance > 0) {
			ofVec2f d = b->getVelocity();
			d.normalize();
			c += d;
		}
	}
	return c;
}
