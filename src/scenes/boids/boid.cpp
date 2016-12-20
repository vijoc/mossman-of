#include "boid.hpp"
#include "rules.hpp"

void Boid::update(std::vector<std::shared_ptr<Boid>> boids) {
	body.update();
	flock(boids);
	body.checkBounds();
}

void Boid::flock(std::vector<std::shared_ptr<Boid>> boids) {
	ofVec2f separation = separate(boids) * Rules::separationWeight;
	ofVec2f cohesion   = cohere(boids)   * Rules::cohesionWeight;
	ofVec2f alignment  = align(boids)    * Rules::alignmentWeight;

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
		if(distance < Rules::desiredSeparation && distance > 0) {
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
		if(distance < Rules::cohesionDist && distance > 0) {
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
		if(distance < Rules::alignmentDist && distance > 0) {
			ofVec2f d = b->getVelocity();
			d.normalize();
			c += d;
		}
	}
	return c;
}
