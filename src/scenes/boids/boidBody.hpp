#ifndef BOIDBODY_H
#define BOIDBODY_H

#include "ofMain.h"
#include "rules.hpp"

class BoidBody {
public:
	BoidBody():
		rules(),
		radius(rules.radius),
		weight(rules.weight),
		bounds(Rules::Boundaries::Wrap),
		location(ofVec2f(ofRandom(radius, ofGetWidth()-radius), ofRandom(radius, ofGetHeight()-radius))),
		velocity(ofVec2f(ofRandomf(), ofRandomf())),
		acceleration(ofVec2f(0, 0)),
		deceleration(rules.deceleration)
	{;}

	void	update();
	void	checkBounds();

	ofVec2f	getLocation() { return location; }
	void	setLocation(ofVec2f loc) { location = loc; }

	ofVec2f	getVelocity() { return velocity; }
	void	setVelocity(ofVec2f vel) { velocity = vel; }

	float	getRadius() { return radius; }
	void	setRadius(float r) { radius = r; }
	void	applyForce(ofVec2f force);
private:
	Rules rules;
	float radius;
	float weight;
	Rules::Boundaries bounds;
	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
	float deceleration;
};

#endif /* BOIDBODY_H */
