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
	std::vector<Boid> findClosestNeighbours(Boid b);
	static bool pairCompare(const pair<float, Boid>&i, const pair<float, Boid>&j) { return i.first < j.first; };
};
