#include "circleRenderer.hpp"

void CircleRenderer::draw() {
	for(int i = 0; i < flock.getSize(); i++) {
		std::shared_ptr<Boid> b = flock.getBoid(i);
		ofVec2f location = b->getLocation();
		float radius = b->getRadius();
		ofSetColor(0, 0, 0);
		ofDrawCircle(location, radius);
	}
}
