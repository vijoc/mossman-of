#include "golScene.hpp"
#include "goodRuleSets.hpp"

void GolScene::draw() {
	float cellWidth = (float) ofGetWidth() / (float) colCount;
	float cellHeight= (float) ofGetHeight() / (float) rowCount;
	for(int i = 0; i < colCount; i++) {
		for(int j = 0; j < rowCount; j++) {
			if(gol[i][j]) ofDrawRectangle(i*cellWidth, j*cellHeight, cellWidth, cellHeight);
		}
	}
}

void GolScene::update(float dt) {
	if(active) gol = getNextStates();
}

void GolScene::activate() {

}

void GolScene::deactivate() {

}

void GolScene::keyPress(int key) {
	if(key == 'r') randomizeState();
	if(key == 'n') randomizeRules();
	if(key == 'c') clearScreen();
	if(key == 'b') insertShape(bomb, rand() % rowCount, rand() % colCount);
	if(key == 'a') gol = getNextStates();
	if(key == 'p') active = !active;
	if(key == OF_KEY_UP) {
		colCount++; // TODO testing
		rowCount++;
		gol.resize(colCount);
		for(int i = 0; i < colCount; i++) {
			gol[i].resize(rowCount);
		}
	}
	if(key == OF_KEY_DOWN) {
		colCount--;
		rowCount--;
		gol.resize(colCount);
		for(int i = 0; i < colCount; i++) {
			gol[i].resize(rowCount);
		}
	}
}

std::vector<std::vector<bool>> GolScene::getNextStates() {
	std::vector<std::vector<bool>> buffer;
	buffer.resize(colCount);
	for(int i = 0; i < colCount; i++) {
		buffer[i].resize(rowCount);
	}
	for(int i = 0; i < colCount; i++) {
		for(int j = 0; j < rowCount; j++) {
			bool nextState = calculateNextState(i, j);
			buffer[i][j] = nextState;
		}
	}
	return buffer;
}

bool GolScene::calculateNextState(int x, int y) {
	int neighbourCount = countAliveNeighbours(x, y);
	if(gol[x][y])	return ruleSet.survivalRulesContain(neighbourCount);
	else		return ruleSet.birthRulesContain(neighbourCount);
}

void GolScene::randomizeState() {
	for(int i = 0; i < colCount; i++) {
		for(int j = 0; j < rowCount; j++) {
			if(rand() % 2 == 0) gol[i][j] = true;
			else gol[i][j] = false;
		}
	}
}

void GolScene::clearScreen() {
	for(int i = 0; i < colCount; i++) {
		for(int j = 0; j < rowCount; j++) {
			gol[i][j] = false;
		}
	}
}

void GolScene::insertShape(std::vector<std::vector<bool>> shape, int x, int y) {
	for(int i = 0; i < shape.size(); i++) {
		for(int j = 0; j < shape[0].size(); j++) {
			gol[x+i][y+j] = shape[i][j];
		}
	}
}

void GolScene::randomizeRules() {
	ruleSet = GoodRuleSets::getRandomRuleSet();
}

int GolScene::countAliveNeighbours(int x, int y) {
	int sum = 0;
	int col, row;
	for(int i = -1; i <= 1; i++) {
		col = wrapColumn(x + i);
		for(int j = -1; j <= 1; j++) {
			if(i == 0 && j == 0) continue; // skip self
			row = wrapRow(y + j);
			if(gol[col][row]) sum++;
		}
	}
	return sum;
}
