#include "ofMain.h"
#include "flock.hpp"
#include "renderingModes.hpp"
#include "neighbourRenderer.hpp"

class BoidsRenderer {
public:
	BoidsRenderer(Flock& flock): flock(flock), nr(flock) {;}
	void draw();
	void setRenderingMode(RenderingModes rMode);
private:
	NeighbourRenderer nr;
	Flock& flock;
	void renderTriangles();
};
