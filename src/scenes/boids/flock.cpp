#include "flock.hpp"

Flock::Flock() {
	x = 200.0;
	y = 200.0;
}

void Flock::draw() {
	ofSetColor(255, 0, 0);
	ofDrawCircle(x, y, 20);
}

void Flock::update() {

}
