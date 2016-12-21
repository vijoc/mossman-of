#ifndef BOIDRULES_H
#define BOIDRULES_H

class BoidRules {
public:
	BoidRules(): separationWeight(2.0), cohesionWeight(0.25), alignmentWeight(0.5), desiredSeparation(100), cohesionDist(150), alignmentDist(200) {;}
	BoidRules(float separation): desiredSeparation(separation), separationWeight(2.0), cohesionWeight(0.25), alignmentWeight(0.5), cohesionDist(150), alignmentDist(200) {;} // TODO testing

	friend std::ostream& operator << (std::ostream &strm, const BoidRules& br) { // TODO flesh out
		return strm << "BoidRules: sw: " << br.separationWeight << ", ds: " << br.desiredSeparation << "\n";
	}

	float separationWeight;
	float cohesionWeight;
	float alignmentWeight;

	float desiredSeparation;
	float cohesionDist;
	float alignmentDist;
};

#endif /* BOIDRULES_H */
