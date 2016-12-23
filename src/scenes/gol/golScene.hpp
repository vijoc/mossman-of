#ifndef GOLSCENE_H
#define GOLSCENE_H

#include "ofMain.h"
#include "scene.hpp"
#include "ruleSet.hpp"

class GolScene : public Scene {
public:
	GolScene(): ruleSet() {
		gol.resize(32);
		for(int i = 0; i < 32; i++) {
			gol[i].resize(32);
		}
		for(int i = 0; i < 32; i++) {
			for(int j = 0; j < 32; j++) {
				if(i == j) gol[i][j] = true;
				else if(i == 2*j) gol[i][j] = true;
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
	bool calculateNextState(int i, int j);
	int countAliveNeighbours(int x, int y);
	int wrapColumn(int x) { return wrapAround(x, 32); }
	int wrapRow(int y) { return wrapAround(y, 32); }
	int wrapAround(int i, int max) { if(i >= 0 && i < max) return i; else if(i < 0) return max + i; else return i - max; }
};

#endif /* GOLSCENE_H */
