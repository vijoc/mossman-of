#include "boidsRenderer.hpp"

enum RenderingModes { Circle, Triangle };

RenderingModes mode = RenderingModes::Triangle;

void BoidsRenderer::draw() {
	switch(mode) {
		case RenderingModes::Circle:
			for(int i = 0; i < flock.getSize(); i++) {
				Boid b = flock.getBoid(i);
				ofVec2f location = b.getLocation();
				float radius = b.getRadius();

				ofSetColor(0, 0, 0);
				ofDrawCircle(location, radius);
			}
			break;
		case RenderingModes::Triangle:
			break;
	}
}

void BoidsRenderer::setRenderingMode(int index) {
	if(index == 0) {
		mode = RenderingModes::Circle;	
	}
	if(index == 1) {
		mode = RenderingModes::Triangle;
	}
}
