#include "boidBody.hpp"

void BoidBody::update() {
	velocity += acceleration;
	if(velocity.length() > Rules::maxSpeed) velocity.scale(Rules::maxSpeed);
	location += velocity;
	acceleration *= deceleration;
	checkBounds();
}

void BoidBody::checkBounds() {
	switch(bounds) {
		case Rules::Boundaries::Wrap :
			if(location.x > ofGetWidth() + radius) location.x = -radius;
			if(location.x < -radius) location.x = ofGetWidth() + radius;
			if(location.y > ofGetHeight() + radius) location.y = -radius;
			if(location.y < -radius) location.y = ofGetHeight() + radius;
			break;
		case Rules::Boundaries::Bounce :
			if(location.x > ofGetWidth() - radius) {
				velocity.x = -velocity.x;
				location.x -= 2 * (location.x - (ofGetWidth() - radius)); // bounce back
			}
			if(location.x < radius) {
				velocity.x = -velocity.x;
				location.x -= 2 * (location.x - radius); // bounce back
			}
			if(location.y > ofGetHeight() - radius) {
				velocity.y = -velocity.y;
				location.y -= 2 * (location.y - (ofGetHeight() - radius)); // bounce back
			}
			if(location.y < radius) {
				velocity.y = -velocity.y;
			location.y -= 2 * (location.y - radius); // bounce back
			}
			break;
	}
}

void BoidBody::applyForce(ofVec2f force) {
	acceleration = acceleration + (force / weight);
}
