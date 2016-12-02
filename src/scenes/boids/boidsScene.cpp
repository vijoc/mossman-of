#include "boidsScene.hpp"

BoidsScene::BoidsScene() {
	x = 50.0;
	y = 50.0;
	flock = new Flock();
}

void BoidsScene::draw() {
	ofSetColor(0, 255, 0);
	ofDrawCircle(x, y, 20);
	flock->draw();
}

void BoidsScene::update() {
	flock->update();
	return;
}
