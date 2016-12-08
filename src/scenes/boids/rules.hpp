#include "ofMain.h"

class Rules {
public:
	static float weight;
	static float radius;
	static float deceleration;
	static float maxSpeed;

	static float separationWeight;
	static float cohesionWeight;
	static float alignmentWeight;

	static float desiredSeparation;
	static float cohesionDist;
	static float alignmentDist;
};
