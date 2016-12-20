#include "ofmain.h"
#include "flock.hpp"

class CircleRenderer {
public:
	CircleRenderer(Flock& flock): flock(flock) {;}
	void draw();
private:
	Flock& flock;
};
