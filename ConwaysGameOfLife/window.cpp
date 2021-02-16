#include <iostream>
#include "global.h"


Window::Window(const std::string& title, int width, int height) :
	_title(title), _width(width), _height(height) 
{

	_closed = !Init();
}

Window::~Window() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Window::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);

	if (_window == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (_renderer == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	return true;

}

void Window::SetBackground() {

	SDL_SetRenderDrawColor(_renderer, 0, 0, 200, 255);
	SDL_RenderClear(_renderer);

	
}


bool Window::PollEvents() {
	SDL_Event event;

	std::vector<int> positions;

	if (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			_closed = true;
			break;

		case SDL_MOUSEBUTTONDOWN:
			positions.push_back(event.button.x/25);
			positions.push_back(event.button.y / 25);
			SelectCell(positions);
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				_closed = true;
				break;

			case SDLK_SPACE:
				return true;
				break;
			
				
			default:
				break;
			}

		default:
			break;
		}
	}
	

	return false;
}

void Window::DrawRect(int height, int width, int xPos, int yPos, bool alive) {

	SDL_Rect rect;
	rect.w = width - 0.1;
	rect.h = height - 0.1;
	rect.x = xPos ;
	rect.y = yPos ;
	if (alive) {
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	}
	else
		SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(_renderer, &rect);
}

void Window::SelectCell(std::vector<int> positions) {
	manager.ClickCell(positions);
}

void Window::PresentRenderer() {
	SDL_RenderPresent(_renderer);

}

