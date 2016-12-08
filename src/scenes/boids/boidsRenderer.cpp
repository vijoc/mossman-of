#include "boidsRenderer.hpp"

enum RenderingModes { Circle, Triangle, Closest };

RenderingModes mode = RenderingModes::Triangle;

int trianglesLimit = 32; // bad magic number, but try changing this to 3 or whatever

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
			renderTriangles();
			break;
		case RenderingModes::Closest:
			renderClosestTriangles();
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
	if(index == 2) {
		mode = RenderingModes::Closest;
	}
}

void BoidsRenderer::renderTriangles() {
	for(int i = 0; i < flock.getSize(); i++) {
		Boid b = flock.getBoid(i);
		ofVec2f bLoc = b.getLocation();

		for(int j = 0; j < trianglesLimit; j++) {
			Boid c = flock.getBoid(j);
			ofVec2f cLoc = c.getLocation();
			ofDrawLine(bLoc, cLoc);
		}
	}
}

void BoidsRenderer::renderClosestTriangles() {
	for(int i = 0; i < flock.getSize(); i++) {
		Boid b = flock.getBoid(i);
		ofVec2f bLoc = b.getLocation();
		std::vector<Boid> neighbours = findClosestNeighbours(b);
		for(int j = 0; j < neighbours.size(); j++) {
			Boid c = neighbours[j];
			ofVec2f cLoc = c.getLocation();
			ofDrawLine(bLoc, cLoc);
		}
	}
}

std::vector<Boid> BoidsRenderer::findClosestNeighbours(Boid b) {
	std::vector<Boid> out;
	std::vector<std::pair<Boid&, float>> distances;
	for(int i = 0; i < flock.getSize(); i++) {
		Boid c = flock.getBoid(i);
		float d = b.getLocation().distance(c.getLocation());
		distances.emplace_back(c, d);
	}
	for(int i = 0; i < 3; i++) {
		out.push_back(distances[i].first);
	}
	return out;
}
