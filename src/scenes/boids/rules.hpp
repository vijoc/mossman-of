#ifndef RULES_H
#define RULES_H

#include "ofMain.h"

class Rules {
public:
	enum class Boundaries { Wrap, Bounce, Inertial }; // TODO implement Inertial: basically apply force if over boundaries

	Rules(): weight(10.0f), radius(10.0f), deceleration(0.3f), maxSpeed(2.0f), bounds(Boundaries::Inertial) {;}

	Rules(float w, float r, float d, float ms, Boundaries b): weight(w), radius(r), deceleration(d), maxSpeed(ms), bounds(b) {;}

	static Rules getRandomRules() { // TODO needs sensible ranges
		float w = ofRandom(1, 20);
		float r = ofRandom(1, 20);
		float d = ofRandom(0.1, 0.95);
		float ms = ofRandom(0, 5);
		Boundaries b = static_cast<Boundaries>(rand() % 3);
		return Rules(w, r, d, ms, b);
	}

	friend std::ostream& operator << (std::ostream& strm, const Rules& r) {
		return strm << "Rules: \n"
			<< "weight: " << r.weight << "\n"
			<< "radius: " << r.radius << "\n"
			<< "deceleration: " << r.deceleration << "\n"
			<< "maxSpeed: " << r.maxSpeed << "\n"
			<< "bounds: " << static_cast<int>(r.bounds) << "\n";
	}

	float weight;
	float radius;
	float deceleration;
	float maxSpeed; // TODO move this to Boid to control flocking, but still allow e.g. gravitational acceleration

	Boundaries bounds;
};

#endif /* RULES_H */
