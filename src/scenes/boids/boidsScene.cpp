#include "boidsScene.hpp"

BoidsScene::BoidsScene() {
	flock = new Flock();
	boidsRenderer = new BoidsRenderer(*flock);
}

void BoidsScene::draw() {
	boidsRenderer->draw();
}

void BoidsScene::update(float dt) {
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
		boidsRenderer->setRenderingMode(RenderingModes::Circle);
	}
	if(key == 'w') {
		boidsRenderer->setRenderingMode(RenderingModes::Glitchy);
	}
	if(key == 'e') {
		boidsRenderer->setRenderingMode(RenderingModes::Closest);
	}
	return;
}
