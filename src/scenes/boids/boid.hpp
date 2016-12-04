#include "ofMain.h"

class Boid {
public:
	Boid();
	void draw();
	void update(Boid boids[]);
private:
	ofVec2f location;
	ofVec2f velocity;
	float radius;
	void checkBounds();
	void separate(Boid boids[]);
};
