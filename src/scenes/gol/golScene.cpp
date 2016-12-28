#include "golScene.hpp"
#include "goodRuleSets.hpp"

void GolScene::draw() {
	const auto worldCopy = world; // double buffering
	auto cols = worldCopy.colCount();
	auto rows = worldCopy.rowCount();
	float cellWidth = (float) ofGetWidth() / (float) cols;
	float cellHeight= (float) ofGetHeight() / (float) rows;
	if(cellWidth < 1) cellWidth = 1.0f;
	if(cellHeight < 1) cellHeight = 1.0f;
	for(int i = 0; i < cols; i++) {
		for(int j = 0; j < rows; j++) {
			float screenX = i * cellWidth;
			float screenY = j * cellHeight;
			if(screenX > ofGetWidth()) continue;
			if(screenY > ofGetHeight()) continue;
			if(worldCopy.isAlive(i, j)) ofDrawRectangle(i*cellWidth, j*cellHeight, cellWidth, cellHeight);
		}
	}
}

void GolScene::update(float dt) {
	if(active) world.step();
}

void GolScene::activate() {

}

void GolScene::deactivate() {

}

void GolScene::keyPress(int key) {
	if(key == 'r') world.randomizeState();
	if(key == 'n') randomizeRules();
	if(key == 'c') world.clear();
	//if(key == 'b') insertShape(bomb, rand() % rowCount, rand() % colCount);
	//if(key == 'a') gol = getNextStates();
	if(key == 'p') active = !active;
	if(key == OF_KEY_UP) {
		colCount++; // TODO testing
		rowCount++;
		world.resize(colCount, rowCount);
	}
	if(key == OF_KEY_DOWN) {
		colCount--;
		rowCount--;
		world.resize(colCount, rowCount);
	}
}

void GolScene::insertShape(std::vector<std::vector<bool>> shape, int x, int y) {
	//for(int i = 0; i < shape.size(); i++) {
	//	for(int j = 0; j < shape[0].size(); j++) {
	//		gol[x+i][y+j] = shape[i][j];
	//	}
	//}
}

void GolScene::randomizeRules() {
	world.setRules(GoodRuleSets::getRandomRuleSet());
}
