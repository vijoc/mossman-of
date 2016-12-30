#include "golWorld.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>

// TODO organize/reorder

// TODO move this somewhere else?
namespace mossman {
	int wrapAround(int i, int max) {
		if( i >= 0 && i < max ) return i;
		if( i < 0 ) return max + i;
		return i - max;
	}
}

GolWorld::GolWorld(int columns, int rows) 
		: nCols(columns), nRows(rows) {
	randomizeState();
}

void GolWorld::step() {
	auto buffer = buildCellContainer();
	for(int x = 0; x < colCount(); x++) {
		for(int y = 0; y < rowCount(); y++) {
			if(x >= nCols || y >= nRows) continue;
			int neighbourCount = countAliveNeighbours(x,y);
			buffer[x][y] = (isAlive(x, y) ? ruleSet.survivalRulesContain(neighbourCount)
						  : ruleSet.birthRulesContain(neighbourCount));
		}
	}
	this->cells = buffer;
}

int GolWorld::countAliveNeighbours(int x, int y) const {
	int sum = 0;
	int col, row;
	for(int i = -1; i <= 1; i++) {
		for(int j = -1; j <= 1; j++) {
			if(i == 0 && j == 0) continue; // skip self
			col = wrapColumn(x + i);
			row = wrapRow(y + j);
			if(isAlive(col, row)) sum++;
		}
	}
	return sum;
}

CellContainer GolWorld::buildCellContainer() const {
	auto container = std::vector<std::vector<bool>>(nCols);
	for(int i = 0; i < nCols; i++) {
		container[i].resize(nRows);
	}
	return container;
}

void GolWorld::randomizeState() {
	this->cells = buildRandomizedCellContainer();
}

CellContainer GolWorld::buildRandomizedCellContainer() const {
	auto buffer = buildCellContainer();
	for(int x = 0; x < nCols; x++) {
		for(int y = 0; y < nRows; y++) {
			buffer[x][y] = (rand() % 2 == 0) ? true : false;
		}
	}
	return buffer;
}

void GolWorld::setRules(RuleSet rules) {
	this->ruleSet = rules;
}

void GolWorld::clear() {
	this->cells = buildCellContainer();
}

void GolWorld::insertShape(const CellContainer& shape, int x, int y) {
	for(size_t i = 0; i < shape.size(); i++) {
		for(size_t j = 0; j < shape[0].size(); j++) {
			cells[x+i][y+j] = shape[i][j];
		}
	}
}
