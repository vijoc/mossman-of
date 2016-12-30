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
	void resize(size_t columns, size_t rows) {
		nCols = columns; 
		nRows = rows; 
	}
	void randomizeState();
	void setRules(RuleSet ruleSet);
	void clear();
	void insertShape(const CellContainer& shape, int x, int y);

	inline bool isAlive(int x, int y) const {
		if( x >= 0 && x < colCount() && y >= 0 && y < rowCount())
			return cells[x][y];
		else
			return false;
	}

	int colCount() const { return cells.size(); }
	int rowCount() const { return cells[0].size(); }

private:
	int countAliveNeighbours(int x, int y) const;
	CellContainer buildCellContainer() const;
	CellContainer buildRandomizedCellContainer() const;

	inline size_t wrapColumn(int x) const {
		return wrapAround(x, colCount());
	}

	inline size_t wrapRow(int y) const {
		return wrapAround(y, rowCount());
	}

	int nCols; // number of columns AFTER NEXT step()
	int nRows; // number of rows AFTER NEXT step()

	RuleSet ruleSet; 	// currently applied ruleset
	CellContainer cells;	// current state
};

#endif /* GOLWORLD_H */
