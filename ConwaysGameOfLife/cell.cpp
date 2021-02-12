#include "cell.h"

Cell::Cell(int xPos, int yPos) :
	_xPosition(xPos), _yPosition(yPos)
{

}

Cell::~Cell() {

}

int Cell::ReturnLife() {
	if (_isAlive) {
		return 1;
	}
	return 0;
}

void Cell::SetNeighbors(std::vector<Cell> newNeighbors) {


	for (int i = 0; i < newNeighbors.size(); i++) {
		_neighbors.push_back(newNeighbors[i]);
	}
}
void Cell::CheckNeighborsLife() {
	int accumulator = 0;
	for (int i = 0; i < _neighbors.size(); i++) {
		accumulator += (_neighbors[i]).ReturnLife();
	}

	if (!_isAlive && accumulator == 3) { //Can probably improve the efficiency of this
		_aliveNextIteration = true;
		return;
	}

	if (_isAlive && accumulator == 2 || accumulator == 3)
		return;

	_aliveNextIteration = false;
	
}

void Cell::NextLifecycle() {
	_isAlive = _aliveNextIteration;
}

int Cell::GetPosition() {
	return _xPosition;
}

int Cell::GetPosition2() {
	return _yPosition;
}
