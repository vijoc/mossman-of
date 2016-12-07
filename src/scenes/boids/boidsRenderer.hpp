#include "ofMain.h"
#include "flock.hpp"

class BoidsRenderer {
public:
	BoidsRenderer(Flock& flock): flock(flock) {;}
	void draw();
private:
	Flock& flock;
};
