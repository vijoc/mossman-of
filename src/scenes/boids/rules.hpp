#ifndef RULES_H
#define RULES_H

#include "ofMain.h"

class Rules {
public:
	Rules(): weight(10.0f), radius(10.0f), deceleration(0.3f), maxSpeed(2.0f) {;}

	float weight;
	float radius;
	float deceleration;
	float maxSpeed;

	enum class Boundaries { Wrap, Bounce };
};

#endif /* RULES_H */
