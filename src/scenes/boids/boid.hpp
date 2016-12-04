#include "ofMain.h"

class Boid {
public:
	Boid();
	void draw();
	void update();
private:
	ofVec2f location;
	ofVec2f velocity;
	float radius;
};
