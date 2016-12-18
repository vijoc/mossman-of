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
			renderClosestTriangles();
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

void BoidsRenderer::renderClosestTriangles() {
	for(int i = 0; i < flock.getSize(); i++) {
		std::shared_ptr<Boid> b = flock.getBoid(i);
		ofVec2f bLoc = b->getLocation();
		std::vector<std::shared_ptr<Boid>> neighbours = findClosestNeighbours(b);
		for(int j = 0; j < neighbours.size(); j++) {
			std::shared_ptr<Boid> c = neighbours[j];
			ofVec2f cLoc = c->getLocation();
			ofDrawLine(bLoc, cLoc);
		}
	}
}

std::vector<std::shared_ptr<Boid>> BoidsRenderer::findClosestNeighbours(std::shared_ptr<Boid> b) {
	std::vector<std::shared_ptr<Boid>> out;
	std::vector<std::pair<float, std::shared_ptr<Boid>>> distances;
	for(int i = 0; i < flock.getSize(); i++) {
		std::shared_ptr<Boid> c = flock.getBoid(i);
		float d = b->getLocation().distance(c->getLocation());
		distances.emplace_back(d, c);
	}
	std::sort(distances.begin(), distances.end(), pairCompare);
	for(int i = 0; i < 4; i++) {
		out.push_back(distances[i].second);
	}
	return out;
}
