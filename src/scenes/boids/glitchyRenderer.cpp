#include "glitchyRenderer.hpp"

int trianglesLimit = 3;

void GlitchyRenderer::draw() {
	for(int i = 0; i < flock.getSize(); i++) {
		std::shared_ptr<Boid> b = flock.getBoid(i);
		ofVec2f bLoc = b->getLocation();
		for(int j = 0; j < trianglesLimit; j++) {
			std::shared_ptr<Boid> c = flock.getBoid(j);
			ofVec2f cLoc = c->getLocation();
			ofDrawLine(bLoc, cLoc);
		}
	}
}
