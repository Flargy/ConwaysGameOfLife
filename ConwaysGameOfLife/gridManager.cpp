#include "gridManager.h"
#include <iostream>
#include "cell.h"

GridManager::GridManager(int cellWidth, int cellHeight, Window* window) :
	_cellWidth(cellWidth), _cellHeight(cellHeight), _window(window)
{
	CreateGrid();
}

GridManager::~GridManager() {
	/*	for (int i = 0; i < 20; i++) {
		delete[] _cellGrid[i];
	}

	delete[] _cellGrid;*/

	for (int rows = 0; rows < 30; rows++) {
		for (int columns = 0; columns < 30; columns++) {
			delete _cellGrid[rows][columns];
		}
	}
}

void GridManager::CreateGrid() {
	for (int rows = 0; rows < 30; rows++) {
		for (int columns = 0; columns < 30; columns++) {
			_cellGrid[rows][columns] = new Cell(_cellWidth * rows, _cellHeight * columns);

			//glider

			if (rows == 5 && columns == 5 ) { 
				_cellGrid[rows][columns]->SetState(true);
			}
			else if (rows == 6 && columns == 5) {
				_cellGrid[rows][columns]->SetState(true);
			}
			else if (rows == 7 && columns == 5) {
				_cellGrid[rows][columns]->SetState(true);
			}
			else if (rows == 7 && columns == 4) {
				_cellGrid[rows][columns]->SetState(true);
			}
			else if (rows == 6 && columns == 3) {
				_cellGrid[rows][columns]->SetState(true);
			}

			//rotator

			/*if (rows == 0 && columns == 0) { 
				_cellGrid[rows][columns]->SetState(true);
			}
			else if (rows == 0 && columns == 1) {
				_cellGrid[rows][columns]->SetState(true);
			}

			else if (rows == 0 && columns == 19) {
				_cellGrid[rows][columns]->SetState(true);
			}*/
		}
	}

	//CreateConnections();
}

void GridManager::CreateConnections() {


	struct {
		int dx;
		int dy;
	} directions[] = { {-1,-1,},{-1,0,},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

	int x = 0;
	int y = 0;
	std::vector<Cell*> adjacentCells;


	for (int row = 0; row < 30; row++) {
		for (int column = 0; column < 30; column++) {
			for (int i = 0; i < 8; i++)
			{
				x = directions[i].dx;
				y = directions[i].dy;
				if (row + x < 0) {
					x = 29;
				}
				else if (row + x > 29) {
					x = -29;
				}
				if (column + y < 0) {
					y = 29;
				}
				else if (column + y > 29) {
					y = -29;
				}

				adjacentCells.push_back((_cellGrid[row + x][column + y]));

				//std::cout << "X: " << rows + x << " Y: " << columns + y << std::endl;

				//std::cout <<"X pos: " << (_cellGrid[rows + x][columns + y])->GetPosition() << " Y pos: " << (_cellGrid[rows + x][columns + y])->GetPosition2() << std::endl;

			}

			(_cellGrid[row][column])->SetNeighbors(adjacentCells);

			adjacentCells.clear();
			
		}
	}
	
}

void GridManager::CheckStatus() {
	for (int rows = 0; rows < 30; rows++) {
		for (int columns = 0; columns < 30; columns++) {
			(*_cellGrid[rows][columns]).CheckNeighborsLife();
		}
	}
}

void GridManager::UpdateStatus() {
	// call NextLifecycle on every cell here
	for (int rows = 0; rows < 30; rows++) {
		for (int columns = 0; columns < 30; columns++) {
			(*_cellGrid[rows][columns]).NextLifecycle();
		}
	}

	//FunctionTest(&Cell::NextLifecycle);
}

void GridManager::FunctionTest(void (*f)()) {
	for (int rows = 0; rows < 30; rows++) {
		for (int columns = 0; columns < 30; columns++) {
			//(*_cellGrid[rows][columns]).(*f)();
		}
	}
}


void GridManager::DebugGrid() {
	for (int rows = 0; rows < 30; rows++) {
		for (int columns = 0; columns < 30; columns++) {
			std::cout << (*_cellGrid[rows][columns]).GetPositionX() << std::endl;
			std::cout << (*_cellGrid[rows][columns]).GetPositionY() << std::endl;
		}

	}
}

void GridManager::DrawCells() {
	Cell* currentCell;
	for (int rows = 0; rows < 30; rows++) {
		for (int columns = 0; columns < 30; columns++) {
			currentCell = _cellGrid[rows][columns];

			_window->DrawRect(_cellHeight, _cellWidth, currentCell->GetPositionX(), currentCell->GetPositionY(), currentCell->ReturnLife());
		}
	}
}