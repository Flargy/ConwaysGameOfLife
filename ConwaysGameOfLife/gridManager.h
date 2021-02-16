#pragma once
#include <vector>
#include "window.h"
class Cell;

class GridManager {
public:
	GridManager(int cellWidth, int cellHeight, Window* window, int dynamic);
	~GridManager();
	void CreateGrid();
	void CheckStatus();
	void UpdateStatus();
	void CreateConnections();
	void DrawCells();
	void ClickCell(std::vector<int> vec);

	void DebugGrid();
	void FunctionTest(void (*f)());

private:
	int _cellWidth = 5;
	int _cellHeight = 5;
	Window* _window;

	static const int _gridSize = 30;
	Cell* _cellGrid[_gridSize][_gridSize];

	int dynamicValue = 30;
	Cell** testGrid;
};