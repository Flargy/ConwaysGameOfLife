#include "gridManager.h"
#include <iostream>
#include "cell.h"

/*
GridManager::GridManager(int cellWidth, int cellHeight, Window* window, int dynamic) :
	_cellWidth(cellWidth), _cellHeight(cellHeight), _window(window), dynamicValue(dynamic)
{

	CreateGrid();
}

GridManager::~GridManager() {
	
	for (int rows = 0; rows < _gridSize; rows++) {
		for (int columns = 0; columns < _gridSize; columns++) {
			delete _cellGrid[rows][columns];
		}
	}

}

void GridManager::CreateGrid() {
	for (int rows = 0; rows < _gridSize; rows++) {
		for (int columns = 0; columns < _gridSize; columns++) {
			_cellGrid[rows][columns] = new Cell(_cellWidth * rows, _cellHeight * columns, _cellWidth, _cellHeight);

		}
	}

}

void GridManager::CreateConnections() {

	struct {
		int dx;
		int dy;
	} directions[] = { {-1,-1,},{-1,0,},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

	int x = 0;
	int y = 0;
	std::vector<Cell*> adjacentCells;


	for (int row = 0; row < _gridSize; row++) {
		for (int column = 0; column < _gridSize; column++) {
			for (int i = 0; i < 8; i++)
			{
				x = directions[i].dx;
				y = directions[i].dy;
				if (row + x < 0) {
					x = _gridSize -1;
				}
				else if (row + x > _gridSize - 1) {
					x = -_gridSize+ 1;
				}
				if (column + y < 0) {
					y = _gridSize -1;
				}
				else if (column + y > _gridSize - 1) {
					y = -_gridSize + 1;
				}

				adjacentCells.push_back((_cellGrid[row + x][column + y]));

			}

			(_cellGrid[row][column])->SetNeighbors(adjacentCells);

			adjacentCells.clear();
			
		}
	}
	
}

void GridManager::CheckStatus() {
	for (int rows = 0; rows < _gridSize; rows++) {
		for (int columns = 0; columns < _gridSize; columns++) {
			(*_cellGrid[rows][columns]).CheckNeighborsLife();
		}
	}
}

void GridManager::UpdateStatus() {
	for (int rows = 0; rows < _gridSize; rows++) {
		for (int columns = 0; columns < _gridSize; columns++) {
			(*_cellGrid[rows][columns]).NextLifecycle();
		}
	}

}

void GridManager::FunctionTest(void (*f)()) {
	for (int rows = 0; rows < _gridSize; rows++) {
		for (int columns = 0; columns < _gridSize; columns++) {
		}
	}
}


void GridManager::DebugGrid() {
	for (int rows = 0; rows < _gridSize; rows++) {
		for (int columns = 0; columns < _gridSize; columns++) {
			std::cout << (*_cellGrid[rows][columns]).GetPositionX() << std::endl;
			std::cout << (*_cellGrid[rows][columns]).GetPositionY() << std::endl;
		}

	}
}

void GridManager::DrawCells() {
	Cell* currentCell;
	for (int rows = 0; rows < _gridSize; rows++) {
		for (int columns = 0; columns < _gridSize; columns++) {
			currentCell = _cellGrid[rows][columns];

			_window->DrawRect(_cellHeight, _cellWidth, currentCell->GetPositionX(), currentCell->GetPositionY(), currentCell->ReturnLife());
		}
	}
}

void GridManager::ClickCell(std::vector<int> vec) {
	Cell* currentCell = _cellGrid[vec[0]][vec[1]];
	currentCell->Clicked();
	_window->DrawRect(_cellHeight, _cellWidth, currentCell->GetPositionX(), currentCell->GetPositionY(), currentCell->ReturnLife());
}
*/







GridManager::GridManager(int cellWidth, int cellHeight, Window* window, int dynamic) :
	_cellWidth(cellWidth), _cellHeight(cellHeight), _window(window), dynamicValue(dynamic)
{
	testGrid = new Cell*[dynamicValue];
	CreateGrid();
}

GridManager::~GridManager() {

	for (int i = 0; i < dynamicValue; i++)
	{
		delete[] testGrid[i];
	}

	delete[] testGrid;

}

void GridManager::CreateGrid() {
	for (int i = 0; i < dynamicValue; i++)
	{
		testGrid[i] = new Cell[dynamicValue];
	}

	for (int row = 0; row < dynamicValue; row++)
	{
		for (int column = 0; column < dynamicValue; column++)
		{
			testGrid[row][column].SetValues(_cellWidth * row, _cellHeight * column, _cellWidth, _cellHeight);
		}
	}

}

void GridManager::CreateConnections() {


	struct {
		int dx;
		int dy;
	} directions[] = { {-1,-1,},{-1,0,},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

	int x = 0;
	int y = 0;
	std::vector<Cell*> adjacentCells;


	for (int row = 0; row < dynamicValue; row++) {
		for (int column = 0; column < dynamicValue; column++) {
			for (int i = 0; i < 8; i++)
			{
				x = directions[i].dx;
				y = directions[i].dy;
				if (row + x < 0) {
					x = dynamicValue - 1;
				}
				else if (row + x > dynamicValue - 1) {
					x = -dynamicValue + 1;
				}
				if (column + y < 0) {
					y = dynamicValue - 1;
				}
				else if (column + y > dynamicValue - 1) {
					y = -dynamicValue + 1;
				}

				adjacentCells.push_back(&(testGrid[row + x][column + y]));
			}

			(testGrid[row][column]).SetNeighbors(adjacentCells);

			adjacentCells.clear();
		}
	}

}

void GridManager::CheckStatus() {
	for (int rows = 0; rows < dynamicValue; rows++) {
		for (int columns = 0; columns < dynamicValue; columns++) {
			(testGrid[rows][columns]).CheckNeighborsLife();
		}
	}
}

void GridManager::UpdateStatus() {
	for (int rows = 0; rows < dynamicValue; rows++) {
		for (int columns = 0; columns < dynamicValue; columns++) {
			(testGrid[rows][columns]).NextLifecycle();
		}
	}

}

void GridManager::FunctionTest(void (*f)()) {
	for (int rows = 0; rows < dynamicValue; rows++) {
		for (int columns = 0; columns < dynamicValue; columns++) {
		}
	}
}


void GridManager::DebugGrid() {
	for (int rows = 0; rows < dynamicValue; rows++) {
		for (int columns = 0; columns < dynamicValue; columns++) {
			std::cout << (*_cellGrid[rows][columns]).GetPositionX() << std::endl;
			std::cout << (*_cellGrid[rows][columns]).GetPositionY() << std::endl;
		}

	}
}

void GridManager::DrawCells() {
	Cell* currentCell;
	for (int rows = 0; rows < dynamicValue; rows++) {
		for (int columns = 0; columns < dynamicValue; columns++) {
			currentCell = &testGrid[rows][columns];

			_window->DrawRect(_cellHeight, _cellWidth, currentCell->GetPositionX(), currentCell->GetPositionY(), currentCell->ReturnLife());
		}
	}
}

void GridManager::ClickCell(std::vector<int> vec) {
	Cell* currentCell = &testGrid[vec[0]][vec[1]];
	currentCell->Clicked();
	_window->DrawRect(_cellHeight, _cellWidth, currentCell->GetPositionX(), currentCell->GetPositionY(), currentCell->ReturnLife());
}
