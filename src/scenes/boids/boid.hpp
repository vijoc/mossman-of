#include "ofMain.h"

class Boid {
public:
	Boid();
	Boid(float r);
	void draw();
	void update(Boid boids[]);
	ofVec2f location;
	ofVec2f velocity;
private:
	float radius;
	void checkBounds();
	void separate(Boid boids[]);
};
