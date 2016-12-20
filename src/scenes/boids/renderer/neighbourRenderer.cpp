#include "neighbourRenderer.hpp"

void NeighbourRenderer::draw() {
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

std::vector<std::shared_ptr<Boid>> NeighbourRenderer::findClosestNeighbours(std::shared_ptr<Boid> b) {
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

