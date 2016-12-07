#include "boidsRenderer.hpp"

void BoidsRenderer::draw() {
	for(int i = 0; i < flock.getSize(); i++) {
		Boid b = flock.getBoid(i);
		ofVec2f location = b.getLocation();
		float radius = b.getRadius();

		ofSetColor(0, 0, 0);
		ofDrawCircle(location, radius);
	}
}
