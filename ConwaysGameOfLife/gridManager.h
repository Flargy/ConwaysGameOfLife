#pragma once
#include <vector>
#include "window.h"
class Cell;

class GridManager {
public:
	GridManager(int cellWidth, int cellHeight, Window* window);
	~GridManager();
	void CreateGrid();
	void CheckStatus();
	void UpdateStatus();
	void CreateConnections();
	void DrawCells();

	void DebugGrid();
	void FunctionTest(void (*f)());

private:
	int _cellWidth = 5;
	int _cellHeight = 5;
	Cell* _cellGrid[30][30];
	Window* _window;
};