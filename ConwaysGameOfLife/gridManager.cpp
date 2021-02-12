#include "gridManager.h"
#include <iostream>
#include "cell.h"

GridManager::GridManager(int cellWidth, int cellHeight) :
	_cellWidth(cellWidth), _cellHeight(cellHeight)
{
	CreateGrid();
}

GridManager::~GridManager() {
		for (int i = 0; i < 20; i++) {
		delete[] _cellGrid[i];
	}

	delete[] _cellGrid;
}

void GridManager::CreateGrid() {
	for (int rows = 0; rows < 20; rows++) {
		for (int columns = 0; columns < 20; columns++) {
			_cellGrid[rows][columns] = new Cell(_cellWidth * rows, _cellHeight * columns);
		}
	}
}

void GridManager::CreateConnections() {
	// Create each connetion here
	// Gather a vector of adjacent cells and send it to the current cell in the iteration
	// Needed cells are in x:y
	// x-1:y-1
	// x-1:y
	// x-1:y+1
	// x-1:y
	// x+1:y
	// x-1:y+1
	// x:y+1
	// x+1:y+1
	
}

void GridManager::CheckStatus() {
	// call CheckNeighborLife() on every cell here
}

void GridManager::UpdateStatus() {
	// call NextLifecycle on every cell here
}

void GridManager::DebugGrid() {
	for (int rows = 0; rows < 20; rows++) {
		for (int columns = 0; columns < 20; columns++) {
			std::cout << (*_cellGrid[rows][columns]).GetPosition() << std::endl;
			std::cout << (*_cellGrid[rows][columns]).GetPosition2() << std::endl;
		}

	}
}