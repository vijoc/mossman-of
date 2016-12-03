#include "boidsScene.hpp"

BoidsScene::BoidsScene() {
	flock = new Flock();
}

void BoidsScene::draw() {
	flock->draw();
}

void BoidsScene::update() {
	flock->update();
	return;
}
