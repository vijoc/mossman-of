#include "ofMain.h"
#include "flock.hpp"

class BoidsScene
{
public:
	BoidsScene();
	void draw();
	void update();
private:
	float x;
	float y;
	Flock* flock;
};
