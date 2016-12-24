#ifndef GOLSCENE_H
#define GOLSCENE_H

#include "ofMain.h"
#include "scene.hpp"
#include "ruleSet.hpp"

class GolScene : public Scene {
public:
	int rowCount = 64;
	int colCount = 32;
	GolScene(): ruleSet() {
		gol.resize(rowCount);
		for(int i = 0; i < rowCount; i++) {
			gol[i].resize(colCount);
		}
		for(int i = 0; i < rowCount; i++) {
			for(int j = 0; j < colCount; j++) {
				if(rand() % 2 == 0) gol[i][j] = true;
				else gol[i][j] = false;
			}
		}
		return;
	}
	void draw();
	void update(float dt);
	void activate();
	void deactivate();
	void keyPress(int key);
private:
	RuleSet ruleSet;
	std::vector<std::vector<bool>> gol;
	std::vector<std::vector<bool>> getNextStates();
	bool calculateNextState(int x, int y);
	void randomizeState();
	void randomizeRules();
	int countAliveNeighbours(int x, int y);
	int wrapColumn(int x) { return wrapAround(x, rowCount); }
	int wrapRow(int y) { return wrapAround(y, colCount); }
	int wrapAround(int i, int max) { if(i >= 0 && i < max) return i; else if(i < 0) return max + i; else return i - max; }
};

#endif /* GOLSCENE_H */
