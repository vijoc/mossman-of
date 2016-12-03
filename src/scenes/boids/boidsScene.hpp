#include "ofMain.h"
#include "flock.hpp"

class BoidsScene
{
public:
	BoidsScene();
	void draw();
	void update();
private:
	Flock* flock;
};
