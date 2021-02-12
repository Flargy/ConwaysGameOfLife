#pragma once
#include <vector>

class Cell;

class GridManager {
public:
	GridManager(int cellWidth, int cellHeight);
	~GridManager();
	void CreateGrid();
	void CheckStatus();
	void UpdateStatus();
	void CreateConnections();

	void DebugGrid();

private:
	int _cellWidth = 5;
	int _cellHeight = 5;
	Cell* _cellGrid[20][20];
};