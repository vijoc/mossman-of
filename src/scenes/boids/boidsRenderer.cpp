#include "boidsRenderer.hpp"

RenderingModes mode = RenderingModes::Triangle;

int trianglesLimit = 32; // bad magic number, but try changing this to 3 or whatever

void BoidsRenderer::draw() {
	switch(mode) {
		case RenderingModes::Circle:
			for(int i = 0; i < flock.getSize(); i++) {
				std::shared_ptr<Boid> b = flock.getBoid(i);
				ofVec2f location = b->getLocation();
				float radius = b->getRadius();

				ofSetColor(0, 0, 0);
				ofDrawCircle(location, radius);
			}
			break;
		case RenderingModes::Triangle:
			renderTriangles();
			break;
		case RenderingModes::Closest:
			nr.renderClosestTriangles();
			break;
	}
}

void BoidsRenderer::setRenderingMode(RenderingModes rMode) {
	mode = rMode;
}

void BoidsRenderer::renderTriangles() {
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
