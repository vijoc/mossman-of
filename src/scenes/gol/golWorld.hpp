#ifndef GOLWORLD_H
#define GOLWORLD_H

#include <cassert>
#include <cstddef>
#include <vector>

#include "ruleSet.hpp"

using CellContainer = std::vector<std::vector<bool>>;

// TODO place this somewhere else?
namespace mossman {
	int wrapAround(int i, int max);
}

using namespace mossman;

class GolWorld {
public:
	GolWorld(int columns, int rows);
	void step();
	void resize(size_t columns, size_t rows) { nCols = columns; nRows = rows; }
	void randomizeState();
	void setRules(RuleSet ruleSet);
	void clear();

	inline bool isAlive(int x, int y) const {
		assert(x >= 0 && x < nCols);
		assert(y >= 0 && y < nRows);
		return cells[x][y];
	}

	int colCount() const { return cells.size(); }
	int rowCount() const { return cells[0].size(); }

private:
	int countAliveNeighbours(int x, int y) const;
	CellContainer buildCellContainer() const;
	CellContainer buildRandomizedCellContainer() const;
	inline size_t wrapColumn(int x) const {
		return wrapAround(x, nCols);
	}

	inline size_t wrapRow(int y) const {
		return wrapAround(y, nRows);
	}

	int nCols; // number of columns
	int nRows; // number of rows

	RuleSet ruleSet; 	// currently applied ruleset
	CellContainer cells;	// current state
};

#endif /* GOLWORLD_H */