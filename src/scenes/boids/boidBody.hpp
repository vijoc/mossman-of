#ifndef BOIDBODY_H
#define BOIDBODY_H

#include "ofMain.h"
#include "rules.hpp"

class BoidBody {
public:
	BoidBody():
		rules(),
		location(ofVec2f(ofRandom(rules.radius, ofGetWidth()-rules.radius), ofRandom(rules.radius, ofGetHeight()-rules.radius))),
		velocity(ofVec2f(ofRandomf(), ofRandomf())),
		acceleration(ofVec2f(0, 0))
	{;}

	void	update();
	void	checkBounds();

	ofVec2f	getLocation() { return location; }
	void	setLocation(ofVec2f loc) { location = loc; }

	ofVec2f	getVelocity() { return velocity; }
	void	setVelocity(ofVec2f vel) { velocity = vel; }

	float	getRadius() { return rules.radius; }
	void	setRadius(float r) { rules.radius = r; }
	void	applyForce(ofVec2f force);

	void	setRules(Rules bodyRules) { rules = bodyRules; }
private:
	Rules rules;
	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
};

#endif /* BOIDBODY_H */
