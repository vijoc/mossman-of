#ifndef BOIDRULES_H
#define BOIDRULES_H

class BoidRules {
public:
	static float separationWeight;
	static float cohesionWeight;
	static float alignmentWeight;
	
	static float desiredSeparation;
	static float cohesionDist;
	static float alignmentDist;
};

#endif /* BOIDRULES_H */
