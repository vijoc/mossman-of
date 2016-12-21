#ifndef RULES_H
#define RULES_H

#include "ofMain.h"

class Rules {
public:
	enum class Boundaries { Wrap, Bounce };

	Rules(): weight(10.0f), radius(10.0f), deceleration(0.3f), maxSpeed(2.0f), bounds(Boundaries::Wrap) {;}

	Rules(float w, float r, float d, float ms, Boundaries b): weight(w), radius(r), deceleration(d), maxSpeed(ms), bounds(b) {;}

	static Rules getRandomRules() { // TODO needs sensible ranges
		float w = ofRandom(1, 20);
		float r = ofRandom(1, 20);
		float d = ofRandom(0.1, 0.95);
		float ms = ofRandom(0, 5);
		Boundaries b = static_cast<Boundaries>(rand() % 2);
		return Rules(w, r, d, ms, b);
	}

	float weight;
	float radius;
	float deceleration;
	float maxSpeed;

	Boundaries bounds;
};

#endif /* RULES_H */
