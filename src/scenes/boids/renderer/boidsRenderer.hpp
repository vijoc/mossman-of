#include "ofMain.h"
#include "flock.hpp"
#include "renderingModes.hpp"
#include "neighbourRenderer.hpp"
#include "circleRenderer.hpp"
#include "glitchyRenderer.hpp"

class BoidsRenderer {
public:
	BoidsRenderer(Flock& flock): flock(flock), nr(flock), cr(flock), gr(flock) {;}
	void draw();
	void setRenderingMode(RenderingModes rMode);
private:
	Flock& flock;
	NeighbourRenderer nr;
	CircleRenderer cr;
	GlitchyRenderer gr;
	void renderTriangles();
};
