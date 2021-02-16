#pragma once
#include <vector>

class Cell {
public:
	Cell(int xPos, int yPos, int width, int height);
	Cell() {};
	~Cell();

	int ReturnLife();
	void SetNeighbors(std::vector<Cell*>);
	void CheckNeighborsLife();
	void NextLifecycle();
	int GetPositionX();
	int GetPositionY();
	void SetState(bool state);
	void DebugNeighbors();
	void Clicked();
	void SetValues(int xPos, int yPos, int width, int height);

private:
	int _xPosition;
	int _yPosition;
	bool _isAlive = false;
	bool _aliveNextIteration = false;
	int _width;
	int _height;
	//std::array<Cell*, 8> _neighbors = {nullptr};

	std::vector<Cell*> _neighbors;
};