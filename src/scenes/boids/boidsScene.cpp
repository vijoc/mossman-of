#include "boidsScene.hpp"

BoidsScene::BoidsScene() {
	x = 50.0;
	y = 50.0;
}

void BoidsScene::draw() {
	ofSetColor(0, 255, 0);
	ofDrawCircle(x, y, 20);
}

void BoidsScene::update() {
	return;
}
