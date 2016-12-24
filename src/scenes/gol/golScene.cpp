#include "golScene.hpp"
#include "goodRuleSets.hpp"

void GolScene::draw() {
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 32; j++) {
			if(gol[i][j]) ofDrawRectangle(i*15, j*15, 10, 10);
		}
	}
}

void GolScene::update(float dt) {

}

void GolScene::activate() {

}

void GolScene::deactivate() {

}

void GolScene::keyPress(int key) {
	if(key == 'r') randomizeState();
	if(key == 'n') randomizeRules();
	else gol = getNextStates();
}

std::vector<std::vector<bool>> GolScene::getNextStates() {
	std::vector<std::vector<bool>> buffer;
	buffer.resize(32);
	for(int i = 0; i < 32; i++) {
		buffer[i].resize(32);
	}
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 32; j++) {
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
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 32; j++) {
			if(rand() % 2 == 0) gol[i][j] = true;
			else gol[i][j] = false;
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
			if(col == 0 && row == 0) continue; // skip self
			row = wrapRow(y + j);
			if(gol[col][row]) sum++;
		}
	}
	return sum;
}
