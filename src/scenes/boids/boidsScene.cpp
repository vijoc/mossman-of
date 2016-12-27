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
	if(key == 'r') {
		flock->randomizeBoidRules();
	}
	if(key == 't') {
		flock->randomizeBoidBodyRules();
	}
	if(key == OF_KEY_UP) {
		flock->addBoid();
	}
	if(key == OF_KEY_DOWN) {
		flock->removeBoid();
	}
	if(key == OF_KEY_LEFT) {
		boidsRenderer->decreaseNumberOfNeighbours();
	}
	if(key == OF_KEY_RIGHT) {
		boidsRenderer->increaseNumberOfNeighbours();
	}
	return;
}
