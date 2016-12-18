#include "ofMain.h"
#include "flock.hpp"

class BoidsRenderer {
public:
	BoidsRenderer(Flock& flock): flock(flock) {;}
	void draw();
	void setRenderingMode(int index);
private:
	Flock& flock;
	void renderTriangles();
	void renderClosestTriangles();
	std::vector<std::shared_ptr<Boid>> findClosestNeighbours(std::shared_ptr<Boid> b);
	static bool pairCompare(const pair<float, std::shared_ptr<Boid>>&i, const pair<float, std::shared_ptr<Boid>>&j) { return i.first < j.first; };
};
