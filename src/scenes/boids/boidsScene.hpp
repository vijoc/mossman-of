#include "ofMain.h"
#include "flock.hpp"
#include "boidsRenderer.hpp"

class BoidsScene
{
public:
	BoidsScene();
	void draw();
	void update();
private:
	Flock* flock;
	BoidsRenderer* boidsRenderer;
};
