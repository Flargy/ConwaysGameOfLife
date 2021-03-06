#pragma once
#include <string>
#include <SDL.h>
#include <iostream>
#include <vector>

class Window {
public:
	Window(const std::string& title, int width, int height);
	~Window();

	inline bool IsClosed() const { return _closed; }
	void SetBackground();
	bool PollEvents();
	void DrawRect(int height, int width, int xPos, int yPos, bool alive);
	void PresentRenderer();
	void SelectCell(std::vector<int> vec);

private:
	bool Init();
	std::string _title;
	int _width = 800;
	int _height = 600;
	bool _closed = false;
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;
};