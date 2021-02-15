#include "window.h"
#include <iostream>

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

	

	if (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			_closed = true;
			break;

		case SDL_MOUSEBUTTONDOWN:
			std::cout << event.button.x << " " << event.button.y << std::endl ;
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
	rect.x = xPos + 100;
	rect.y = yPos + 100;
	if (alive) {
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	}
	else
		SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(_renderer, &rect);
}

void Window::PresentRenderer() {
	SDL_RenderPresent(_renderer);

}

