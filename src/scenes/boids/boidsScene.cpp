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
	if(key == 'q') {
		boidsRenderer->setRenderingMode(0);
	}
	if(key == 'w') {
		boidsRenderer->setRenderingMode(1);
	}
	return;
}
