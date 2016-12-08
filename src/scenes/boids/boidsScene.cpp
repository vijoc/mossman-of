#include "boidsScene.hpp"

BoidsScene::BoidsScene() {
	flock = new Flock();
	boidsRenderer = new BoidsRenderer(*flock);
}

void BoidsScene::draw() {
	boidsRenderer->draw();
}

void BoidsScene::update() {
	flock->update();
	return;
}

void BoidsScene::activate() {
	return;
}

void BoidsScene::deactivate() {
	return;
}

void BoidsScene::keyPress(int key) {
	return;
}
