#include "ofmain.h"
#include "flock.hpp"

class NeighbourRenderer {
public:
	NeighbourRenderer(Flock& flock): flock(flock) {;}
	void draw();
	void increaseNumberOfNeighbours() { if ( numberOfNeighbours < flock.getSize() ) numberOfNeighbours++; }
	void decreaseNumberOfNeighbours() { if ( numberOfNeighbours > 1 ) numberOfNeighbours--; }
private:
	int numberOfNeighbours = 4;
	Flock& flock;
	std::vector<std::shared_ptr<Boid>> findClosestNeighbours(std::shared_ptr<Boid> b);
	static bool pairCompare(const pair<float, std::shared_ptr<Boid>>&i, const pair<float, std::shared_ptr<Boid>>&j) { return i.first < j.first; };
};
