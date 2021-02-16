#include "cell.h"
#include <iostream>

Cell::Cell(int xPos, int yPos, int width, int height) :
	_xPosition(xPos), _yPosition(yPos), _width(width), _height(height)
{

}

Cell::~Cell() {

}

int Cell::ReturnLife() {
	return _isAlive;
}

void Cell::SetNeighbors(std::vector<Cell*> newNeighbors) {
	for (int i = 0; i < newNeighbors.size(); i++) {
		_neighbors.push_back(newNeighbors[i]);
	}
}
void Cell::CheckNeighborsLife() {
	int accumulator = 0;
	for (int i = 0; i < _neighbors.size(); i++) {
		accumulator += _neighbors[i]->ReturnLife();
	}


	if (!_isAlive && accumulator == 3) { //Can probably improve the efficiency of this
		_aliveNextIteration = true;
		return;
	}

	if (_isAlive && (accumulator == 2 || accumulator == 3)) {
		_aliveNextIteration = true;
		return;
	}

	_aliveNextIteration = false;
	
}

void Cell::NextLifecycle() {
	_isAlive = _aliveNextIteration;
}

int Cell::GetPositionX() {
	return _xPosition;
}

int Cell::GetPositionY() {
	return _yPosition;
}

void Cell::SetState(bool state) {
	_isAlive = state;
}

//void Cell::DebugNeighbors() {
//	for (int i = 0; i < _neighbors.size(); i++) {
//		std::cout <<"X:" << _neighbors[i]->GetPositionX() << " Y:" << _neighbors[i]->GetPositionY() << std::endl;
//		_neighbors[i]->SetState(true);
//	}
//}

void Cell::Clicked() {
	_isAlive = !_isAlive;
}

void Cell::SetValues(int xPos, int yPos, int width, int height) {
	_xPosition = xPos;
	_yPosition = yPos;
	_width = width;
	_height = height;
}