#ifndef RULES_H
#define RULES_H

#include "ofMain.h"

class Rules {
public:
	Rules(): weight(10.0f), radius(10.0f), deceleration(0.3f), maxSpeed(2.0f) {;}

	static float separationWeight;
	static float cohesionWeight;
	static float alignmentWeight;

	float weight;
	float radius;
	float deceleration;
	float maxSpeed;

	static float desiredSeparation;
	static float cohesionDist;
	static float alignmentDist;
	enum class Boundaries { Wrap, Bounce };
};

#endif /* RULES_H */
