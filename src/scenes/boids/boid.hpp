#include "ofMain.h"

class Boid {
public:
	Boid();
	Boid(float r);
	void draw();
	void update(std::vector<Boid> boids);
	ofVec2f location;
	ofVec2f velocity;
	float radius;
private:
	void checkBounds();
	void separate(std::vector<Boid> boids);
};
