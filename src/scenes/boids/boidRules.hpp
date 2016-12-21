#ifndef BOIDRULES_H
#define BOIDRULES_H

class BoidRules {
public:
	BoidRules(): separationWeight(2.0), cohesionWeight(0.25), alignmentWeight(0.5), desiredSeparation(100), cohesionDist(150), alignmentDist(200) {;}

	BoidRules(float sw, float cw, float aw, float ds, float cd, float ad):
		separationWeight(sw),
		cohesionWeight(cw),
		alignmentWeight(aw),
		desiredSeparation(ds),
		cohesionDist(cd),
		alignmentDist(ad) {;}

	static BoidRules getRandomBoidRules() { // TODO needs sensible ranges
		float sw = ofRandom(0, 4);
		float cw = ofRandom(0, 4);
		float aw = ofRandom(0, 4);
		float ds = ofRandom(0, 400);
		float cd = ofRandom(0, 400);
		float ad = ofRandom(0, 400);
		return BoidRules(sw, cw, aw, ds, cd, ad);
	}

	friend std::ostream& operator << (std::ostream& strm, const BoidRules& br) {
		return strm << "BoidRules: \n"
			<< "separationWeight: " << br.separationWeight << "\n"
			<< "cohesionWeight: " << br.cohesionWeight << "\n"
			<< "alignmentWeight: " << br.alignmentWeight << "\n"
			<< "desiredSeparation: " << br.desiredSeparation << "\n"
			<< "cohesionDist: " << br.cohesionDist << "\n"
			<< "alignmentDist: " << br.alignmentDist << "\n";
	}

	float separationWeight;
	float cohesionWeight;
	float alignmentWeight;

	float desiredSeparation;
	float cohesionDist;
	float alignmentDist;
};

#endif /* BOIDRULES_H */
